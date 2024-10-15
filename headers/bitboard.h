#ifndef CHESS_BITBOARD_H
#define CHESS_BITBOARD_H

#include <cstdint>
#include <iostream>

#define u64 uint64_t

class bitboard {
private:
    u64 piece_bitboard[14]{};
    u64 occupied_bitboard{};

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

    enum square {
        a1, b1, c1, d1, e1, f1, g1, h1,
        a2, b2, c2, d2, e2, f2, g2, h2,
        a3, b3, c3, d3, e3, f3, g3, h3,
        a4, b4, c4, d4, e4, f4, g4, h4,
        a5, b5, c5, d5, e5, f5, g5, h5,
        a6, b6, c6, d6, e6, f6, g6, h6,
        a7, b7, c7, d7, e7, f7, g7, h7,
        a8, b8, c8, d8, e8, f8, g8, h8
    };



    bitboard();

    void initialize_pieces();
};


#endif //CHESS_BITBOARD_H
