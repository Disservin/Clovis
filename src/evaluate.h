#pragma once

#include "position.h"
#include "tt.h"

namespace Clovis {

	struct Position;

	namespace Eval {
	
#define S(mg, eg) Score(mg, eg)

        constexpr Score pawn_table[] = {
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
			S(100, 282), S(144, 260), S(152, 233), S(160, 220),
			S(77, 90), S(96, 88), S(119, 83), S(113, 83),
			S(62, 80), S(81, 76), S(84, 76), S(94, 69),
			S(54, 72), S(63, 73), S(78, 70), S(90, 69),
			S(60, 66), S(72, 67), S(77, 71), S(76, 76),
			S(56, 68), S(77, 67), S(72, 79), S(67, 82),
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		};

		constexpr Score knight_table[] = {
			S(179, 188), S(241, 209), S(222, 234), S(298, 222),
			S(265, 219), S(291, 235), S(370, 217), S(318, 243),
			S(302, 217), S(344, 228), S(333, 250), S(347, 246),
			S(321, 228), S(320, 246), S(328, 258), S(328, 264),
			S(312, 228), S(327, 243), S(331, 255), S(330, 259),
			S(307, 226), S(328, 234), S(330, 240), S(334, 253),
			S(308, 209), S(301, 228), S(319, 235), S(328, 238),
			S(283, 206), S(311, 199), S(297, 227), S(312, 227),
		};

		constexpr Score bishop_table[] = {
			S(307, 232), S(323, 237), S(323, 234), S(320, 240),
			S(309, 236), S(339, 225), S(336, 240), S(335, 241),
			S(315, 243), S(336, 242), S(346, 244), S(335, 250),
			S(316, 243), S(321, 243), S(324, 250), S(340, 248),
		};

		constexpr Score rook_table[] = {
			S(416, 459), S(434, 454), S(405, 462), S(448, 452),
			S(428, 458), S(420, 463), S(458, 451), S(460, 447),
			S(415, 453), S(443, 451), S(429, 453), S(427, 453),
			S(405, 458), S(417, 452), S(436, 455), S(428, 451),
			S(403, 454), S(421, 451), S(418, 453), S(426, 448),
			S(404, 447), S(422, 447), S(426, 442), S(422, 443),
			S(401, 447), S(425, 440), S(424, 443), S(432, 441),
			S(428, 436), S(421, 445), S(431, 443), S(430, 442),
		};

		constexpr Score queen_table[] = {
			S(907, 785), S(891, 810), S(894, 822), S(918, 800),
			S(903, 786), S(856, 824), S(879, 828), S(849, 856),
			S(917, 785), S(905, 803), S(903, 809), S(878, 841),
			S(899, 812), S(892, 823), S(891, 815), S(883, 830),
			S(916, 782), S(901, 819), S(905, 808), S(906, 817),
			S(908, 796), S(928, 779), S(917, 800), S(916, 795),
			S(907, 779), S(923, 763), S(935, 764), S(928, 780),
			S(924, 758), S(916, 762), S(915, 766), S(929, 753),
		};

		constexpr Score king_table[] = {
			S(67, 16), S(104, 35), S(70, 59), S(76, 56),
			S(75, 45), S(104, 57), S(76, 77), S(58, 87),
			S(51, 58), S(92, 71), S(81, 85), S(74, 93),
			S(22, 61), S(70, 80), S(61, 95), S(47, 103),
		};

		constexpr Score passed_pawn[] = {
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
			S(6, 5), S(4, 5), S(5, 5), S(6, 4),
			S(8, 122), S(0, 113), S(9, 89), S(2, 68),
			S(11, 62), S(3, 59), S(7, 39), S(6, 32),
			S(9, 35), S(0, 33), S(0, 18), S(0, 15),
			S(5, 11), S(0, 14), S(0, 3), S(0, 0),
			S(0, 11), S(2, 8), S(4, 0), S(0, 0),
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		};

		constexpr Score mobility[] = {
			S(0, 0), S(0, 0), S(5, 0), S(4, 2), S(4, 1), S(1, 4), S(0, 0),
		};

		constexpr Score double_pawn_penalty = S(0, 6);
		constexpr Score isolated_pawn_penalty = S(15, 7);
		constexpr Score bishop_pair_bonus = S(24, 42);
		constexpr Score rook_open_file_bonus = S(27, 0);
		constexpr Score rook_semi_open_file_bonus = S(3, 9);
		constexpr Score rook_closed_file_penalty = S(13, 4);
		constexpr Score tempo_bonus = S(17, 15);
		constexpr Score king_full_open_penalty = S(38, 7);
		constexpr Score king_semi_open_penalty = S(11, 0);
		constexpr Score king_adjacent_full_open_penalty = S(8, 9);
		constexpr Score king_adjacent_semi_open_penalty = S(14, 0);
		constexpr Score knight_outpost_bonus = S(35, 12);
		constexpr Score bishop_outpost_bonus = S(38, 0);
		constexpr Score weak_queen_penalty = S(32, 1);
		constexpr Score rook_on_our_passer_file = S(8, 8);
		constexpr Score rook_on_their_passer_file = S(0, 38);
		constexpr Score tall_pawn_penalty = S(12, 24);
		constexpr Score fianchetto_bonus = S(19, 12);
		constexpr Score rook_on_seventh = S(19, 20);

		constexpr short pawn_shield[] = {
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			21, 27, 24, 0,
		};

		constexpr short inner_ring_attack[] = {
			0, 38, 21, 37, 36, 25, 0,
		};

		constexpr short outer_ring_attack[] = {
			0, 4, 35, 15, 14, 25, 0,
		};

		constexpr short virtual_mobility = 15;

#undef S

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
			0x282828282828ULL,     0x505050505050ULL,     0xa0a0a0a0a0a0ULL,     0x404040404040ULL, 
			0x2020202020202ULL,    0x5050505050505ULL,    0xa0a0a0a0a0a0aULL,    0x14141414141414ULL, 
			0x28282828282828ULL,   0x50505050505050ULL,   0xa0a0a0a0a0a0a0ULL,   0x40404040404040ULL,
		};

		constexpr Bitboard rook_on_passer_masks[COLOUR_N][SQ_N] = {
			0x101010101010100ULL,  0x202020202020200ULL,  0x404040404040400ULL,  0x808080808080800ULL, 
			0x1010101010101000ULL, 0x2020202020202000ULL, 0x4040404040404000ULL, 0x8080808080808000ULL, 
			0x101010101010000ULL,  0x202020202020000ULL,  0x404040404040000ULL,  0x808080808080000ULL, 
			0x1010101010100000ULL, 0x2020202020200000ULL, 0x4040404040400000ULL, 0x8080808080800000ULL, 
			0x101010101000000ULL,  0x202020202000000ULL,  0x404040404000000ULL,  0x808080808000000ULL, 
			0x1010101010000000ULL, 0x2020202020000000ULL, 0x4040404040000000ULL, 0x8080808080000000ULL, 
			0x101010100000000ULL,  0x202020200000000ULL,  0x404040400000000ULL,  0x808080800000000ULL, 
			0x1010101000000000ULL, 0x2020202000000000ULL, 0x4040404000000000ULL, 0x8080808000000000ULL, 
			0x101010000000000ULL,  0x202020000000000ULL,  0x404040000000000ULL,  0x808080000000000ULL, 
			0x1010100000000000ULL, 0x2020200000000000ULL, 0x4040400000000000ULL, 0x8080800000000000ULL, 
			0x101000000000000ULL,  0x202000000000000ULL,  0x404000000000000ULL,  0x808000000000000ULL, 
			0x1010000000000000ULL, 0x2020000000000000ULL, 0x4040000000000000ULL, 0x8080000000000000ULL, 
			0x100000000000000ULL,  0x200000000000000ULL,  0x400000000000000ULL,  0x800000000000000ULL, 
			0x1000000000000000ULL, 0x2000000000000000ULL, 0x4000000000000000ULL, 0x8000000000000000ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x0ULL,                0x0ULL,                0x0ULL,                0x0ULL, 
			0x1ULL,                0x2ULL,                0x4ULL,                0x8ULL, 
			0x10ULL,               0x20ULL,               0x40ULL,               0x80ULL, 
			0x101ULL,              0x202ULL,              0x404ULL,              0x808ULL, 
			0x1010ULL,             0x2020ULL,             0x4040ULL,             0x8080ULL, 
			0x10101ULL,            0x20202ULL,            0x40404ULL,            0x80808ULL, 
			0x101010ULL,           0x202020ULL,           0x404040ULL,           0x808080ULL, 
			0x1010101ULL,          0x2020202ULL,          0x4040404ULL,          0x8080808ULL, 
			0x10101010ULL,         0x20202020ULL,         0x40404040ULL,         0x80808080ULL, 
			0x101010101ULL,        0x202020202ULL,        0x404040404ULL,        0x808080808ULL, 
			0x1010101010ULL,       0x2020202020ULL,       0x4040404040ULL,       0x8080808080ULL, 
			0x10101010101ULL,      0x20202020202ULL,      0x40404040404ULL,      0x80808080808ULL, 
			0x101010101010ULL,     0x202020202020ULL,     0x404040404040ULL,     0x808080808080ULL, 
			0x1010101010101ULL,    0x2020202020202ULL,    0x4040404040404ULL,    0x8080808080808ULL, 
			0x10101010101010ULL,   0x20202020202020ULL,   0x40404040404040ULL,   0x80808080808080ULL,
		};
		
		constexpr Bitboard light_mask = 0x55aa55aa55aa55aaULL;

		constexpr Bitboard dark_mask = 0xaa55aa55aa55aa55ULL;

		constexpr Bitboard fianchetto_bishop_mask[COLOUR_N] = { 0x4200ULL, 0x42000000000000ULL };

		constexpr Bitboard fianchetto_pawn_mask[COLOUR_N] = { 0x42a500ULL, 0xa5420000000000ULL };

		constexpr Bitboard center_mask = 0x1818000000ULL;

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
			 2,  9,  7,  8,  8,  7,  9,  2,
			 3,  6,  8,  9,  9,  8,  6,  3,
			 3,  6,  8,  9,  9,  8,  6,  3,
			 2,  9,  7,  8,  8,  7,  9,  2,
			 1,  4,  5,  6,  6,  5,  4,  1,
			 0,  1,  2,  3,  3,  2,  1,  0,
		};

		void init_eval();
		void init_values();
		template<bool TRACE> int evaluate(const Position& pos);
		
		extern int T[TI_N][PHASE_N];

	} // namespace Eval

} // namespace Clovis
