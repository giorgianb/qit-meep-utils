#include "Block.hpp"

using namespace meep_utils;

Block::Block(const meep::vec& s, const meep::vec& c, const double e):
    sides {s},
    center {c},
    eps {e} {
}

double Block::epsilon(void) const {
    return eps;
}

bool Block::contains(const meep::vec& p) const {
    return p.x() >= (center.x() - sides.x() / 2)
        && p.x() <= (center.x() + sides.x() / 2)
        && p.y() >= (center.y() - sides.y() / 2)
        && p.y() <= (center.y() + sides.y() / 2)
        && p.z() >= (center.z() - sides.z() / 2)
        && p.z() <= (center.z() + sides.z() / 2);
}
