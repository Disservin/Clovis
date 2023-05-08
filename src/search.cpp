#include <chrono>
#include <iomanip>
#include <climits>
#include <algorithm>

#include "search.h"
#include "evaluate.h"

using namespace std;

namespace clovis {

	namespace search {

		constexpr double log_table[] = {
			0.000000,
			0.000000, 0.693147, 1.098612, 1.386294,
			1.609438, 1.791759, 1.945910, 2.079442,
			2.197225, 2.302585, 2.397895, 2.484907,
			2.564949, 2.639057, 2.708050, 2.772589,
			2.833213, 2.890372, 2.944439, 2.995732,
			3.044522, 3.091042, 3.135494, 3.178054,
			3.218876, 3.258097, 3.295837, 3.332205,
			3.367296, 3.401197, 3.433987, 3.465736,
			3.496508, 3.526361, 3.555348, 3.583519,
			3.610918, 3.637586, 3.663562, 3.688879,
			3.713572, 3.737670, 3.761200, 3.784190,
			3.806662, 3.828641, 3.850148, 3.871201,
			3.891820, 3.912023, 3.931826, 3.951244,
			3.970292, 3.988984, 4.007333, 4.025352,
			4.043051, 4.060443, 4.077537, 4.094345,
			4.110874, 4.127134, 4.143135, 4.158883
		};

		constexpr int lmr_depth = 2;
		constexpr int lmr_history_min = 2;
		constexpr int lmr_history_max = 2;
		constexpr int lmr_history_divisor = 4000;
		constexpr int lmr_reduction = 2;

		constexpr auto lmr_table = [] {
			array<array<int, 64>, MAX_PLY + 1> arr{};

			for (int depth = 1; depth <= MAX_PLY; ++depth)
				for (int ordered = 1; ordered < 64; ++ordered)
					arr[depth][ordered] = static_cast<int>(0.75 + log_table[depth] * log_table[ordered] / 2.25);

			return arr;
		}();

		constexpr int iid_depth[2] = { 5, 7 };
		constexpr int iid_reduction[2] = { 5, 4 };
		constexpr int iid_factor[2] = { 1, 4 };
		constexpr int iid_divisor[2] = { 2, 4 };

		constexpr auto iid_table = [] {
			array<array<int, MAX_PLY + 1>, 2> arr{};

			for (int depth = 1; depth <= MAX_PLY; ++depth)
				for (int i = 0; i < 2; ++i)
					arr[i][depth] = (iid_factor[i] * depth - iid_reduction[i]) / (iid_divisor[i] + 1);

			return arr;
		}();
	
		constexpr int futility_factor = 75;
		constexpr int futility_depth = 8;
        
		constexpr int null_depth = 3;
		constexpr int null_reduction = 3;
        
		constexpr int asp_depth = 3;
		constexpr int16_t delta = 45;

		bool stop = false;

		chrono::steady_clock::time_point start_time;
		Duration allocated_time;

		// reset transposition table, set search to standard conditions
		void clear() {
			move_pick::clear();
			tt.clear();
		}
 
		template<NodeType N>
		int16_t quiescence(Position& pos, int16_t alpha, int16_t beta, uint64_t& nodes, const uint8_t ply, Line& pline) {

			constexpr bool PV_NODE = N != NODE_NON_PV;

			assert(PV_NODE || (alpha == beta - 1));

			++nodes;

			if (pos.is_draw())
				return DRAW_SCORE;
			if (ply >= MAX_PLY)
				return eval::evaluate<false>(pos);

			const TTEntry tte = tt.probe(pos.bs->key);

			if (!PV_NODE && tte.key == pos.bs->key 
			&& (tte.flags == HASH_EXACT 
			|| (tte.flags == HASH_BETA  && tte.eval >= beta)
			|| (tte.flags == HASH_ALPHA && tte.eval <= alpha)))
				return tte.eval;

			const bool in_check = pos.is_king_in_check();
			const int16_t old_alpha = alpha;
			int16_t eval;

			if (!in_check) {

				eval = eval::evaluate<false>(pos);
	
				// use TT score instead of static eval if conditions are right
				// conditions: valid TTE and either 
				// 1. alpha flag + lower hash score than static eval
				// 2. beta flag + higher hash score than static eval
				if (tte.key == pos.bs->key && ((tte.flags == HASH_ALPHA) == (tte.eval < eval)))
					eval = tte.eval;
				if (eval >= beta)
					return beta;
				if (eval > alpha)
					alpha = eval;
			}

			move_pick::MovePicker mp(pos, 0, MOVE_NONE, (tte.key == pos.bs->key) ? tte.move : MOVE_NONE);
			Move best_move = MOVE_NONE;
			int16_t best_eval = INT16_MIN;

			while (const Move curr_move = mp.get_next(in_check)) {
				// illegal move or non capture
				if (!pos.do_move(curr_move)) continue;

				Line line;
				eval = -quiescence<N>(pos, -beta, -alpha, nodes, ply + 1, line);

				pos.undo_move(curr_move);

				// fail high
 				if (eval >= beta) {
					tt.new_entry(pos.bs->key, 0, beta, HASH_BETA, curr_move);
					return beta;
				}
				if (eval > best_eval) {
					best_eval = eval;
					best_move = curr_move;
					// new best move found
					if (eval > alpha) {
						if constexpr (PV_NODE) {
							pline.last = pline.moves.data();
							*pline.last++ = curr_move;
							for (const auto& m : line)
								*pline.last++ = m;
						}
						alpha = eval;
					}
				}
			}

			if (in_check && best_eval == INT16_MIN)
				return ply - CHECKMATE_SCORE;

			tt.new_entry(pos.bs->key, 0, alpha, alpha > old_alpha ? HASH_EXACT : HASH_ALPHA, best_move);

			return alpha;
		}

		template<NodeType N>
		int16_t negamax(Position& pos, int16_t alpha, int16_t beta, uint8_t depth, const uint8_t ply, const bool is_null, const Move prev_move, uint64_t& nodes, Line& pline) {
			
			constexpr bool ROOT_NODE = N == NODE_ROOT;
			constexpr bool PV_NODE   = N != NODE_NON_PV;

			assert(PV_NODE || (alpha == beta - 1));

			if (nodes & 2047 && chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time).count() > allocated_time) {
				stop = true;
				return 0;
			}

			if (depth == 0)
				return quiescence<N>(pos, alpha, beta, nodes, ply, pline);

			++nodes;

			if (ply >= MAX_PLY)
				return eval::evaluate<false>(pos);

			// mate distance pruning
			// if me have found a mate, no point in finding a longer mate
			alpha = max(alpha, static_cast<int16_t>(-CHECKMATE_SCORE + ply));
			beta  = min(beta,  static_cast<int16_t>( CHECKMATE_SCORE - ply + 1));

			if (alpha >= beta)
				return alpha;

			TTEntry tte = tt.probe(pos.bs->key);

			if (tte.key == pos.bs->key) {
				if (PV_NODE && tte.move != MOVE_NONE) {
					assert(pline.last == pline.moves.data());
					*pline.last++ = tte.move;
				}
				if (!PV_NODE
				&& tte.depth >= depth
				&& (tte.flags == HASH_EXACT
				|| (tte.flags == HASH_BETA  && tte.eval >= beta)
				|| (tte.flags == HASH_ALPHA && tte.eval <= alpha)))
					return tte.eval;
			}

			const bool in_check = pos.is_king_in_check();

			if (!in_check) {

				int16_t score = tte.key == pos.bs->key ? tte.eval : eval::evaluate<false>(pos);

				// reverse futility pruning
				// if evaluation is above a certain threshold, we can trust that it will maintain it in the future
				if (!PV_NODE
				&& depth <= futility_depth
				&& score - depth * futility_factor > beta)
					return score;

				// null move pruning
				if (!PV_NODE
				&& !is_null
				&& depth >= null_depth
				&& pos.stm_has_promoted()) {

					pos.do_null_move();
					Line line;
					score = -negamax<NODE_NON_PV>(pos, -beta, -beta + 1, depth - null_reduction, ply + 1, true, MOVE_NULL, nodes, line);
					pos.undo_null_move();

					if (score >= beta)
						return beta;
				}

				// internal iterative deepening
				if (tte.key != pos.bs->key && depth >= iid_depth[PV_NODE]) {

					Line line;
					negamax<N>(pos, alpha, beta, iid_table[PV_NODE][depth], ply, false, prev_move, nodes, line);
					tte = tt.probe(pos.bs->key);

					if (tte.key == pos.bs->key) {
						if constexpr (PV_NODE) {
							assert(pline.last == pline.moves.data());
							*pline.last++ = tte.move;
						}
					}
				}
			}
			else
				++depth;

			move_pick::MovePicker mp(pos, ply, prev_move, tte.key == pos.bs->key ? tte.move : MOVE_NONE);
			Move best_move = MOVE_NONE;
			int16_t best_score = INT16_MIN;
			int moves_searched = 0;
			HashFlag hash_flag = HASH_ALPHA;
			bool play_quiets = true;

			while (const Move curr_move = mp.get_next(play_quiets)) {
				// illegal move
				if (!pos.do_move(curr_move)) continue;

				int16_t score = INT16_MIN;
				Line line;
				++moves_searched;

				if (pos.is_draw())
					score = DRAW_SCORE;
				else {
					if (moves_searched > 1
					&& depth > lmr_depth
					&& move_capture(curr_move) == NO_PIECE
					&& move_promotion_type(curr_move) == NO_PIECE) {
						
						const int history_entry = move_pick::get_history_entry(~pos.side, curr_move);
						// reduction factor
						int R = lmr_table[depth][min(moves_searched, 63)];
						// reduce for pv nodes
						R -= PV_NODE;
						// reduce for killers
						R -= move_pick::is_killer(curr_move, ply);
						// reduce based on history heuristic and lmr reduction
						R = clamp(R - clamp(history_entry / lmr_history_divisor, -lmr_history_min, lmr_history_max), 0, depth - lmr_reduction);
						// search current move with reduced depth:
						score = -negamax<NODE_NON_PV>(pos, -alpha - 1, -alpha, depth - R - 1, ply + 1, false, curr_move, nodes, line);
						// if search does not fail low, we search again without reduction
						if (R && score > alpha)
							score = -negamax<NODE_NON_PV>(pos, -alpha - 1, -alpha, depth - 1, ply + 1, false, curr_move, nodes, line);
					}
					else if (!PV_NODE || moves_searched > 1)
						score = -negamax<NODE_NON_PV>(pos, -alpha - 1, -alpha, depth - 1, ply + 1, false, curr_move, nodes, line);
					// full PV search if all options are exhausted
					if (PV_NODE && (moves_searched == 1 || ((ROOT_NODE || score < beta) && score > alpha)))
						score = -negamax<NODE_PV>(pos, -beta, -alpha, depth - 1, ply + 1, false, curr_move, nodes, line);
				}

				pos.undo_move(curr_move);

				if (stop) 
					return 0;

				// fail high
				if (score >= beta) {
					if (move_capture(curr_move) == NO_PIECE) {
						mp.update_history<HASH_BETA>(curr_move, depth);
						move_pick::update_killers(curr_move, ply);
						move_pick::update_counter_entry(pos.side, prev_move, curr_move);
					}
					tt.new_entry(pos.bs->key, depth, beta, HASH_BETA, curr_move);
					return beta;
				}

				if (score > best_score) {
					// new best move found
					best_move = curr_move, best_score = score;
                    
					if (score > alpha) {
						if constexpr (PV_NODE) {
							pline.last = pline.moves.data();
							*pline.last++ = curr_move;
							for (const auto& m : line)
								*pline.last++ = m;
						}
						hash_flag = HASH_EXACT;
						// new best move found
						alpha = score;
					}
				}

				if (!ROOT_NODE 
				&& score > - MIN_CHECKMATE_SCORE 
				&& moves_searched >= (4 + depth * depth))
					play_quiets = false;
			}

			// no legal moves
			if (moves_searched == 0)
				return in_check ? ply - CHECKMATE_SCORE : - DRAW_SCORE;

			tt.new_entry(pos.bs->key, depth, best_score, hash_flag, best_move);

			if (hash_flag == HASH_EXACT && move_capture(best_move) == NO_PIECE)
				mp.update_history<HASH_EXACT>(best_move, depth);

			return alpha;
		}

		// begin search
		void start_search(Position& pos, const SearchLimits& limits, SearchInfo& info) {

			move_gen::MoveList ml(pos);
			ml.remove_illegal(pos);

			if (ml.size() > 1) {

				start_time = chrono::steady_clock::now();
				allocated_time = limits.depth ? LLONG_MAX : 5 * limits.time[pos.side] / (limits.moves_left + 5);

				int16_t beta = CHECKMATE_SCORE, alpha = -beta;

				move_pick::reset_killers();
				move_pick::age_history();

				info.nodes = 0;

				for (uint8_t depth = 1; depth <= MAX_PLY && (limits.depth == 0 || depth <= limits.depth); ++depth) {

					info.score = negamax<NODE_ROOT>(pos, alpha, beta, depth, 0, false, MOVE_NONE, info.nodes, info.pline);

					if (stop) {
						stop = false;
						break;
					}

					if (info.score <= alpha) {
						assert(depth > asp_depth);
						alpha = -CHECKMATE_SCORE;
						--depth;
						continue;
					}
                    
					if (info.score >= beta) {
						assert(depth > asp_depth);
						beta = CHECKMATE_SCORE;
						--depth;
						continue;
					}

					const auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start_time).count();

					cout << "info depth " << setw(2) << static_cast<int>(depth)
					     << " score cp "  << setw(4) << info.score
					     << " nodes "     << setw(8) << info.nodes
					     << " time "      << setw(6) << elapsed_time
					     << " nps "       << setw(8) << 1000ULL * info.nodes / (elapsed_time + 1)
					     << " pv ";

					for (auto& it : info.pline)
						cout << it << " ";

					cout << endl;

					if (elapsed_time > allocated_time / 3) break;

					if (depth > asp_depth) {
						alpha = info.score - delta;
						beta  = info.score + delta;
					}
				}
			}
			else
				*info.pline.last++ = *ml.begin();

			cout << "bestmove " << info.pline.moves[0] << endl;
		}

	} // namespace search

} // namespace clovis
