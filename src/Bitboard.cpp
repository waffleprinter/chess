#include "Bitboard.h"

Bitboard::Bitboard() {
    initializePieces();
}

void Bitboard::initializePieces() {
    whitePawns = 0x000000000000ff00;    // Pawns on A2...H2
    whiteKnights = 0x0000000000000042;  // Knights on B1 and G1
    whiteBishops = 0x0000000000000024;  // Bishops on C1 and F1
    whiteRooks = 0x0000000000000081;    // Rooks on A1 and H1
    whiteQueens = 0x0000000000000008;   // Queen on D1
    whiteKing = 0x0000000000000010;     // King on E1

    blackPawns = 0x00ff000000000000;    // Pawns on A7...H7
    blackKnights = 0x4200000000000000;  // Knights on B8 and G8
    blackBishops = 0x2400000000000000;  // Bishops on C8 and F8
    blackRooks = 0x8100000000000000;    // Rooks on A8 and H8
    blackQueens = 0x0800000000000000;   // Queen on D8
    blackKing = 0x1000000000000000;     // King on E8

    // POSSIBLY UNNECESSARY
    pieces[0] = &whitePawns;
    pieces[1] = &whiteKnights;
    pieces[2] = &whiteBishops;
    pieces[3] = &whiteRooks;
    pieces[4] = &whiteQueens;
    pieces[5] = &whiteKing;
    pieces[6] = &blackPawns;
    pieces[7] = &blackKnights;
    pieces[8] = &blackBishops;
    pieces[9] = &blackRooks;
    pieces[10] = &blackQueens;
    pieces[11] = &blackKing;
}

void Bitboard::printPieces() {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            U64 square = 1ULL << (rank * 8 + file);

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
