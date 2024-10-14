#ifndef CHESS_BITBOARD_H
#define CHESS_BITBOARD_H

#include <cstdint>
#include <iostream>

#define U64 uint64_t

class Bitboard {
private:
    U64 whitePawns;
    U64 whiteKnights;
    U64 whiteBishops;
    U64 whiteRooks;
    U64 whiteQueens;
    U64 whiteKing;

    U64 blackPawns;
    U64 blackKnights;
    U64 blackBishops;
    U64 blackRooks;
    U64 blackQueens;
    U64 blackKing;

    // POSSIBLY UNNECESSARY
    U64 *pieces[12];

public:
    Bitboard();

    void initializePieces();
    void printPieces();
};


#endif //CHESS_BITBOARD_H
