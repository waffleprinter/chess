#ifndef CHESS_MOVE_GEN_H
#define CHESS_MOVE_GEN_H

#include <cstdint>
#include <array>
#include <board.h>
#include <bitboard_utils.h>

typedef uint64_t u64;

class move_gen {
private:
    static std::array<std::array<u64, 64>, 2> pawn_push_lookup;
    static std::array<std::array<u64, 64>, 2> pawn_attack_lookup;
    static std::array<u64, 64> knight_lookup;
    static std::array<u64, 64> king_lookup;

    static std::array<std::array<u64, 64>, 2> generate_pawn_push_lookup();
    static std::array<std::array<u64, 64>, 2> generate_pawn_attack_lookup();
    static std::array<u64, 64> generate_knight_lookup();
    static std::array<u64, 64> generate_king_lookup();

public:
    static u64 get_pawn_pushes(board::enum_color color, board::square square) {return pawn_push_lookup[color][square];}
    static u64 get_pawn_attacks(board::enum_color color, board::square square) {return pawn_attack_lookup[color][square];} // Does not include en passant
    static u64 get_knight_attacks(board::square square) {return knight_lookup[square];}
    static u64 get_king_attacks(board::square square) {return king_lookup[square];}
};

#endif //CHESS_MOVE_GEN_H
