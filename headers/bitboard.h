#ifndef CHESS_BITBOARD_H
#define CHESS_BITBOARD_H

#include <cstdint>
#include <iostream>

#define u64 uint64_t

class bitboard {
private:
    u64 piece_bitboard[14];

public:
    enum enum_piece {
        white        = 0,   // All white pieces
        black        = 1,   // All black pieces
        white_pawn   = 2,
        black_pawn   = 3,
        white_knight = 4,
        black_knight = 5,
        white_bishop = 6,
        black_bishop = 7,
        white_rook   = 8,
        black_rook   = 9,
        white_queen  = 10,
        black_queen  = 11,
        white_king   = 12,
        black_king   = 13
    };

    bitboard();

    void initialize_pieces();
};


#endif //CHESS_BITBOARD_H
