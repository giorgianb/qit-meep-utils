#include "GaussianBeam.hpp"
#include <cmath>

using namespace qit_meep_utils;
constexpr double pi {4 * std::atan(1)};

GaussianBeam::GaussianBeam(
        const meep::src_time& source,
        const meep::vec& position, 
        const double radius,
        const meep::vec& k, 
        const double sigma,
        const meep::component& component,
        const std::complex<double>& amplitude
        ):
    _volume {
        position - meep::vec(radius, radius, radius) * 2.0, 
        position + meep::vec(radius, radius, radius) * 2.0
    },
    _source {source},
    _position {position},
    _radius {radius},
    _k {k},
    _sigma {sigma},
    _component {component},
    _amplitude {amplitude} {
}

meep::src_time GaussianBeam::source(void) const {
    return _source;
}

meep::vec GaussianBeam::position(void) const {
    return _position;
}

meep::vec GaussianBeam::k(void) const {
    return _k;
}

static thread_local const GaussianBeam* beam;
std::complex<double> amplitude_function(const meep::vec& p);

void GaussianBeam::add_to_fields(meep::fields& f) const {
    beam = this;

    f.add_volume_source(_component, _source, _volume, amplitude_function, _amplitude);
}

std::complex<double> amplitude_function(const meep::vec& p) {
    using namespace std::complex_literals;

    const meep::vec& d {p - beam->position()};
    if ((d & d) > beam->radius() * beam->radius())
        return 0.0i;

    return std::exp(2.0i * pi * (beam->k() & d) - (d & d)/(2 * beam->sigma() * beam->sigma()));
}
