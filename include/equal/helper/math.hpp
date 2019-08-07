#pragma once

/**
 * @defgroup math Math
 * @ingroup helpers
 * @brief Math functions
 */

namespace eq::math {

/**
 * @ingroup math
 * @brief Linearly interpolates between **a** and **b** by **t**
 *
 * The parameter **t** is clamped to the range [0, 1]
 * @li When **t** = 0 returns **a**
 * @li When **t** = 1 return **b**
 * @li When **t** = 0.5 returns the midpoint of **a** and **b**
 *
 * @param a float
 * @param b float
 * @param t float
 * @return float
 */
float lerp(float a, float b, float t);

/**
 * @ingroup math
 * @brief Linearly interpolates between **a** and **b** by **t**
 *
 * The parameter **t** is clamped to the range [0, 1]
 * @li When **t** = 0 returns **a**
 * @li When **t** = 1 return **b**
 * @li When **t** = 0.5 returns the midpoint of **a** and **b**
 *
 * @param a double
 * @param b double
 * @param t double
 * @return double
 */
double lerp(double a, double b, double t);

/**
 * @ingroup math
 * @brief Linearly interpolates between **a** and **b** by **t**
 *
 * The parameter **t** is clamped to the range [0, 1]
 * @li When **t** = 0 returns **a**
 * @li When **t** = 1 return **b**
 * @li When **t** = 0.5 returns the midpoint of **a** and **b**
 *
 * @param a long double
 * @param b long double
 * @param t long double
 * @return long double
 */
long double lerp(long double a, long double b, long double t);

} // namespace eq::math
