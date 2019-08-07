#pragma once

#include <string>
#include <functional>
#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>

namespace eq::ui {

class Text;

/**
 * @ingroup ui
 * @brief UI button
 */
class Button : public GameObject {
private:
  Text *m_label{nullptr};

public:
  Button(const std::string& id = "");
  Button(const std::string &value, const Position &position, const Size &size);
  virtual ~Button();

  void text(const std::wstring &text);
  void text(const std::string &text);
  void text_font(Font *font);
  void text_font_size(uint32_t font_size);
  void text_color(const Color &color);
  void text_position(const Position &position);
  void text_anchor(Transform::Anchor anchor);
  void action(const ActionPerform &fn);
};

} // namespace eq::ui
