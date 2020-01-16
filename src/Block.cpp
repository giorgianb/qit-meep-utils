#include "Block.hpp"

using namespace qit_meep_utils;

Block::Block(const meep::volume& volume, const double epsilon):
    _volume {volume},
    _epsilon {epsilon} {
}

meep::volume Block::volume(void) const {
    return _volume;
}

bool Block::contains(const meep::vec& p) const {
    return _volume.contains(p);
}

Block Block::construct(
        const meep::vec& center, 
        const meep::vec& sides, 
        const double epsilon
        ) {
    return Block {{center - sides / 2, center + sides / 2}, epsilon};
}


