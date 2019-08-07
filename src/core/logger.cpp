#include <equal/core/logger.hpp>

namespace eq {

namespace out {

const std::string apply_effect(const char *color, const std::string &text) {
  return fmt::format("{}{}{}", color, text, code::RESET);
}

const std::string BOLD(const std::string &text) { return apply_effect(code::TEXT_BOLD, text); }
const std::string UNDERLINE(const std::string &text) { return apply_effect(code::TEXT_UNDERLINE, text); }

const std::string BLACK(const std::string &text) { return apply_effect(code::FG_BLACK, text); }
const std::string RED(const std::string &text) { return apply_effect(code::FG_RED, text); }
const std::string GREEN(const std::string &text) { return apply_effect(code::FG_GREEN, text); }
const std::string YELLOW(const std::string &text) { return apply_effect(code::FG_YELLOW, text); }
const std::string BLUE(const std::string &text) { return apply_effect(code::FG_BLUE, text); }
const std::string MAGENTA(const std::string &text) { return apply_effect(code::FG_MAGENTA, text); }
const std::string CYAN(const std::string &text) { return apply_effect(code::FG_CYAN, text); }
const std::string LIGHT_GRAY(const std::string &text) { return apply_effect(code::FG_LIGHT_GRAY, text); }
const std::string DEFAULT(const std::string &text) { return apply_effect(code::FG_DEFAULT, text); }
const std::string DARK_GRAY(const std::string &text) { return apply_effect(code::FG_DARK_GRAY, text); }
const std::string LIGHT_RED(const std::string &text) { return apply_effect(code::FG_LIGHT_RED, text); }
const std::string LIGHT_GREEN(const std::string &text) { return apply_effect(code::FG_LIGHT_GREEN, text); }
const std::string LIGHT_YELLOW(const std::string &text) { return apply_effect(code::FG_LIGHT_YELLOW, text); }
const std::string LIGHT_BLUE(const std::string &text) { return apply_effect(code::FG_LIGHT_BLUE, text); }
const std::string LIGHT_MAGENTA(const std::string &text) { return apply_effect(code::FG_LIGHT_MAGENTA, text); }
const std::string LIGHT_CYAN(const std::string &text) { return apply_effect(code::FG_LIGHT_CYAN, text); }
const std::string WHITE(const std::string &text) { return apply_effect(code::FG_WHITE, text); }

const std::string BG_BLACK(const std::string &text) { return apply_effect(code::BG_BLACK, text); }
const std::string BG_RED(const std::string &text) { return apply_effect(code::BG_RED, text); }
const std::string BG_GREEN(const std::string &text) { return apply_effect(code::BG_GREEN, text); }
const std::string BG_YELLOW(const std::string &text) { return apply_effect(code::BG_YELLOW, text); }
const std::string BG_BLUE(const std::string &text) { return apply_effect(code::BG_BLUE, text); }
const std::string BG_MAGENTA(const std::string &text) { return apply_effect(code::BG_MAGENTA, text); }
const std::string BG_CYAN(const std::string &text) { return apply_effect(code::BG_CYAN, text); }
const std::string BG_WHITE(const std::string &text) { return apply_effect(code::BG_WHITE, text); }
const std::string BG_DEFAULT(const std::string &text) { return apply_effect(code::BG_DEFAULT, text); }

} // namespace out

std::shared_ptr<Logger> Logger::m_core = std::make_shared<Logger>("CORE");
std::shared_ptr<Logger> Logger::m_client = std::make_shared<Logger>("GAME");

Logger::Logger(const std::string &name) : m_name(name) {}

Logger::~Logger() {}

const std::string Logger::level_to_str(Level level) {
  switch (level) {
  case TRACE:
    return out::LIGHT_GRAY(out::BOLD("TRACE"));
    break;
  case DEBUG:
    return out::CYAN(out::BOLD("DEBUG"));
    break;
  case INFO:
    return out::GREEN(out::BOLD("INFO"));
    break;
  case WARN:
    return out::YELLOW(out::BOLD("WARN"));
    break;
  case ERROR:
    return out::RED(out::BOLD("ERROR"));
    break;
  case CRITICAL:
    return out::BG_RED(out::WHITE(out::BOLD("CRITICAL")));
    break;
  default:
    return out::DEFAULT(out::BOLD("NONE"));
    break;
  }
}

} // namespace eq
