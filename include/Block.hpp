#include <meep.hpp>

namespace meep_utils {
    class Block {
        private:
            meep::vec sides;
            meep::vec center;
            double eps;
        public:
            Block(const meep::vec& sides, const meep::vec& center, const double epsilon);
            double epsilon(void) const;
            bool contains(const meep::vec& p) const;
    };
}
