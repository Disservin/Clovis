#pragma once

#include "position.h"
#include "tt.h"

namespace Clovis {

	struct Position;

	namespace Eval {

		extern Score pawn_table[32];
		extern Score knight_table[32];
		extern Score bishop_table[16];
		extern Score rook_table[32];
		extern Score queen_table[32];
		extern Score king_table[16];
		extern Score double_pawn_penalty;
		extern Score isolated_pawn_penalty;
		extern Score passed_pawn_bonus[32];
		extern Score pawn_shield[32];
		extern Score bishop_pair_bonus;
		extern Score rook_open_file_bonus;
		extern Score rook_semi_open_file_bonus;
		extern Score rook_closed_file_penalty;
		extern Score tempo_bonus;
		extern Score mobility[7];
		extern Score outer_ring_attack[7];
		extern Score inner_ring_attack[7];
		extern Score knight_outpost_bonus;
		extern Score bishop_outpost_bonus;
		extern Score king_full_open_penalty;
		extern Score king_semi_open_penalty;
		extern Score king_adjacent_full_open_penalty;
		extern Score king_adjacent_semi_open_penalty;
		extern Score virtual_king_m;
		extern Score virtual_king_b;
		extern Score weak_queen_penalty;

		extern const Score* piece_table[7];
		extern const Score* score_table[15][SQ_N];
		extern const Score* passed_table[COLOUR_N][SQ_N];
		extern const Score* shield_table[COLOUR_N][SQ_N];
	
		constexpr Bitboard file_masks[SQ_N] =  {
			0x101010101010101ULL,  0x202020202020202ULL,  0x404040404040404ULL,  0x808080808080808ULL, 
			0x1010101010101010ULL, 0x2020202020202020ULL, 0x4040404040404040ULL, 0x8080808080808080ULL, 
			0x101010101010101ULL,  0x202020202020202ULL,  0x404040404040404ULL,  0x808080808080808ULL, 
			0x1010101010101010ULL, 0x2020202020202020ULL, 0x4040404040404040ULL, 0x8080808080808080ULL, 
			0x101010101010101ULL,  0x202020202020202ULL,  0x404040404040404ULL,  0x808080808080808ULL, 
			0x1010101010101010ULL, 0x2020202020202020ULL, 0x4040404040404040ULL, 0x8080808080808080ULL, 
			0x101010101010101ULL,  0x202020202020202ULL,  0x404040404040404ULL,  0x808080808080808ULL, 
			0x1010101010101010ULL, 0x2020202020202020ULL, 0x4040404040404040ULL, 0x8080808080808080ULL, 
			0x101010101010101ULL,  0x202020202020202ULL,  0x404040404040404ULL,  0x808080808080808ULL, 
			0x1010101010101010ULL, 0x2020202020202020ULL, 0x4040404040404040ULL, 0x8080808080808080ULL, 
			0x101010101010101ULL,  0x202020202020202ULL,  0x404040404040404ULL,  0x808080808080808ULL, 
			0x1010101010101010ULL, 0x2020202020202020ULL, 0x4040404040404040ULL, 0x8080808080808080ULL, 
			0x101010101010101ULL,  0x202020202020202ULL,  0x404040404040404ULL,  0x808080808080808ULL, 
			0x1010101010101010ULL, 0x2020202020202020ULL, 0x4040404040404040ULL, 0x8080808080808080ULL, 
			0x101010101010101ULL,  0x202020202020202ULL,  0x404040404040404ULL,  0x808080808080808ULL, 
			0x1010101010101010ULL, 0x2020202020202020ULL, 0x4040404040404040ULL, 0x8080808080808080ULL,
		};
		
		constexpr Bitboard rank_masks[SQ_N] = {
			0xffULL,               0xffULL,               0xffULL,               0xffULL, 
			0xffULL,               0xffULL,               0xffULL,               0xffULL, 
			0xff00ULL,             0xff00ULL,             0xff00ULL,             0xff00ULL, 
			0xff00ULL,             0xff00ULL,             0xff00ULL,             0xff00ULL, 
			0xff0000ULL,           0xff0000ULL,           0xff0000ULL,           0xff0000ULL, 
			0xff0000ULL,           0xff0000ULL,           0xff0000ULL,           0xff0000ULL, 
			0xff000000ULL,         0xff000000ULL,         0xff000000ULL,         0xff000000ULL, 
			0xff000000ULL,         0xff000000ULL,         0xff000000ULL,         0xff000000ULL, 
			0xff00000000ULL,       0xff00000000ULL,       0xff00000000ULL,       0xff00000000ULL, 
			0xff00000000ULL,       0xff00000000ULL,       0xff00000000ULL,       0xff00000000ULL, 
			0xff0000000000ULL,     0xff0000000000ULL,     0xff0000000000ULL,     0xff0000000000ULL, 
			0xff0000000000ULL,     0xff0000000000ULL,     0xff0000000000ULL,     0xff0000000000ULL, 
			0xff000000000000ULL,   0xff000000000000ULL,   0xff000000000000ULL,   0xff000000000000ULL, 
			0xff000000000000ULL,   0xff000000000000ULL,   0xff000000000000ULL,   0xff000000000000ULL, 
			0xff00000000000000ULL, 0xff00000000000000ULL, 0xff00000000000000ULL, 0xff00000000000000ULL, 
			0xff00000000000000ULL, 0xff00000000000000ULL, 0xff00000000000000ULL, 0xff00000000000000ULL,
		};
		
		constexpr Bitboard isolated_masks[SQ_N] = {
			0x202020202020202ULL,  0x505050505050505ULL,  0xa0a0a0a0a0a0a0aULL,  0x1414141414141414ULL, 
			0x2828282828282828ULL, 0x5050505050505050ULL, 0xa0a0a0a0a0a0a0a0ULL, 0x4040404040404040ULL, 
			0x202020202020202ULL,  0x505050505050505ULL,  0xa0a0a0a0a0a0a0aULL,  0x1414141414141414ULL, 
			0x2828282828282828ULL, 0x5050505050505050ULL, 0xa0a0a0a0a0a0a0a0ULL, 0x4040404040404040ULL, 
			0x202020202020202ULL,  0x505050505050505ULL,  0xa0a0a0a0a0a0a0aULL,  0x1414141414141414ULL, 
			0x2828282828282828ULL, 0x5050505050505050ULL, 0xa0a0a0a0a0a0a0a0ULL, 0x4040404040404040ULL, 
			0x202020202020202ULL,  0x505050505050505ULL,  0xa0a0a0a0a0a0a0aULL,  0x1414141414141414ULL, 
			0x2828282828282828ULL, 0x5050505050505050ULL, 0xa0a0a0a0a0a0a0a0ULL, 0x4040404040404040ULL, 
			0x202020202020202ULL,  0x505050505050505ULL,  0xa0a0a0a0a0a0a0aULL,  0x1414141414141414ULL, 
			0x2828282828282828ULL, 0x5050505050505050ULL, 0xa0a0a0a0a0a0a0a0ULL, 0x4040404040404040ULL, 
			0x202020202020202ULL,  0x505050505050505ULL,  0xa0a0a0a0a0a0a0aULL,  0x1414141414141414ULL, 
			0x2828282828282828ULL, 0x5050505050505050ULL, 0xa0a0a0a0a0a0a0a0ULL, 0x4040404040404040ULL, 
			0x202020202020202ULL,  0x505050505050505ULL,  0xa0a0a0a0a0a0a0aULL,  0x1414141414141414ULL, 
			0x2828282828282828ULL, 0x5050505050505050ULL, 0xa0a0a0a0a0a0a0a0ULL, 0x4040404040404040ULL, 
			0x202020202020202ULL,  0x505050505050505ULL,  0xa0a0a0a0a0a0a0aULL,  0x1414141414141414ULL, 
			0x2828282828282828ULL, 0x5050505050505050ULL, 0xa0a0a0a0a0a0a0a0ULL, 0x4040404040404040ULL,
		};
		
		constexpr Bitboard passed_masks[COLOUR_N][SQ_N] = {
			0x303030303030300ULL,  0x707070707070700ULL,  0xe0e0e0e0e0e0e00ULL,  0x1c1c1c1c1c1c1c00ULL, 
			0x3838383838383800ULL, 0x7070707070707000ULL, 0xe0e0e0e0e0e0e000ULL, 0xc0c0c0c0c0c0c000ULL, 
			0x303030303030000ULL,  0x707070707070000ULL,  0xe0e0e0e0e0e0000ULL,  0x1c1c1c1c1c1c0000ULL, 
			0x3838383838380000ULL, 0x7070707070700000ULL, 0xe0e0e0e0e0e00000ULL, 0xc0c0c0c0c0c00000ULL, 
			0x303030303000000ULL,  0x707070707000000ULL,  0xe0e0e0e0e000000ULL,  0x1c1c1c1c1c000000ULL, 
			0x3838383838000000ULL, 0x7070707070000000ULL, 0xe0e0e0e0e0000000ULL, 0xc0c0c0c0c0000000ULL, 
			0x303030300000000ULL,  0x707070700000000ULL,  0xe0e0e0e00000000ULL,  0x1c1c1c1c00000000ULL, 
			0x3838383800000000ULL, 0x7070707000000000ULL, 0xe0e0e0e000000000ULL, 0xc0c0c0c000000000ULL, 
			0x303030000000000ULL,  0x707070000000000ULL,  0xe0e0e0000000000ULL,  0x1c1c1c0000000000ULL, 
			0x3838380000000000ULL, 0x7070700000000000ULL, 0xe0e0e00000000000ULL, 0xc0c0c00000000000ULL, 
			0x303000000000000ULL,  0x707000000000000ULL,  0xe0e000000000000ULL,  0x1c1c000000000000ULL, 
			0x3838000000000000ULL, 0x7070000000000000ULL, 0xe0e0000000000000ULL, 0xc0c0000000000000ULL, 
			0x300000000000000ULL,  0x700000000000000ULL,  0xe00000000000000ULL,  0x1c00000000000000ULL, 
			0x3800000000000000ULL, 0x7000000000000000ULL, 0xe000000000000000ULL, 0xc000000000000000ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x3ULL,                0x7ULL,                0xeULL,                0x1cULL, 
			0x38ULL,               0x70ULL,               0xe0ULL,               0xc0ULL, 
			0x303ULL,              0x707ULL,              0xe0eULL,              0x1c1cULL, 
			0x3838ULL,             0x7070ULL,             0xe0e0ULL,             0xc0c0ULL, 
			0x30303ULL,            0x70707ULL,            0xe0e0eULL,            0x1c1c1cULL, 
			0x383838ULL,           0x707070ULL,           0xe0e0e0ULL,           0xc0c0c0ULL, 
			0x3030303ULL,          0x7070707ULL,          0xe0e0e0eULL,          0x1c1c1c1cULL, 
			0x38383838ULL,         0x70707070ULL,         0xe0e0e0e0ULL,         0xc0c0c0c0ULL, 
			0x303030303ULL,        0x707070707ULL,        0xe0e0e0e0eULL,        0x1c1c1c1c1cULL, 
			0x3838383838ULL,       0x7070707070ULL,       0xe0e0e0e0e0ULL,       0xc0c0c0c0c0ULL, 
			0x30303030303ULL,      0x70707070707ULL,      0xe0e0e0e0e0eULL,      0x1c1c1c1c1c1cULL, 
			0x383838383838ULL,     0x707070707070ULL,     0xe0e0e0e0e0e0ULL,     0xc0c0c0c0c0c0ULL, 
			0x3030303030303ULL,    0x7070707070707ULL,    0xe0e0e0e0e0e0eULL,    0x1c1c1c1c1c1c1cULL, 
			0x38383838383838ULL,   0x70707070707070ULL,   0xe0e0e0e0e0e0e0ULL,   0xc0c0c0c0c0c0c0ULL,
		};
		
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
		};

#define KZ(out, in) KingZone(out, in)

		constexpr KingZone king_zones[SQ_N] = {
			KZ(0x70404ULL,            0x302ULL),              KZ(0xf0808ULL,            0x705ULL), 
			KZ(0x1f1111ULL,           0xe0aULL),              KZ(0x3e2222ULL,           0x1c14ULL), 
			KZ(0x7c4444ULL,           0x3828ULL),             KZ(0xf88888ULL,           0x7050ULL), 
			KZ(0xf01010ULL,           0xe0a0ULL),             KZ(0xe02020ULL,           0xc040ULL), 
			KZ(0x7040404ULL,          0x30203ULL),            KZ(0xf080808ULL,          0x70507ULL), 
			KZ(0x1f111111ULL,         0xe0a0eULL),            KZ(0x3e222222ULL,         0x1c141cULL), 
			KZ(0x7c444444ULL,         0x382838ULL),           KZ(0xf8888888ULL,         0x705070ULL), 
			KZ(0xf0101010ULL,         0xe0a0e0ULL),           KZ(0xe0202020ULL,         0xc040c0ULL), 
			KZ(0x704040407ULL,        0x3020300ULL),          KZ(0xf0808080fULL,        0x7050700ULL), 
			KZ(0x1f1111111fULL,       0xe0a0e00ULL),          KZ(0x3e2222223eULL,       0x1c141c00ULL), 
			KZ(0x7c4444447cULL,       0x38283800ULL),         KZ(0xf8888888f8ULL,       0x70507000ULL), 
			KZ(0xf0101010f0ULL,       0xe0a0e000ULL),         KZ(0xe0202020e0ULL,       0xc040c000ULL), 
			KZ(0x70404040700ULL,      0x302030000ULL),        KZ(0xf0808080f00ULL,      0x705070000ULL), 
			KZ(0x1f1111111f00ULL,     0xe0a0e0000ULL),        KZ(0x3e2222223e00ULL,     0x1c141c0000ULL), 
			KZ(0x7c4444447c00ULL,     0x3828380000ULL),       KZ(0xf8888888f800ULL,     0x7050700000ULL), 
			KZ(0xf0101010f000ULL,     0xe0a0e00000ULL),       KZ(0xe0202020e000ULL,     0xc040c00000ULL), 
			KZ(0x7040404070000ULL,    0x30203000000ULL),      KZ(0xf0808080f0000ULL,    0x70507000000ULL), 
			KZ(0x1f1111111f0000ULL,   0xe0a0e000000ULL),      KZ(0x3e2222223e0000ULL,   0x1c141c000000ULL), 
			KZ(0x7c4444447c0000ULL,   0x382838000000ULL),     KZ(0xf8888888f80000ULL,   0x705070000000ULL), 
			KZ(0xf0101010f00000ULL,   0xe0a0e0000000ULL),     KZ(0xe0202020e00000ULL,   0xc040c0000000ULL), 
			KZ(0x704040407000000ULL,  0x3020300000000ULL),    KZ(0xf0808080f000000ULL,  0x7050700000000ULL), 
			KZ(0x1f1111111f000000ULL, 0xe0a0e00000000ULL),    KZ(0x3e2222223e000000ULL, 0x1c141c00000000ULL), 
			KZ(0x7c4444447c000000ULL, 0x38283800000000ULL),   KZ(0xf8888888f8000000ULL, 0x70507000000000ULL), 
			KZ(0xf0101010f0000000ULL, 0xe0a0e000000000ULL),   KZ(0xe0202020e0000000ULL, 0xc040c000000000ULL), 
			KZ(0x404040700000000ULL,  0x302030000000000ULL),  KZ(0x808080f00000000ULL,  0x705070000000000ULL), 
			KZ(0x1111111f00000000ULL, 0xe0a0e0000000000ULL),  KZ(0x2222223e00000000ULL, 0x1c141c0000000000ULL), 
			KZ(0x4444447c00000000ULL, 0x3828380000000000ULL), KZ(0x888888f800000000ULL, 0x7050700000000000ULL), 
			KZ(0x101010f000000000ULL, 0xe0a0e00000000000ULL), KZ(0x202020e000000000ULL, 0xc040c00000000000ULL), 
			KZ(0x404070000000000ULL,  0x203000000000000ULL),  KZ(0x8080f0000000000ULL,  0x507000000000000ULL), 
			KZ(0x11111f0000000000ULL, 0xa0e000000000000ULL),  KZ(0x22223e0000000000ULL, 0x141c000000000000ULL), 
			KZ(0x44447c0000000000ULL, 0x2838000000000000ULL), KZ(0x8888f80000000000ULL, 0x5070000000000000ULL), 
			KZ(0x1010f00000000000ULL, 0xa0e0000000000000ULL), KZ(0x2020e00000000000ULL, 0x40c0000000000000ULL),
		};

#undef KZ

		void init_eval();
		void init_values();
		template<bool USE_TT> int evaluate(const Position& pos);
		
		inline bool doubled_pawn(Bitboard bb, Square sq) 
		{
			return popcnt(bb & file_masks[sq]) >= 2;
		}
		
		constexpr bool isolated_pawn(Bitboard bb, Square sq) 
		{
			return !(bb & isolated_masks[sq]);
		}

		template<Colour US>
		constexpr bool passed_pawn(Bitboard bb, Square sq) 
		{
			return !(bb & passed_masks[US][sq]);
		}

		template<Colour US>
		constexpr bool outpost(const Position& pos, Square sq) 
		{
			return (Bitboards::pawn_attacks[~US][sq] & pos.pc_bb[make_piece(PAWN, US)]) 
				&& (outpost_masks[US] & sq) 
				&& !(pos.pc_bb[make_piece(PAWN, ~US)] & outpost_pawn_masks[US][sq]);
		}
		
		template<Colour US, PieceType PT>
		inline void king_danger(Bitboard attacks, PTEntry& pte)
		{
			Bitboard or_att_bb = attacks & king_zones[pte.ksq[~US]].outer_ring;
			Bitboard ir_att_bb = attacks & king_zones[pte.ksq[~US]].inner_ring;
		
			if (or_att_bb || ir_att_bb)
			{
				pte.weight[US] += inner_ring_attack[PT] * popcnt(ir_att_bb) + outer_ring_attack[PT] * popcnt(or_att_bb);
				if constexpr (PT != PAWN)
					++pte.n_att[US];
			}
		}

	} // namespace Eval

} // namespace Clovis
