#include <cmath>
#include <equal/helper/math.hpp>
#include <equal/helper/error.hpp>

namespace eq::math {

template <typename T>
T lerp(T a, T b, T t) {
  if (t <= 0) {
    return a;
  } else if (t >= 1) {
    return b;
  } else if (std::isfinite(t) && a == b) {
    return a;
  } else if (std::isfinite(t) || (!std::isnan(t) && (b - a) != 0)) {
    return std::fma(t, b, std::fma(-t, a, a));
  }

  EQ_THROW("Invalid values, **t** can't be a **finite** or **NAN** and the diference of **b** and **a** can't be a "
           "**ZERO**");
}

float lerp(float a, float b, float t) { return lerp<float>(a, b, t); }

double lerp(double a, double b, double t) { return lerp<double>(a, b, t); }

long double lerp(long double a, long double b, long double t) { return lerp<long double>(a, b, t); }

} // namespace eq::math
