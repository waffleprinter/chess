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

public:
    static u64 get_knight_attacks(u64 knight_square, u64 occupied) { return knight_lookup[knight_square] & ~occupied; };
    static u64 get_king_attacks(u64 king_square, u64 occupied) { return king_lookup[king_square] & ~occupied; };
};

#endif //CHESS_MOVE_GEN_H
