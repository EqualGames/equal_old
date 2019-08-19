/*
 * Copyright 2019 Equal Games
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <cmath>
#include <equal/helper/error.hpp>
#include <equal/helper/math.hpp>

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
