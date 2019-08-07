#pragma once

#include <ctime>
#include <iostream>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <string_view>
#include <fmt/format.h>

namespace eq {

namespace out {

namespace code {

static const char RESET[7] = "\033[0m";
static const char TEXT_BOLD[7] = "\033[1m";
static const char TEXT_UNDERLINE[7] = "\033[4m";

static const char FG_BLACK[8] = "\033[30m";
static const char FG_RED[8] = "\033[31m";
static const char FG_GREEN[8] = "\033[32m";
static const char FG_YELLOW[8] = "\033[33m";
static const char FG_BLUE[8] = "\033[34m";
static const char FG_MAGENTA[8] = "\033[35m";
static const char FG_CYAN[8] = "\033[36m";
static const char FG_LIGHT_GRAY[8] = "\033[37m";
static const char FG_DEFAULT[8] = "\033[39m";
static const char FG_DARK_GRAY[8] = "\033[90m";
static const char FG_LIGHT_RED[8] = "\033[91m";
static const char FG_LIGHT_GREEN[8] = "\033[92m";
static const char FG_LIGHT_YELLOW[8] = "\033[93m";
static const char FG_LIGHT_BLUE[8] = "\033[94m";
static const char FG_LIGHT_MAGENTA[8] = "\033[95m";
static const char FG_LIGHT_CYAN[8] = "\033[96m";
static const char FG_WHITE[8] = "\033[97m";

static const char BG_BLACK[8] = "\033[40m";
static const char BG_RED[8] = "\033[41m";
static const char BG_GREEN[8] = "\033[42m";
static const char BG_YELLOW[8] = "\033[43m";
static const char BG_BLUE[8] = "\033[44m";
static const char BG_MAGENTA[8] = "\033[45m";
static const char BG_CYAN[8] = "\033[46m";
static const char BG_WHITE[8] = "\033[47m";
static const char BG_DEFAULT[8] = "\033[49m";

} // namespace code

const std::string apply_effect(const char *color, const std::string &text);

const std::string BOLD(const std::string &text);
const std::string UNDERLINE(const std::string &text);

const std::string BLACK(const std::string &text);
const std::string RED(const std::string &text);
const std::string GREEN(const std::string &text);
const std::string YELLOW(const std::string &text);
const std::string BLUE(const std::string &text);
const std::string MAGENTA(const std::string &text);
const std::string CYAN(const std::string &text);
const std::string LIGHT_GRAY(const std::string &text);
const std::string DEFAULT(const std::string &text);
const std::string DARK_GRAY(const std::string &text);
const std::string LIGHT_RED(const std::string &text);
const std::string LIGHT_GREEN(const std::string &text);
const std::string LIGHT_YELLOW(const std::string &text);
const std::string LIGHT_BLUE(const std::string &text);
const std::string LIGHT_MAGENTA(const std::string &text);
const std::string LIGHT_CYAN(const std::string &text);
const std::string WHITE(const std::string &text);
const std::string BG_BLACK(const std::string &text);
const std::string BG_RED(const std::string &text);
const std::string BG_GREEN(const std::string &text);
const std::string BG_YELLOW(const std::string &text);
const std::string BG_BLUE(const std::string &text);
const std::string BG_MAGENTA(const std::string &text);
const std::string BG_CYAN(const std::string &text);
const std::string BG_WHITE(const std::string &text);
const std::string BG_DEFAULT(const std::string &text);

} // namespace out

/**
 * @defgroup logger Logger
 * @ingroup core
 *
 * The messages are formated using fmt::format
 * @see https://fmt.dev/5.3.0/
 */

/**
 * @ingroup core
 * @brief Logger manager
 */
class Logger {
public:
  /**
   * @brief Logger levels
   */
  enum Level { TRACE, DEBUG, INFO, WARN, ERROR, CRITICAL };

private:
  /**
   * @brief Transform eq::Logger::Level to std::string
   *
   * @param level  eq::Logger::Level
   * @return std::string
   */
  const std::string level_to_str(Level level);

  Level m_level{Level::INFO};
  std::string m_name;

  static std::shared_ptr<Logger> m_core;
  static std::shared_ptr<Logger> m_client;

public:
  /**
   * @brief Construct a new Logger object
   *
   * @param name const std::string&
   */
  Logger(const std::string &name = "default");

  /**
   * @brief Destroy the Logger
   */
  ~Logger();

  /**
   * @brief Define logger level
   *
   * @param level eq::Logger::Level
   */
  void level(Level level) { m_level = level; }

  /**
   * @brief Print message
   *
   * @tparam Args
   * @param level eq::Logger::Level
   * @param args Args
   */
  template <typename... Args>
  void log(Level level, Args... args) {
    if (level >= m_level) {
      std::time_t t = std::time(nullptr);
      std::tm tm = *std::localtime(&t);

      std::stringstream ss;
      ss << std::put_time(&tm, "%Y/%m/%d %H:%M:%S %z");

      std::cout << "[" << ss.str() << "] [" << level_to_str(level) << "] " << out::LIGHT_GRAY(out::BOLD(m_name)) << " "
                << fmt::format(args...) << std::endl;
    }
  }

  /**
   * @brief Print trace message
   *
   * @tparam Args
   * @param args Args
   */
  template <typename... Args>
  void trace(Args... args) {
    log(Level::TRACE, args...);
  }

  /**
   * @brief Print debug message
   *
   * @tparam Args
   * @param args Args
   */
  template <typename... Args>
  void debug(Args... args) {
    log(Level::DEBUG, args...);
  }

  /**
   * @brief Print info message
   *
   * @tparam Args
   * @param args Args
   */
  template <typename... Args>
  void info(Args... args) {
    log(Level::INFO, args...);
  }

  /**
   * @brief Print warn message
   *
   * @tparam Args
   * @param args Args
   */
  template <typename... Args>
  void warn(Args... args) {
    log(Level::WARN, args...);
  }

  /**
   * @brief Print error message
   *
   * @tparam Args
   * @param args Args
   */
  template <typename... Args>
  void error(Args... args) {
    log(Level::ERROR, args...);
  }

  /**
   * @brief Print critical message
   *
   * @tparam Args
   * @param args Args
   */
  template <typename... Args>
  void critical(Args... args) {
    log(Level::CRITICAL, args...);
  }

  /**
   * @brief Get the Core Logger object
   *
   * @return std::shared_ptr<Logger>&
   */
  inline static std::shared_ptr<Logger> &GetCoreLogger() { return m_core; }

  /**
   * @brief Get the Client Logger object
   *
   * @return std::shared_ptr<Logger>&
   */
  inline static std::shared_ptr<Logger> &GetClientLogger() { return m_client; }
};

} // namespace eq

/**
 * @ingroup logger
 * @brief Define core logger level
 */
#define EQ_CORE_LEVEL(...) eq::Logger::GetCoreLogger()->level(__VA_ARGS__);

/**
 * @ingroup logger
 * @brief Print trace message in core logger
 */
#define EQ_CORE_TRACE(...) eq::Logger::GetCoreLogger()->trace(__VA_ARGS__)

/**
 * @ingroup logger
 * @brief Print debug message in core logger
 */
#define EQ_CORE_DEBUG(...) eq::Logger::GetCoreLogger()->debug(__VA_ARGS__)

/**
 * @ingroup logger
 * @brief Print info message in core logger
 */
#define EQ_CORE_INFO(...) eq::Logger::GetCoreLogger()->info(__VA_ARGS__)

/**
 * @ingroup logger
 * @brief Print warn message in core logger
 */
#define EQ_CORE_WARN(...) eq::Logger::GetCoreLogger()->warn(__VA_ARGS__)

/**
 * @ingroup logger
 * @brief Print error message in core logger
 */
#define EQ_CORE_ERROR(...) eq::Logger::GetCoreLogger()->error(__VA_ARGS__)

/**
 * @ingroup logger
 * @brief Print critical message in core logger
 */
#define EQ_CORE_CRITICAL(...) eq::Logger::GetCoreLogger()->critical(__VA_ARGS__)

/**
 * @ingroup logger
 * @brief Define client logger level
 */
#define EQ_LEVEL(...) eq::Logger::GetClientLogger()->level(__VA_ARGS__);

/**
 * @ingroup logger
 * @brief Print trace message in client logger
 */
#define EQ_TRACE(...) eq::Logger::GetClientLogger()->trace(__VA_ARGS__)

/**
 * @ingroup logger
 * @brief Print debug message in client logger
 */
#define EQ_DEBUG(...) eq::Logger::GetClientLogger()->debug(__VA_ARGS__)

/**
 * @ingroup logger
 * @brief Print info message in client logger
 */
#define EQ_INFO(...) eq::Logger::GetClientLogger()->info(__VA_ARGS__)

/**
 * @ingroup logger
 * @brief Print warn message in client logger
 */
#define EQ_WARN(...) eq::Logger::GetClientLogger()->warn(__VA_ARGS__)

/**
 * @ingroup logger
 * @brief Print error message in client logger
 */
#define EQ_ERROR(...) eq::Logger::GetClientLogger()->error(__VA_ARGS__)

/**
 * @ingroup logger
 * @brief Print critical message in client logger
 */
#define EQ_CRITICAL(...) eq::Logger::GetClientLogger()->critical(__VA_ARGS__)
