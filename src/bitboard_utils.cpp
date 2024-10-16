#include <bitboard_utils.h>

void bitboard_utils::print_bitboard(u64 bitboard) {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            u64 square = 1ULL << (rank * 8 + file);

            if (bitboard & square) std::cout << "1 ";
            else std::cout << "0 ";
        }

        std::cout << '\n';
    }
}
