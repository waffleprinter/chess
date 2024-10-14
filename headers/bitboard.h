#ifndef CHESS_BITBOARD_H
#define CHESS_BITBOARD_H

#include <cstdint>
#include <iostream>

#define u64 uint64_t

class bitboard {
private:
    u64 white_pawns;
    u64 white_knights;
    u64 white_bishops;
    u64 white_rooks;
    u64 white_queens;
    u64 white_king;

    u64 black_pawns;
    u64 black_knights;
    u64 black_bishops;
    u64 black_rooks;
    u64 black_queens;
    u64 black_king;

    // POSSIBLY UNNECESSARY
    u64 *pieces[12];

public:
    bitboard();

    void initialize_pieces();
    void print_bitboard();
};


#endif //CHESS_BITBOARD_H
