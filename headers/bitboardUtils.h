#ifndef CHESS_BITBOARDUTILS_H
#define CHESS_BITBOARDUTILS_H

#include <cstdint>

#define U64 uint64_t

class bitboardUtils {
public:
    const static U64 notAFile = 0xfefefefefefefefe; // ~0x0101010101010101
    const static U64 notHFile = 0x7f7f7f7f7f7f7f7f; // ~0x8080808080808080

    static U64 nortOne(U64 bitboard) {return bitboard << 8;};
    static U64 soutOne(U64 bitboard) {return bitboard >> 8;};

    // Mask out A file to avoid wrap around from H file
    static U64 eastOne(U64 bitboard) {return (bitboard << 1) & notAFile;};
    static U64 noEaOne(U64 bitboard) {return (bitboard << 9) & notAFile;};
    static U64 soEaOne(U64 bitboard) {return (bitboard >> 7) & notAFile;};

    // Mask out H file to avoid wrap around from A file
    static U64 westOne(U64 bitboard) {return (bitboard >> 1) & notHFile;};
    static U64 noWeOne(U64 bitboard) {return (bitboard << 7) & notHFile;};
    static U64 soWeOne(U64 bitboard) {return (bitboard >> 9) & notHFile;};
};


#endif //CHESS_BITBOARDUTILS_H
