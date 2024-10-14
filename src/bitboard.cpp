#include "bitboard.h"

bitboard::bitboard() {
    initialize_pieces();
}

void bitboard::initialize_pieces() {
    white_pawns = 0x000000000000ff00;    // Pawns on A2...H2
    white_knights = 0x0000000000000042;  // Knights on B1 and G1
    white_bishops = 0x0000000000000024;  // Bishops on C1 and F1
    white_rooks = 0x0000000000000081;    // Rooks on A1 and H1
    white_queens = 0x0000000000000008;   // Queen on D1
    white_king = 0x0000000000000010;     // King on E1

    black_pawns = 0x00ff000000000000;    // Pawns on A7...H7
    black_knights = 0x4200000000000000;  // Knights on B8 and G8
    black_bishops = 0x2400000000000000;  // Bishops on C8 and F8
    black_rooks = 0x8100000000000000;    // Rooks on A8 and H8
    black_queens = 0x0800000000000000;   // Queen on D8
    black_king = 0x1000000000000000;     // King on E8

    // POSSIBLY UNNECESSARY
    pieces[0] = &white_pawns;
    pieces[1] = &white_knights;
    pieces[2] = &white_bishops;
    pieces[3] = &white_rooks;
    pieces[4] = &white_queens;
    pieces[5] = &white_king;
    pieces[6] = &black_pawns;
    pieces[7] = &black_knights;
    pieces[8] = &black_bishops;
    pieces[9] = &black_rooks;
    pieces[10] = &black_queens;
    pieces[11] = &black_king;
}

void bitboard::print_bitboard() {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            u64 square = 1ULL << (rank * 8 + file);

            char pieceChar = '.';

            if (*pieces[0] & square) pieceChar = 'P';        // White Pawn
            else if (*pieces[1] & square) pieceChar = 'N';   // White Knight
            else if (*pieces[2] & square) pieceChar = 'B';   // White Bishop
            else if (*pieces[3] & square) pieceChar = 'R';   // White Rook
            else if (*pieces[4] & square) pieceChar = 'Q';   // White Queen
            else if (*pieces[5] & square) pieceChar = 'K';   // White King
            else if (*pieces[6] & square) pieceChar = 'p';   // Black Pawn
            else if (*pieces[7] & square) pieceChar = 'n';   // Black Knight
            else if (*pieces[8] & square) pieceChar = 'b';   // Black Bishop
            else if (*pieces[9] & square) pieceChar = 'r';   // Black Rook
            else if (*pieces[10] & square) pieceChar = 'q';  // Black Queen
            else if (*pieces[11] & square) pieceChar = 'k';  // Black King

            std::cout << pieceChar << ' ';
        }
        std::cout << "\n";
    }
}
