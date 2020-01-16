#ifndef QIT_MEEP_UTILS_GAUSSIAN_BEAM_INCLUDE
#define QIT_MEEP_UTILS_GAUSSIAN_BEAM_INCLUDE
#include <meep.hpp>
#include <complex>

namespace qit_meep_utils {
    class GaussianBeam {
        private:
            meep::volume _volume;
            meep::src_time _source;
            meep::vec _position; 
            double _radius;
            meep::vec _k; // direction of propogation
            double _sigma;
            meep::component _component;
            std::complex<double> _amplitude;
        public:
            GaussianBeam(
                    const meep::src_time& source,
                    const meep::vec& position, 
                    const double radius,
                    const meep::vec& k, 
                    const double sigma,
                    const meep::component& component,
                    const std::complex<double>& amplitude
                    );

            meep::src_time source(void) const;
            meep::vec position(void) const;
            constexpr double radius(void) const;
            meep::vec k(void) const;
            constexpr double sigma(void) const;
            constexpr meep::component component(void) const;
            constexpr std::complex<double> amplitude(void) const;

            void add_to_fields(meep::fields& f) const;
    };

    constexpr double GaussianBeam::radius(void) const {
        return _radius;
    }

    constexpr double GaussianBeam::sigma(void) const {
        return _sigma;
    }

    constexpr meep::component GaussianBeam::component(void) const {
        return _component;
    }

    constexpr std::complex<double> GaussianBeam::amplitude(void) const {
        return _amplitude;
    }
}
#endif

