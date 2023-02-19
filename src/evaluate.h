#pragma once

#include "position.h"
#include "tt.h"

namespace Clovis {

	struct Position;

	namespace Eval {
	
#define S(mg, eg) Score(mg, eg)

        constexpr Score pawn_table[] = {
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
			S(102, 281), S(145, 259), S(153, 231), S(161, 219),
			S(78, 90), S(97, 87), S(119, 82), S(113, 82),
			S(62, 80), S(81, 75), S(84, 75), S(95, 68),
			S(54, 72), S(64, 72), S(79, 69), S(90, 68),
			S(60, 66), S(73, 66), S(78, 70), S(76, 76),
			S(56, 67), S(78, 66), S(73, 78), S(68, 82),
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		};

		constexpr Score knight_table[] = {
			S(180, 186), S(246, 205), S(225, 231), S(303, 218),
			S(271, 214), S(296, 230), S(376, 212), S(323, 238),
			S(308, 212), S(350, 223), S(340, 244), S(353, 241),
			S(327, 224), S(327, 241), S(335, 253), S(334, 259),
			S(318, 224), S(333, 238), S(337, 250), S(337, 254),
			S(313, 222), S(335, 230), S(337, 235), S(341, 248),
			S(313, 206), S(307, 224), S(326, 231), S(335, 234),
			S(289, 203), S(317, 195), S(303, 222), S(319, 223),
		};

		constexpr Score bishop_table[] = {
			S(313, 228), S(330, 233), S(330, 230), S(327, 236),
			S(315, 232), S(346, 221), S(344, 235), S(343, 236),
			S(322, 239), S(343, 238), S(353, 239), S(342, 245),
			S(322, 239), S(328, 239), S(331, 245), S(347, 244),
		};

		constexpr Score rook_table[] = {
			S(439, 432), S(432, 440), S(442, 437), S(442, 436),
			S(414, 444), S(432, 439), S(439, 438), S(447, 433),
			S(418, 442), S(438, 441), S(439, 437), S(435, 438),
			S(417, 446), S(433, 441), S(439, 444), S(440, 438),
		};

		constexpr Score queen_table[] = {
			S(887, 798), S(870, 823), S(871, 836), S(890, 818),
			S(885, 798), S(837, 838), S(859, 841), S(829, 870),
			S(898, 797), S(886, 816), S(884, 823), S(858, 856),
			S(881, 824), S(873, 837), S(872, 829), S(863, 845),
			S(897, 795), S(883, 832), S(887, 822), S(887, 832),
			S(890, 808), S(909, 793), S(898, 814), S(898, 809),
			S(890, 792), S(905, 777), S(917, 778), S(910, 794),
			S(906, 771), S(898, 775), S(897, 779), S(911, 767),
		};

		constexpr Score king_table[] = {
			S(66, 18), S(104, 37), S(70, 61), S(76, 58),
			S(75, 43), S(105, 55), S(77, 76), S(58, 86),
			S(49, 56), S(91, 70), S(80, 83), S(74, 91),
			S(18, 59), S(66, 78), S(56, 93), S(43, 102),
		};

		constexpr Score passed_pawn[] = {
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
			S(8, 4), S(5, 4), S(6, 3), S(7, 3),
			S(10, 121), S(0, 113), S(11, 88), S(4, 67),
			S(13, 61), S(4, 58), S(8, 39), S(7, 31),
			S(10, 34), S(0, 32), S(0, 18), S(0, 14),
			S(6, 11), S(0, 13), S(0, 3), S(0, 0),
			S(0, 11), S(3, 8), S(5, 0), S(0, 0),
			S(0, 0), S(0, 0), S(0, 0), S(0, 0),
		};

		constexpr Score mobility[] = {
			S(0, 0), S(0, 0), S(5, 0), S(4, 2), S(4, 2), S(2, 4), S(0, 0),
		};

		constexpr Score double_pawn_penalty = S(0, 6);
		constexpr Score isolated_pawn_penalty = S(15, 7);
		constexpr Score bishop_pair_bonus = S(23, 42);
		constexpr Score rook_open_file_bonus = S(25, 0);
		constexpr Score rook_semi_open_file_bonus = S(2, 7);
		constexpr Score rook_closed_file_penalty = S(15, 5);
		constexpr Score tempo_bonus = S(17, 15);
		constexpr Score king_full_open_penalty = S(38, 7);
		constexpr Score king_semi_open_penalty = S(11, 0);
		constexpr Score king_adjacent_full_open_penalty = S(7, 8);
		constexpr Score king_adjacent_semi_open_penalty = S(15, 0);
		constexpr Score knight_outpost_bonus = S(35, 12);
		constexpr Score bishop_outpost_bonus = S(38, 0);
		constexpr Score weak_queen_penalty = S(32, 1);
		constexpr Score rook_on_our_passer_file = S(7, 5);
		constexpr Score rook_on_their_passer_file = S(0, 43);
		constexpr Score tall_pawn_penalty = S(12, 24);
		constexpr Score fianchetto_bonus = S(19, 12);
		constexpr Score rook_on_seventh = S(0, 25);

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
			0, 38, 21, 37, 37, 25, 0,
		};

		constexpr short outer_ring_attack[] = {
			0, 4, 35, 15, 15, 25, 0,
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
		template<bool TRACE> int evaluate(const Position& pos);
		
		extern int T[TI_N][PHASE_N];

	} // namespace Eval

} // namespace Clovis
