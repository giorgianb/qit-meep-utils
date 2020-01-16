#include <meep.hpp>
#include <complex>

namespace qit_meep_utils {
    class GaussianBeam {
        private:
            meep::volume v;
            meep::src_time s;
            meep::component c;
            meep::vec pos; // origin
            meep::vec k; // direction of propogation
            double source_radius;
            double sigma;
            std::complex<double> amp;
        public:
            GaussianBeam(
                    const meep::src_time& source,
                    const meep::component& component,
                    const meep::vec& position, 
                    const double source_radius,
                    const meep::vec& dir, 
                    const double sigma,
                    const std::complex<double> amp
                    );
            void add_to_fields(meep::fields& f) const;
    };
}
