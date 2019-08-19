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

#include <equal/core/logger.hpp>
#include <exception>
#include <stdexcept>
#include <string>

/**
 * @defgroup exceptions Exceptions
 * @ingroup helpers
 */

/**
 * @ingroup exceptions
 * @brief Generate throw with a custom message using fmt::format
 */
#ifdef _DEBUG
#define EQ_THROW(...)                                                                                                  \
  std::throw_with_nested(                                                                                              \
      std::runtime_error(fmt::format("{} {}  {}:{}", __FUNCTION__, fmt::format(__VA_ARGS__), __FILE__, __LINE__)));
#else
#define EQ_THROW(...) std::throw_with_nested(std::runtime_error(fmt::format(__VA_ARGS__)));
#endif

namespace eq {

/**
 * @ingroup exceptions
 * @brief Print stacktrace
 *
 * @param exception const std::exception&
 * @param level int
 */
void StackTrace(const std::exception &exception, int level = 0);

} // namespace eq
