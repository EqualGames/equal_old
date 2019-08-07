#pragma once

#include <string>
#include <exception>
#include <stdexcept>
#include <equal/core/logger.hpp>

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
