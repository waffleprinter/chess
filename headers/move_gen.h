#ifndef CHESS_MOVE_GEN_H
#define CHESS_MOVE_GEN_H

#include <cstdint>
#include <array>
#include <bitboard_utils.h>

typedef uint64_t u64;

class move_gen {
private:
    static std::array<u64, 64> generate_knight_moves() {
        std::array<u64, 64> lookup = {};
        u64 knight_position = 0x0000000000000001;

        for (int i = 0; i < 64; i++) {
            u64 attacks = bitboard_utils::north_north_east(knight_position);
            attacks |= bitboard_utils::north_east_east(knight_position);
            attacks |= bitboard_utils::south_east_east(knight_position);
            attacks |= bitboard_utils::south_south_east(knight_position);

            attacks |= bitboard_utils::north_north_west(knight_position);
            attacks |= bitboard_utils::north_west_west(knight_position);
            attacks |= bitboard_utils::south_west_west(knight_position);
            attacks |= bitboard_utils::south_south_west(knight_position);

            lookup[i] = attacks;
            knight_position <<= 1;
        }

        return lookup;
    };

public:
    static std::array<u64, 64> knight_lookup;
};

#endif //CHESS_MOVE_GEN_H
