#pragma once

#include "position.h"
#include "tt.h"

namespace Clovis {

	struct Position;

	namespace Eval {
	
#define S(mg, eg) Score(mg, eg)

		constexpr Score pawn_table[] = {
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
			S(128, 340), S(175, 314), S(187, 281), S(198, 266),
			S(92, 113), S(112, 108), S(143, 98), S(129, 100),
			S(76, 98), S(95, 93), S(98, 93), S(113, 81),
			S(65, 88), S(74, 89), S(94, 83), S(102, 83),
			S(73, 81), S(85, 82), S(91, 86), S(93, 90),
			S(67, 83), S(90, 81), S(81, 95), S(81, 98),
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		};

		constexpr Score knight_table[] = {
			S(184, 239), S(248, 264), S(240, 290), S(317, 279),
			S(285, 271), S(314, 290), S(402, 273), S(344, 303),
			S(325, 271), S(377, 283), S(369, 309), S(378, 307),
			S(350, 283), S(354, 302), S(362, 319), S(364, 325),
			S(339, 283), S(357, 301), S(363, 316), S(362, 320),
			S(333, 281), S(360, 290), S(363, 299), S(367, 314),
			S(335, 259), S(336, 280), S(351, 291), S(362, 293),
			S(305, 258), S(336, 253), S(322, 283), S(338, 284),
		};

		constexpr Score bishop_table[] = {
			S(317, 292), S(334, 299), S(335, 296), S(334, 302),
			S(318, 296), S(357, 282), S(350, 302), S(348, 305),
			S(325, 305), S(348, 306), S(359, 309), S(346, 315),
			S(325, 307), S(330, 307), S(333, 315), S(351, 315),
		};

		constexpr Score rook_table[] = {
			S(471, 538), S(488, 533), S(451, 544), S(501, 531),
			S(478, 538), S(474, 542), S(512, 531), S(521, 524),
			S(463, 535), S(494, 532), S(480, 533), S(476, 534),
			S(453, 538), S(462, 534), S(489, 536), S(481, 530),
			S(450, 534), S(471, 531), S(468, 533), S(479, 526),
			S(452, 524), S(473, 525), S(480, 519), S(474, 521),
			S(444, 526), S(474, 517), S(477, 520), S(484, 519),
			S(477, 514), S(469, 522), S(485, 518), S(484, 516),
		};

		constexpr Score queen_table[] = {
			S(931, 980), S(913, 1009), S(922, 1018), S(950, 996),
			S(929, 973), S(874, 1020), S(896, 1028), S(864, 1061),
			S(937, 979), S(922, 1001), S(922, 1009), S(892, 1050),
			S(915, 1015), S(909, 1027), S(903, 1022), S(900, 1036),
			S(932, 988), S(918, 1027), S(925, 1010), S(921, 1027),
			S(927, 997), S(947, 980), S(935, 1004), S(935, 1000),
			S(927, 976), S(942, 962), S(957, 962), S(952, 976),
			S(945, 952), S(936, 957), S(937, 959), S(951, 948),
		};

		constexpr Score king_table[] = {
			S(69, 1), S(105, 26), S(62, 53), S(69, 48),
			S(73, 37), S(111, 49), S(78, 73), S(52, 84),
			S(45, 52), S(97, 66), S(87, 80), S(80, 89),
			S(10, 54), S(76, 75), S(67, 92), S(52, 102),
		};

		constexpr Score passed_pawn[] = {
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
			S(16, 137), S(0, 133), S(5, 107), S(8, 79),
			S(15, 71), S(4, 68), S(8, 45), S(6, 37),
			S(11, 38), S(0, 37), S(0, 22), S(0, 17),
			S(4, 10), S(0, 13), S(0, 2), S(0, 0),
			S(0, 10), S(0, 9), S(0, 0), S(0, 0),
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		};

		constexpr short pawn_shield[] = {
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 3,
			0, 0, 0, 0,
			0, 2, 6, 2,
			3, 3, 1, 0,
		};

		constexpr Score mobility[] = {
			S(0, 0), S(0, 0), S(5, 0), S(7, 2), S(4, 3), S(2, 5),
		};

		constexpr short inner_ring_attack[] = {
			0, 6, 3, 5, 5, 4,
		};

		constexpr short outer_ring_attack[] = {
			0, 1, 5, 1, 1, 3,
		};

		constexpr Score double_pawn_penalty = S(1, 8);
		constexpr Score isolated_pawn_penalty = S(17, 8);
		constexpr Score bishop_pair_bonus = S(40, 43);
		constexpr Score rook_open_file_bonus = S(32, 0);
		constexpr Score rook_semi_open_file_bonus = S(8, 13);
		constexpr Score tempo_bonus = S(19, 19);
		constexpr Score king_full_open_penalty = S(41, 8);
		constexpr Score king_semi_open_penalty = S(7, 0);
		constexpr Score king_adjacent_full_open_penalty = S(5, 10);
		constexpr Score king_adjacent_semi_open_penalty = S(10, 0);
		constexpr Score knight_outpost_bonus = S(38, 14);
		constexpr Score bishop_outpost_bonus = S(45, 0);
		constexpr short virtual_king_m = 3;
		constexpr short virtual_king_b = 1;
		constexpr Score rook_closed_file_penalty = S(14, 1);
		constexpr Score weak_queen_penalty = S(39, 0);
		constexpr Score rook_on_our_passer_file = S(8, 10);
		constexpr Score rook_on_their_passer_file = S(7, 38);
		constexpr Score tall_pawn_penalty = S(10, 32);
		constexpr Score fianchetto_bonus = S(17, 17);
		constexpr short safety_threshold = 8;
		constexpr short opposite_bishops_scaling = 15;
		constexpr Score rook_on_seventh = S(0, 0);
		constexpr Score bishop_behind_pawn_bonus = S(0, 0);
		constexpr Score knight_behind_pawn_bonus = S(0, 0);

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

		struct EvalTrace {
			EvalTrace() {
				clear();
			}
			void clear() {
				memset(psqt, 0, sizeof(psqt));
				memset(passers, 0, sizeof(passers));
				memset(double_pawn_penalty, 0, sizeof(double_pawn_penalty));
				memset(isolated_pawn_penalty, 0, sizeof(isolated_pawn_penalty));
				memset(bishop_pair_bonus, 0, sizeof(bishop_pair_bonus));
				memset(rook_open_file_bonus, 0, sizeof(rook_open_file_bonus));
				memset(rook_semi_open_file_bonus, 0, sizeof(rook_semi_open_file_bonus));
				memset(tempo_bonus, 0, sizeof(tempo_bonus));
				memset(king_full_open_penalty, 0, sizeof(king_full_open_penalty));
				memset(king_semi_open_penalty, 0, sizeof(king_semi_open_penalty));
				memset(king_adjacent_full_open_penalty, 0, sizeof(king_adjacent_full_open_penalty));
				memset(king_adjacent_semi_open_penalty, 0, sizeof(king_adjacent_semi_open_penalty));
				memset(knight_outpost_bonus, 0, sizeof(knight_outpost_bonus));
				memset(bishop_outpost_bonus, 0, sizeof(bishop_outpost_bonus));
				memset(rook_closed_file_penalty, 0, sizeof(rook_closed_file_penalty));
				memset(weak_queen_penalty, 0, sizeof(weak_queen_penalty));
				memset(rook_on_our_passer_file, 0, sizeof(rook_on_our_passer_file));
				memset(rook_on_their_passer_file, 0, sizeof(rook_on_their_passer_file));
				memset(tall_pawn_penalty, 0, sizeof(tall_pawn_penalty));
				memset(fianchetto_bonus, 0, sizeof(fianchetto_bonus));
			}
			int psqt[7][COLOUR_N][SQ_N];
			int passers[COLOUR_N][SQ_N];
			int double_pawn_penalty[COLOUR_N];
			int isolated_pawn_penalty[COLOUR_N];
			int bishop_pair_bonus[COLOUR_N];
			int rook_open_file_bonus[COLOUR_N];
			int rook_semi_open_file_bonus[COLOUR_N];
			int tempo_bonus[COLOUR_N];
			int king_full_open_penalty[COLOUR_N];
			int king_semi_open_penalty[COLOUR_N];
			int king_adjacent_full_open_penalty[COLOUR_N];
			int king_adjacent_semi_open_penalty[COLOUR_N];
			int knight_outpost_bonus[COLOUR_N];
			int bishop_outpost_bonus[COLOUR_N];
			int rook_closed_file_penalty[COLOUR_N];
			int weak_queen_penalty[COLOUR_N];
			int rook_on_our_passer_file[COLOUR_N];
			int rook_on_their_passer_file[COLOUR_N];
			int tall_pawn_penalty[COLOUR_N];
			int fianchetto_bonus[COLOUR_N];
		};

		void init_eval();
		void init_values();
		template<bool TRACE> int evaluate(const Position& pos);
		
		extern EvalTrace T;

	} // namespace Eval

} // namespace Clovis
