#ifndef CHESS_MOVE_GEN_H
#define CHESS_MOVE_GEN_H

#include <cstdint>
#include <array>
#include <bitboard.h>
#include <bitboard_utils.h>

typedef uint64_t u64;

class move_gen {
private:
    static std::array<u64, 64> knight_lookup;
    static std::array<u64, 64> king_lookup;

    static std::array<u64, 64> generate_knight_lookup();
    static std::array<u64, 64> generate_king_lookup();
};

#endif //CHESS_MOVE_GEN_H
