#include "GaussianBeam.hpp"
#include <cmath>

using namespace qit_meep_utils;
constexpr double pi {4 * std::atan(1)};

GaussianBeam::GaussianBeam(
        const meep::src_time& source,
        const meep::component& comp,
        const meep::vec& p,
        const double sr,
        const meep::vec& d,
        const double sig,
        const std::complex<double> a
        ):
    v {p - meep::vec(sr, sr, sr) * 2.0, p + meep::vec(sr, sr, sr) * 2.0},
    s {source},
    c {comp},
    pos {p},
    k {d},
    sigma {sig},
    amp {a} {
}

//void fields::add_volume_source(component c, const src_time &src, const volume &where_,
//                                complex<double> A(const vec &), complex<double> amp) {

static thread_local meep::vec g_pos;
static thread_local meep::vec g_k;
static thread_local double g_source_radius;
static thread_local double g_sigma;

std::complex<double> amp_func(const meep::vec& p);


void GaussianBeam::add_to_fields(meep::fields& f) const {
    g_pos = this->pos;
    g_k = this->k;
    g_source_radius = this->source_radius;
    g_sigma = this->sigma;

    f.add_volume_source(c, s, v, amp_func, amp);
}

std::complex<double> amp_func(const meep::vec& p) {
    using namespace std::complex_literals;

    const meep::vec& d {p - g_pos};
    if ((d & d) > g_source_radius * g_source_radius)
        return 0.0i;

    return std::exp(2.0i * pi * (g_k & d) - (d & d)/(2*g_sigma * g_sigma));
}


