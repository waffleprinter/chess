#ifndef CHESS_MOVE_GEN_H
#define CHESS_MOVE_GEN_H

#include <cstdint>
#include <array>
#include <board.h>
#include <bitboard_utils.h>

typedef uint64_t u64;

class move_gen {
private:
    static std::array<std::array<u64, 64>, 2> pawn_attack_lookup;
    static std::array<u64, 64> knight_lookup;
    static std::array<u64, 64> king_lookup;

    static std::array<std::array<u64, 64>, 2> generate_pawn_attack_lookup();
    static std::array<u64, 64> generate_knight_lookup();
    static std::array<u64, 64> generate_king_lookup();

public:
    static u64 get_pawn_pushes(board::enum_color color, board::enum_square square, u64 occupied);

    static u64 get_pawn_attacks(board::enum_color color, board::enum_square square, u64 opponent_pieces) {return pawn_attack_lookup[color][square] & opponent_pieces;}
    static u64 get_knight_attacks(board::enum_square square, u64 allied_pieces) {return knight_lookup[square] & ~allied_pieces;}
    static u64 get_king_attacks(board::enum_square square, u64 allied_pieces) {return king_lookup[square] & ~allied_pieces;}
};

#endif //CHESS_MOVE_GEN_H
