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
