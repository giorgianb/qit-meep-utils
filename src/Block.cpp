#include "Block.hpp"

using namespace qit_meep_utils;

Block::Block(const meep::vec& c, const meep::vec& s, const double e):
    volume {c - s / 2, c + s / 2},
    eps {e} {
}

double Block::epsilon(void) const {
    return eps;
}

bool Block::contains(const meep::vec& p) const {
    return volume.contains(p);
}
