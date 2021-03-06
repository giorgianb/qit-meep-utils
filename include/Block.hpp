#ifndef QIT_MEEP_UTILS_BLOCK_INCLUDE
#define QIT_MEEP_UTILS_BLOCK_INCLUDE
#include <meep.hpp>

namespace qit_meep_utils {
    class Block {
        private:
            meep::volume _volume;
            double _epsilon;
        public:
            Block(const meep::volume& volume, const double epsilon);

            meep::volume volume(void) const;
            constexpr double epsilon(void) const;

            bool contains(const meep::vec& p) const;

            static Block construct(
                    const meep::vec& center, 
                    const meep::vec& sides, 
                    const double epsilon
                    );
    };

    constexpr double Block::epsilon(void) const {
        return _epsilon;
    }
}
#endif

