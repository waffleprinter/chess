#include "move_gen.h"

std::array<std::array<u64, 64>, 2> move_gen::pawn_attack_lookup = move_gen::generate_pawn_attack_lookup();
std::array<u64, 64> move_gen::knight_lookup = move_gen::generate_knight_lookup();
std::array<u64, 64> move_gen::king_lookup = move_gen::generate_king_lookup();
std::array<std::array<u64, 64>, 8> move_gen::ray_lookup = move_gen::generate_ray_lookup();


u64 move_gen::get_pawn_pushes(board::enum_color color, board::enum_square square, u64 occupied) {
    u64 pawn_position = 1ULL << square;

    u64 single_push_targets = ~occupied;
    u64 double_push_targets = ~occupied;

    if (color == board::enum_color::WHITE) {
        single_push_targets &= bitboard_utils::north_one(pawn_position);
        double_push_targets &= bitboard_utils::north_one(single_push_targets) & (~occupied) & bitboard_utils::rank_4;
    } else {
        single_push_targets &= bitboard_utils::south_one(pawn_position);
        double_push_targets &= bitboard_utils::south_one(single_push_targets) & (~occupied) & bitboard_utils::rank_5;
    }

    return single_push_targets | double_push_targets;
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

        u64 attacks = bitboard_utils::north_north_east_one(knight_position);
        attacks |= bitboard_utils::north_east_east_one(knight_position);
        attacks |= bitboard_utils::south_east_east_one(knight_position);
        attacks |= bitboard_utils::south_south_east_one(knight_position);

        attacks |= bitboard_utils::north_north_west_one(knight_position);
        attacks |= bitboard_utils::north_west_west_one(knight_position);
        attacks |= bitboard_utils::south_west_west_one(knight_position);
        attacks |= bitboard_utils::south_south_west_one(knight_position);

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

std::array<std::array<u64, 64>, 8> move_gen::generate_ray_lookup() {
    std::array<std::array<u64, 64>, 8> lookup = {};

    u64 north = 0x0101010101010100;
    for (int square = 0; square < 64; square++, north <<= 1) {
        lookup[board::enum_direction::north][square] = north;
    }

    u64 _east = 0x00000000000000fe;
    for (int rank = 0; rank < 8; rank++) {
        u64 east = _east << (rank * 8);
        for (int file = 0; file < 8; file++) {
            lookup[board::enum_direction::east][rank * 8 + file] = east;
            east = bitboard_utils::east_one(east);
        }
    }

    u64 south = 0x0080808080808080;
    for (int i = 63; i >= 0; i--, south >>= 1) {
        lookup[board::enum_direction::south][i] = south;
    }

    u64 _west = 0x7f00000000000000;
    for (int rank = 7; rank >= 0; rank--) {
        u64 west = _west >> ((7 - rank) * 8);
        for (int file = 7; file >= 0; file--) {
            lookup[board::enum_direction::west][rank * 8 + file] = west;
            west = bitboard_utils::west_one(west);
        }
    }

    return lookup;
}





