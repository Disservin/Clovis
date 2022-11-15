#pragma once

#include <cstdint>
#include <vector>

#include "evaluate.h"
#include "types.h"

namespace Clovis {

    constexpr size_t pt_size = 131072;

    enum HashFlag : uint8_t {
        HASH_NONE,
        HASH_ALPHA,
        HASH_BETA,
        HASH_EXACT,
    };

	struct TTEntry {
        TTEntry(Key key = 0ULL, int depth = 0, int eval = 0, HashFlag flags = HASH_NONE, Move move = MOVE_NONE) : key(key), depth(depth), flags(flags), eval(eval), move(move) {};
        void operator=(const TTEntry& rhs){
            key = rhs.key;
            depth = rhs.depth;
            eval = rhs.eval;
            flags = rhs.flags;
            move = rhs.move;
        };
        Key key;        // 8 bytes
        uint8_t depth;  // 1 byte
        uint8_t flags;  // 1 byte
        short eval;     // 2 bytes
        Move move;      // 4 bytes
	};

    struct Bucket {
    public:
        TTEntry e1;
        TTEntry e2;
    };

    struct PTEntry {
        PTEntry(Key k = 0ULL, Score s = Score(0,0)) {
            key = k;
            eval = s;
        }
        void operator=(const PTEntry& rhs) {
            key = rhs.key;
            eval = rhs.eval;
        }
        Key key;
        Score eval;
    };

	class TTable {
    public:
        TTable();
        void resize(size_t mb);
        void clear();
        void new_entry(Key key, int depth, int eval, HashFlag flags, Move move);
        TTEntry* probe(Key key);
        void new_pawn_entry(Key key, Score score) { pt[pawn_hash_index(key)] = PTEntry(key, score); }
        PTEntry* probe_pawn(Key key);
        ~TTable();
    private:
        int hash_index(Key key) const;
        int pawn_hash_index(Key key) const;
        Bucket* ht = nullptr;
        PTEntry* pt = nullptr;
        size_t tt_size;
    };

    inline int TTable::hash_index(Key key) const {
        return key & (tt_size - 1ULL);
    }

    inline int TTable::pawn_hash_index(Key key) const {
        return key & (pt_size - 1ULL);
    }

    extern TTable tt;

} // Clovis