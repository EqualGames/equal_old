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
#include <equal/core/game_object.hpp>
#include <equal/core/types.hpp>
#include <string>

namespace eq::ui {

/**
 * @ingroup ui
 * @brief UI text
 */
class Text : public GameObject {
public:
  /**
   * @brief Construct a new Text object
   *
   * @param id
   */
  Text(const std::string &id = "");

  /**
   * @brief Construct a new Text object
   *
   * @param value
   * @param position
   */
  Text(const std::string &value, const Position &position);

  /**
   * @brief Destroy the Text object
   *
   */
  virtual ~Text();

  /**
   * @brief
   *
   * @return std::wstring
   */
  std::wstring text();

  /**
   * @brief
   *
   * @param text
   */
  void text(const std::wstring &text);

  /**
   * @brief
   *
   * @param text
   */
  void text(const std::string &text);

  /**
   * @brief
   *
   * @param font
   */
  void font(Font *font);

  /**
   * @brief
   *
   * @param font_size
   */
  void font_size(uint32_t font_size);

  /**
   * @brief
   *
   * @param color
   */
  void color(const Color &color);

  /**
   * @brief
   *
   * @param align
   */
  void alignment(const eq::Text::Alignment &align);

  /**
   * @brief
   *
   * @param style
   */
  void style(const eq::Text::Style &style);
};

} // namespace eq::ui
