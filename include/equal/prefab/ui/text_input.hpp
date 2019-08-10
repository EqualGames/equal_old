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
