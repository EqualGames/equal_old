#pragma once

#include <string>
#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>

namespace eq::ui {

class Text;
class Button;

/**
 * @ingroup ui
 * @brief UI window
 */
class Window : public GameObject {
private:
  Text *m_title{nullptr};
  Button *m_button_close{nullptr};

public:
  Window(const std::string& id = "");
  Window(const std::string &value, const Position &position, const Size &size);
  virtual ~Window();

  void title(const std::wstring &text);
  void title(const std::string &text);
  void title_font(Font *font);
  void title_color(const Color &color);
};

} // namespace eq::ui
