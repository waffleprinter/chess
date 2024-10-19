#ifndef CHESS_BITBOARD_UTILS_H
#define CHESS_BITBOARD_UTILS_H

#include <cstdint>
#include <iostream>

typedef uint64_t u64;

class bitboard_utils {
public:
    // Files
    const static u64 not_A_file = 0xfefefefefefefefe;  // ~0x0101010101010101
    const static u64 not_H_file = 0x7f7f7f7f7f7f7f7f;  // ~0x8080808080808080
    const static u64 not_AB_file = 0xfcfcfcfcfcfcfcfc; // ~0x0303030303030303
    const static u64 not_GH_file = 0x3f3f3f3f3f3f3f3f; // ~0xc0c0c0c0c0c0c0c0

    // Ranks
    const static u64 rank_4 = 0x00000000ff000000;
    const static u64 rank_5 = 0x000000ff00000000;

    // Cardinal directions
    static u64 north_one(u64 bitboard) {return bitboard << 8;}
    static u64 south_one(u64 bitboard) {return bitboard >> 8;}
    static u64 east_one(u64 bitboard)  {return (bitboard << 1) & not_A_file;}
    static u64 west_one(u64 bitboard)  {return (bitboard >> 1) & not_H_file;}

    // Diagonals
    static u64 north_east_one(u64 bitboard) {return (bitboard << 9) & not_A_file;}
    static u64 south_east_one(u64 bitboard) {return (bitboard >> 7) & not_A_file;}
    static u64 north_west_one(u64 bitboard) {return (bitboard << 7) & not_H_file;}
    static u64 south_west_one(u64 bitboard) {return (bitboard >> 9) & not_H_file;}

    // Knight moves
    static u64 north_north_east_one(u64 bitboard) {return (bitboard << 17) & not_A_file;}
    static u64 north_east_east_one(u64 bitboard)  {return (bitboard << 10) & not_AB_file;}
    static u64 south_east_east_one(u64 bitboard)  {return (bitboard >> 6) & not_AB_file;}
    static u64 south_south_east_one(u64 bitboard) {return (bitboard >> 15) & not_A_file;}
    static u64 north_north_west_one(u64 bitboard) {return (bitboard << 15) & not_H_file;}
    static u64 north_west_west_one(u64 bitboard)  {return (bitboard << 6) & not_GH_file;}
    static u64 south_west_west_one(u64 bitboard)  {return (bitboard >> 10) & not_GH_file;}
    static u64 south_south_west_one(u64 bitboard) {return (bitboard >> 17) & not_H_file;}

    static void print_bitboard(u64 bitboard);
};


#endif //CHESS_BITBOARD_UTILS_H
