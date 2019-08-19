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

#include <cstdint>
#include <equal/component/transform_component.hpp>
#include <equal/core/types.hpp>
#include <equal/prefab/ui/container.hpp>
#include <equal/prefab/ui/image.hpp>
#include <equal/prefab/ui/text.hpp>
#include <string>

namespace eq::ui {

/**
 * @ingroup ui
 * @brief UI text input
 */
class TextInput : public GameObject {
private:
  Ref<Text> m_value;
  Ref<Image> m_caret;

public:
  /**
   * @brief Construct a new Text Input object
   *
   * @param id
   */
  TextInput(const std::string &id = "");

  /**
   * @brief Construct a new Text Input object
   *
   * @param value
   * @param position
   * @param size
   */
  TextInput(const std::string &value, const Position &position, const Size &size);

  /**
   * @brief Destroy the Text Input object
   *
   */
  virtual ~TextInput();

  /**
   * @brief
   *
   */
  void move_caret();

  /**
   * @brief
   *
   * @param masked
   */
  void masked(bool masked);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool caret() const;

  /**
   * @brief
   *
   * @param visible
   */
  void caret(bool visible);

  /**
   * @brief
   *
   * @return std::wstring
   */
  std::wstring text();

  /**
   * @brief
   *
   * @param value
   */
  void text(const std::string &value);

  /**
   * @brief
   *
   * @param value
   */
  void text(const std::wstring &value);

  /**
   * @brief
   *
   * @param font
   */
  void text_font(Font *font);

  /**
   * @brief
   *
   * @param font_size
   */
  void text_font_size(uint32_t font_size);

  /**
   * @brief
   *
   * @param color
   */
  void text_color(const Color &color);
};

} // namespace eq::ui
