#include "move_gen.h"

std::array<u64, 64> move_gen::knight_lookup = move_gen::generate_knight_lookup();
std::array<u64, 64> move_gen::king_lookup = move_gen::generate_king_lookup();

std::array<u64, 64> move_gen::generate_knight_lookup() {
    std::array<u64, 64> lookup = {};

    for (int i = 0; i < 64; i++) {
        u64 knight_position = 1ULL << i;

        u64 attacks = bitboard_utils::north_north_east(knight_position);
        attacks |= bitboard_utils::north_east_east(knight_position);
        attacks |= bitboard_utils::south_east_east(knight_position);
        attacks |= bitboard_utils::south_south_east(knight_position);

        attacks |= bitboard_utils::north_north_west(knight_position);
        attacks |= bitboard_utils::north_west_west(knight_position);
        attacks |= bitboard_utils::south_west_west(knight_position);
        attacks |= bitboard_utils::south_south_west(knight_position);

        lookup[i] = attacks;
    }

    return lookup;
};

std::array<u64, 64> move_gen::generate_king_lookup() {
    std::array<u64, 64> lookup = {};

    for (int i = 0; i < 64; i++) {
        u64 king_position = 1ULL << i;

        u64 attacks = bitboard_utils::north_one(king_position);
        attacks |= bitboard_utils::north_east_one(king_position);
        attacks |= bitboard_utils::east_one(king_position);
        attacks |= bitboard_utils::south_east_one(king_position);

        attacks |= bitboard_utils::south_one(king_position);
        attacks |= bitboard_utils::south_west_one(king_position);
        attacks |= bitboard_utils::west_one(king_position);
        attacks |= bitboard_utils::north_west_one(king_position);

        lookup[i] = attacks;
    }

    return lookup;
};