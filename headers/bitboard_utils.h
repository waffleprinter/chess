#ifndef CHESS_BITBOARD_UTILS_H
#define CHESS_BITBOARD_UTILS_H

#include <cstdint>

#define u64 uint64_t

class bitboard_utils {
public:
    const static u64 not_A_file = 0xfefefefefefefefe; // ~0x0101010101010101
    const static u64 not_H_file = 0x7f7f7f7f7f7f7f7f; // ~0x8080808080808080

    static u64 north_one(u64 bitboard) {return bitboard << 8;};
    static u64 south_one(u64 bitboard) {return bitboard >> 8;};

    // Mask out A file to avoid wrap around from H file
    static u64 east_one(u64 bitboard) {return (bitboard << 1) & not_A_file;};
    static u64 north_east_one(u64 bitboard) {return (bitboard << 9) & not_A_file;};
    static u64 south_east_one(u64 bitboard) {return (bitboard >> 7) & not_A_file;};

    // Mask out H file to avoid wrap around from A file
    static u64 west_one(u64 bitboard) {return (bitboard >> 1) & not_H_file;};
    static u64 north_west_one(u64 bitboard) {return (bitboard << 7) & not_H_file;};
    static u64 south_west_one(u64 bitboard) {return (bitboard >> 9) & not_H_file;};
};


#endif //CHESS_BITBOARD_UTILS_H
