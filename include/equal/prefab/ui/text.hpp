#pragma once

#include <string>
#include <cstdint>
#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>

namespace eq::ui {

/**
 * @ingroup ui
 * @brief UI text
 */
class Text : public GameObject {
public:
  Text(const std::string& id = "");
  Text(const std::string &value, const Position &position);
  virtual ~Text();

  std::wstring text();
  void text(const std::wstring &text);
  void text(const std::string &text);
  void font(Font *font);
  void font_size(uint32_t font_size);
  void color(const Color &color);
  void alignment(const eq::Text::Alignment &align);
  void style(const eq::Text::Style &style);
};

} // namespace eq::ui
