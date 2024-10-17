#include "board.h"

board::board() {
    initialize_pieces();
}

void board::initialize_pieces() {
    piece_bitboard[white] =        0x000000000000ffff;   // All white pieces on A1...H1 and A2...H2
    piece_bitboard[black] =        0xffff000000000000;   // All black pieces on A7...H7 and A8...H8
    piece_bitboard[white_pawn] =   0x000000000000ff00;   // White pawns on A2...H2
    piece_bitboard[black_pawn] =   0x00ff000000000000;   // Black pawns on A7...H7
    piece_bitboard[white_knight] = 0x0000000000000042;   // White knights on B1 and G1
    piece_bitboard[black_knight] = 0x4200000000000000;   // Black knights on B8 and G8
    piece_bitboard[white_bishop] = 0x0000000000000024;   // White bishops on C1 and F1
    piece_bitboard[black_bishop] = 0x2400000000000000;   // Black bishops on C8 and F8
    piece_bitboard[white_rook] =   0x0000000000000081;   // White rooks on A1 and H1
    piece_bitboard[black_rook] =   0x8100000000000000;   // Black rooks on A8 and H8
    piece_bitboard[white_queen] =  0x0000000000000008;   // White queen on D1
    piece_bitboard[black_queen] =  0x0800000000000000;   // Black queen on D8
    piece_bitboard[white_king] =   0x0000000000000010;   // White king on E1
    piece_bitboard[black_king] =   0x1000000000000000;   // Black king on E8

    occupied_bitboard = piece_bitboard[white] | piece_bitboard[black];  // All pieces
}
