#pragma once

#include <array>

#include "position.h"
#include "tt.h"

namespace Clovis {

	struct Position;

	namespace Eval {

		struct EvalInfo : public PTEntry {
			constexpr EvalInfo() : PTEntry(), n_att{ 0,0 } {}
			EvalInfo(const PTEntry& pte) : PTEntry(pte), n_att{0, 0} {}
			short n_att[COLOUR_N];
		};
	
#define S(mg, eg) Score(mg, eg)

        	constexpr Score pawn_source[] = {
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
			S(185, 245), S(182, 249), S(158, 236), S(197, 204),
			S(71, 97), S(89, 96), S(107, 89), S(112, 44),
			S(65, 85), S(79, 81), S(90, 75), S(102, 74),
			S(59, 77), S(67, 80), S(82, 75), S(99, 70),
			S(63, 71), S(73, 72), S(78, 76), S(82, 80),
			S(58, 74), S(78, 75), S(73, 83), S(70, 85),
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		};

		constexpr Score knight_source[] = {
			S(250, 199), S(296, 210), S(286, 236), S(303, 233),
			S(308, 213), S(299, 236), S(316, 239), S(322, 242),
			S(302, 223), S(317, 237), S(320, 244), S(328, 253),
			S(306, 236), S(311, 245), S(326, 252), S(322, 260),
		};

		constexpr Score bishop_source[] = {
			S(305, 230), S(337, 224), S(316, 236), S(323, 236),
			S(304, 238), S(334, 221), S(334, 235), S(330, 240),
			S(315, 239), S(333, 239), S(336, 240), S(333, 244),
			S(309, 242), S(312, 242), S(319, 243), S(330, 240),
		};

		constexpr Score rook_source[] = {
			S(443, 436), S(441, 438), S(445, 439), S(446, 437),
			S(420, 441), S(443, 435), S(454, 431), S(453, 431),
			S(436, 439), S(444, 439), S(448, 436), S(453, 436),
			S(431, 446), S(449, 439), S(450, 440), S(457, 436),
		};

		constexpr Score queen_source[] = {
			S(872, 819), S(847, 847), S(832, 862), S(868, 845),
			S(881, 810), S(850, 844), S(865, 851), S(831, 873),
			S(900, 810), S(896, 824), S(889, 835), S(874, 855),
			S(885, 834), S(877, 844), S(877, 841), S(873, 847),
			S(898, 814), S(893, 835), S(894, 822), S(891, 845),
			S(894, 818), S(907, 813), S(899, 829), S(898, 836),
			S(897, 792), S(914, 782), S(914, 801), S(913, 809),
			S(898, 791), S(895, 788), S(896, 790), S(908, 786),
		};

		constexpr Score king_source[] = {
			S(76, 14), S(105, 36), S(71, 58), S(69, 59),
			S(88, 44), S(107, 55), S(82, 72), S(53, 85),
			S(43, 63), S(88, 68), S(67, 85), S(61, 94),
			S(35, 64), S(72, 79), S(71, 92), S(39, 101),
		};

		constexpr Score passed_pawn[] = {
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
			S(40, 112), S(29, 111), S(43, 85), S(29, 108),
			S(30, 61), S(23, 63), S(10, 49), S(5, 35),
			S(12, 39), S(7, 41), S(0, 23), S(0, 20),
			S(0, 11), S(0, 20), S(0, 7), S(0, 0),
			S(2, 15), S(0, 13), S(0, 2), S(0, 2),
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		};

		constexpr Score candidate_passer[] = {
			S(0, 0), S(0, 5), S(0, 9), S(7, 24), S(21, 49), S(28, 66), S(0, 0), S(0, 0),
		};

		constexpr Score quiet_mobility[] = {
			S(0, 0), S(0, 0), S(6, 1), S(4, 4), S(3, 3), S(1, 3), S(0, 0),
		};

		constexpr Score capture_mobility[] = {
			S(0, 0), S(0, 0), S(8, 21), S(13, 20), S(10, 23), S(1, 16), S(0, 0),
		};

		constexpr Score double_pawn_penalty = S(1, 9);
		constexpr Score isolated_pawn_penalty = S(12, 6);
		constexpr Score bishop_pair_bonus = S(23, 43);
		constexpr Score rook_open_file_bonus = S(18, 2);
		constexpr Score rook_semi_open_file_bonus = S(0, 0);
		constexpr Score rook_closed_file_penalty = S(14, 4);
		constexpr Score tempo_bonus = S(23, 15);
		constexpr Score king_full_open_penalty = S(33, 10);
		constexpr Score king_adjacent_full_open_penalty = S(4, 10);
		constexpr Score knight_outpost_bonus = S(37, 11);
		constexpr Score bishop_outpost_bonus = S(36, 0);
		constexpr Score weak_queen_penalty = S(31, 5);
		constexpr Score rook_on_our_passer_file = S(5, 8);
		constexpr Score rook_on_their_passer_file = S(5, 29);
		constexpr Score tall_pawn_penalty = S(10, 24);
		constexpr Score fianchetto_bonus = S(17, 11);
		constexpr Score rook_on_seventh = S(0, 23);

		constexpr short pawn_shield[] = {
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			32, 34, 30, 0,
		};

		constexpr short inner_ring_attack[] = {
			0, 20, 18, 26, 23, 22, 0,
		};

		constexpr short outer_ring_attack[] = {
			0, 0, 28, 14, 10, 19, 0,
		};

		constexpr short virtual_mobility = 14;
		constexpr short attack_factor = 58;

#undef S

		constexpr std::array<Bitboard, SQ_N> file_masks = [] {
			std::array<Bitboard, SQ_N> arr{};

			for (Square sq = SQ_ZERO; sq < SQ_N; ++sq)
				for (Rank r = RANK_1; r < RANK_N; ++r)
					arr[sq] |= make_square(file_of(sq), r);

			return arr;
		}();
		
		constexpr std::array<Bitboard, SQ_N> rank_masks = [] {
			std::array<Bitboard, SQ_N> arr{};

			for (Square sq = SQ_ZERO; sq < SQ_N; ++sq)
				for (File f = FILE_A; f < FILE_N; ++f)
					arr[sq] |= make_square(f, rank_of(sq));

			return arr;
		}();
		
		constexpr std::array<Bitboard, SQ_N> isolated_masks = [] {
			std::array<Bitboard, SQ_N> arr{};

			for (Square sq = SQ_ZERO; sq < SQ_N; ++sq) {
				if (file_of(sq) != FILE_A)
					arr[sq] |= file_masks[sq + WEST];
				if (file_of(sq) != FILE_H)
					arr[sq] |= file_masks[sq + EAST];
			}

			return arr;
		}();
		
		constexpr std::array<std::array<Bitboard, SQ_N>, COLOUR_N> passed_masks = [] {
			std::array<std::array<Bitboard, SQ_N>, COLOUR_N> arr{};

			for (Colour c : {WHITE, BLACK})
				for (Square s1 = SQ_ZERO; s1 < SQ_N; ++s1)
					for (Square s2 = s1; is_valid(s2); s2 += pawn_push(c))
						arr[c][s1] |= Bitboards::pawn_attacks[c][s2] | s2;

			return arr;
		}();
		
		constexpr Bitboard outpost_masks[COLOUR_N] = { 0xffffff000000ULL, 0xffffff0000ULL };
		
		constexpr Bitboard outpost_pawn_masks[COLOUR_N][SQ_N] = {
			0x202020202020200ULL,  0x505050505050500ULL,  0xa0a0a0a0a0a0a00ULL,  0x1414141414141400ULL, 
			0x2828282828282800ULL, 0x5050505050505000ULL, 0xa0a0a0a0a0a0a000ULL, 0x4040404040404000ULL, 
			0x202020202020000ULL,  0x505050505050000ULL,  0xa0a0a0a0a0a0000ULL,  0x1414141414140000ULL, 
			0x2828282828280000ULL, 0x5050505050500000ULL, 0xa0a0a0a0a0a00000ULL, 0x4040404040400000ULL, 
			0x202020202000000ULL,  0x505050505000000ULL,  0xa0a0a0a0a000000ULL,  0x1414141414000000ULL, 
			0x2828282828000000ULL, 0x5050505050000000ULL, 0xa0a0a0a0a0000000ULL, 0x4040404040000000ULL, 
			0x202020200000000ULL,  0x505050500000000ULL,  0xa0a0a0a00000000ULL,  0x1414141400000000ULL, 
			0x2828282800000000ULL, 0x5050505000000000ULL, 0xa0a0a0a000000000ULL, 0x4040404000000000ULL, 
			0x202020000000000ULL,  0x505050000000000ULL,  0xa0a0a0000000000ULL,  0x1414140000000000ULL, 
			0x2828280000000000ULL, 0x5050500000000000ULL, 0xa0a0a00000000000ULL, 0x4040400000000000ULL, 
			0x202000000000000ULL,  0x505000000000000ULL,  0xa0a000000000000ULL,  0x1414000000000000ULL, 
			0x2828000000000000ULL, 0x5050000000000000ULL, 0xa0a0000000000000ULL, 0x4040000000000000ULL, 
			0x200000000000000ULL,  0x500000000000000ULL,  0xa00000000000000ULL,  0x1400000000000000ULL, 
			0x2800000000000000ULL, 0x5000000000000000ULL, 0xa000000000000000ULL, 0x4000000000000000ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x2ULL,                0x5ULL,                0xaULL,                0x14ULL, 
			0x28ULL,               0x50ULL,               0xa0ULL,               0x40ULL, 
			0x202ULL,              0x505ULL,              0xa0aULL,              0x1414ULL, 
			0x2828ULL,             0x5050ULL,             0xa0a0ULL,             0x4040ULL, 
			0x20202ULL,            0x50505ULL,            0xa0a0aULL,            0x141414ULL, 
			0x282828ULL,           0x505050ULL,           0xa0a0a0ULL,           0x404040ULL, 
			0x2020202ULL,          0x5050505ULL,          0xa0a0a0aULL,          0x14141414ULL, 
			0x28282828ULL,         0x50505050ULL,         0xa0a0a0a0ULL,         0x40404040ULL, 
			0x202020202ULL,        0x505050505ULL,        0xa0a0a0a0aULL,        0x1414141414ULL, 
			0x2828282828ULL,       0x5050505050ULL,       0xa0a0a0a0a0ULL,       0x4040404040ULL, 
			0x20202020202ULL,      0x50505050505ULL,      0xa0a0a0a0a0aULL,      0x141414141414ULL, 
			0x282828282828ULL,     0x505050505050ULL,     0xa0a0a0a0a0a0ULL,     0x404040404040ULL, 
			0x2020202020202ULL,    0x5050505050505ULL,    0xa0a0a0a0a0a0aULL,    0x14141414141414ULL, 
			0x28282828282828ULL,   0x50505050505050ULL,   0xa0a0a0a0a0a0a0ULL,   0x40404040404040ULL,
		};

		constexpr std::array<std::array<Bitboard, SQ_N>, COLOUR_N> rook_on_passer_masks = [] {
			std::array<std::array<Bitboard, SQ_N>, COLOUR_N> arr{};

			for (Colour c : {WHITE, BLACK})
				for (Square s1 = SQ_ZERO; s1 < SQ_N; ++s1)
					for (Square s2 = s1; is_valid(s2); s2 += pawn_push(c))
						arr[c][s1] |= s2;

			return arr;
		}();

		constexpr Bitboard light_mask = 0x55aa55aa55aa55aaULL;

		constexpr Bitboard dark_mask = 0xaa55aa55aa55aa55ULL;

		constexpr Bitboard fianchetto_bishop_mask[COLOUR_N] = { 0x4200ULL, 0x42000000000000ULL };

		constexpr Bitboard fianchetto_pawn_mask[COLOUR_N] = { 0x42a500ULL, 0xa5420000000000ULL };

		constexpr Bitboard center_mask = 0x1818000000ULL;

		constexpr std::array<Bitboard, SQ_N> inner_ring = [] {
			std::array<Bitboard, SQ_N> arr{};

			for (Square sq = SQ_ZERO; sq < SQ_N; ++sq)
				arr[sq] = Bitboards::get_attacks<KING>(sq) | sq;

			return arr;
		}();
		
		constexpr std::array<Bitboard, SQ_N> outer_ring = [] {
			std::array<Bitboard, SQ_N> arr{};

			for (Square s1 = SQ_ZERO; s1 < SQ_N; ++s1) {
				Bitboard bb = Bitboards::get_attacks<KING>(s1);
				while (bb) {
					Square s2 = pop_lsb(bb);
					arr[s1] |= Bitboards::get_attacks<KING>(s2);
				}
				arr[s1] &= ~(Bitboards::get_attacks<KING>(s1) | s1);
			}

			return arr;
		}();
		
		constexpr int source32[] = {
			28, 29, 30, 31, 31, 30, 29, 28,
			24, 25, 26, 27, 27, 26, 25, 24,
			20, 21, 22, 23, 23, 22, 21, 20,
			16, 17, 18, 19, 19, 18, 17, 16,
			12, 13, 14, 15, 15, 14, 13, 12,
			 8,  9, 10, 11, 11, 10,  9,  8,
			 4,  5,  6,  7,  7,  6,  5,  4,
			 0,  1,  2,  3,  3,  2,  1,  0,
		};
		
		constexpr int source16[] = {
			 0,  1,  2,  3,  3,  2,  1,  0,
			 4,  5,  6,  7,  7,  6,  5,  4,
			 8,  9, 10, 11, 11, 10,  9,  8,
			12, 13, 14, 15, 15, 14, 13, 12,
			12, 13, 14, 15, 15, 14, 13, 12,
			 8,  9, 10, 11, 11, 10,  9,  8,
			 4,  5,  6,  7,  7,  6,  5,  4,
			 0,  1,  2,  3,  3,  2,  1,  0,
		};
		
		constexpr int source10[] = {
			 0,  1,  2,  3,  3,  2,  1,  0,
			 1,  4,  5,  6,  6,  5,  4,  1,
			 2,  5,  7,  8,  8,  7,  5,  2,
			 3,  6,  8,  9,  9,  8,  6,  3,
			 3,  6,  8,  9,  9,  8,  6,  3,
			 2,  5,  7,  8,  8,  7,  5,  2,
			 1,  4,  5,  6,  6,  5,  4,  1,
			 0,  1,  2,  3,  3,  2,  1,  0,
		};

		void init_eval();
		template<bool TRACE> int evaluate(const Position& pos);
		
		extern int T[TI_MISC][PHASE_N];

	} // namespace Eval

} // namespace Clovis
