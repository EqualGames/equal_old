#pragma once

#include <string>
#include <cstdint>
#include <equal/core/types.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/prefab/ui/container.hpp>
#include <equal/prefab/ui/text.hpp>
#include <equal/prefab/ui/image.hpp>

namespace eq::ui {

/**
 * @ingroup ui
 * @brief UI text input
 */
class TextInput : public GameObject {
private:
  Text *m_value{nullptr};
  Image *m_caret{nullptr};

public:
  TextInput(const std::string &id = "");
  TextInput(const std::string &value, const Position &position, const Size &size);
  virtual ~TextInput();

  void move_caret();
  void masked(bool masked);
  bool caret() const;
  void caret(bool visible);
  std::wstring text();
  void text(const std::string &value);
  void text(const std::wstring &value);
  void text_font(Font *font);
  void text_font_size(uint32_t font_size);
  void text_color(const Color &color);
};

} // namespace eq::ui
