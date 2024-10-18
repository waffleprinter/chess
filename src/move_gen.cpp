#include "move_gen.h"

std::array<std::array<u64, 64>, 2> move_gen::pawn_push_lookup = move_gen::generate_pawn_push_lookup();
std::array<std::array<u64, 64>, 2> move_gen::pawn_attack_lookup = move_gen::generate_pawn_attack_lookup();
std::array<u64, 64> move_gen::knight_lookup = move_gen::generate_knight_lookup();
std::array<u64, 64> move_gen::king_lookup = move_gen::generate_king_lookup();

std::array<std::array<u64, 64>, 2> move_gen::generate_pawn_push_lookup() {
    std::array<u64, 64> white_lookup = {};

    for (int i = 0; i < 64; i++) {
        u64 white_pawn_position = 1ULL << i;

        u64 pushes = bitboard_utils::north_one(white_pawn_position);

        bool has_not_moved = ((1ULL << 8) <= white_pawn_position) && (white_pawn_position <= (1ULL << 15));
        if (has_not_moved)
            pushes |= bitboard_utils::north_one(pushes);

        white_lookup[i] = pushes;
    }

    std::array<u64, 64> black_lookup = {};

    for (int i = 0; i < 64; i++) {
        u64 black_pawn_position = 1ULL << i;

        u64 pushes = bitboard_utils::south_one(black_pawn_position);

        bool has_not_moved = ((1ULL << 48) <= black_pawn_position) && (black_pawn_position <= (1ULL << 55));
        if (has_not_moved)
            pushes |= bitboard_utils::south_one(pushes);

        black_lookup[i] = pushes;
    }

    std::array<std::array<u64, 64>, 2> lookup = {white_lookup, black_lookup};

    return lookup;
}

std::array<std::array<u64, 64>, 2> move_gen::generate_pawn_attack_lookup() {
    std::array<u64, 64> white_lookup = {};

    for (int i = 0; i < 64; i++) {
        u64 white_pawn_position = 1ULL << i;

        u64 attacks = bitboard_utils::north_west_one(white_pawn_position);
        attacks |= bitboard_utils::north_east_one(white_pawn_position);

        white_lookup[i] = attacks;
    }

    std::array<u64, 64> black_lookup = {};

    for (int i = 0; i < 64; i++) {
        u64 black_pawn_position = 1ULL << i;

        u64 attacks = bitboard_utils::south_west_one(black_pawn_position);
        attacks |= bitboard_utils::south_east_one(black_pawn_position);

        black_lookup[i] = attacks;
    }

    std::array<std::array<u64, 64>, 2> lookup = {white_lookup, black_lookup};

    return lookup;
};

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
}


