#pragma once

#include <string>
#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>

namespace eq::ui {

class Image;
class Button;

/**
 * @ingroup ui
 * @brief UI hotkey
 */
class Hotkey : public GameObject {
private:
  Image *m_image{nullptr};
  Button *m_button{nullptr};

public:
  Hotkey(const std::string &value, const Position &position, const Size &size);
  virtual ~Hotkey();

  void key(const std::wstring &text);
  void key(const std::string &text);
  void key_font(Font *font);
  void key_color(const Color &color);
  void icon(Texture *texture);
  void action(const ActionPerform &fn);
};

} // namespace eq::ui
