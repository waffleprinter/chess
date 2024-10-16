#include "move_gen.h"

std::array<u64, 64> move_gen::knight_lookup = move_gen::generate_knight_moves();
