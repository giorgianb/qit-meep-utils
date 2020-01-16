#include <meep.hpp>

namespace qit_meep_utils {
    class Block {
        private:
            meep::volume volume;
            double eps;
        public:
            Block(const meep::vec& center, const meep::vec& sides, const double epsilon);
            double epsilon(void) const;
            bool contains(const meep::vec& p) const;
    };
}
