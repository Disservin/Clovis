#pragma once

#include <cstdint>
#include <memory>

#include "types.h"

namespace Clovis {

	constexpr size_t pt_size = 131072;

	struct TTEntry {
		constexpr TTEntry() = default;
		TTEntry(const Key k, const uint8_t d, const uint8_t f, const short e, const Move m) : key(k), depth(d), flags(f), eval(e), move(m) {}

		Key key{ 0ULL };    // 8 bytes
		uint8_t depth{ 0 }; // 1 bytes
		uint8_t flags{ 0 }; // 1 bytes
		short eval{ 0 };    // 2 bytes
		Move move{ 0 };     // 4 bytes
	};

	struct TTBucket {
		TTEntry& operator[](const bool index) { return index ? e2 : e1; }

		TTEntry e1, e2;
	};
	
	struct PTEntry {
		constexpr PTEntry() = default;

		Score score;
		Key key{ 0ULL };
		Bitboard pawn_attacks[COLOUR_N]{ 0ULL }, passers[COLOUR_N]{ 0ULL }, potential_pawn_attacks[COLOUR_N]{ 0ULL };
		Square ksq[COLOUR_N]{ SQ_NONE };
		short weight[COLOUR_N]{ 0 };
	};

	class TTable {

	public:
		TTable();
		void resize(size_t mb);
		void clear();

		void new_entry(Key key, int depth, int eval, HashFlag flags, Move move);
		void new_pawn_entry(const PTEntry& pte);
		PTEntry probe_pawn(Key key);
		TTEntry probe(Key key);

	private:
		[[nodiscard]] int hash_index(Key key) const;
		[[nodiscard]] int pawn_hash_index(Key key) const;
		std::unique_ptr<TTBucket[]> ht;
		std::unique_ptr<PTEntry[]> pt;
		size_t tt_size;
	};

	inline int TTable::hash_index(const Key key) const {
		return static_cast<int>(key & (tt_size - 1ULL));
	}

	inline int TTable::pawn_hash_index(const Key key) const {
		return static_cast<int>(key & (pt_size - 1ULL));
	}

	// probe the pawn table to see if an entry exists
	inline PTEntry TTable::probe_pawn(const Key key) {
		return pt[pawn_hash_index(key)];
	}

	inline void TTable::new_pawn_entry(const PTEntry& pte) { 
		pt[pawn_hash_index(pte.key)] = pte; 
	}

	extern TTable tt;

} // Clovis
