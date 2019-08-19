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

#include <equal/core/game_object.hpp>
#include <equal/core/types.hpp>
#include <functional>
#include <string>

namespace eq::ui {

class Text;

/**
 * @ingroup ui
 * @brief UI button
 */
class Button : public GameObject {
private:
  Ref<Text> m_label;

public:
  /**
   * @brief Construct a new Button object
   *
   * @param id
   */
  Button(const std::string &id = "");

  /**
   * @brief Construct a new Button object
   *
   * @param value
   * @param position
   * @param size
   */
  Button(const std::string &value, const Position &position, const Size &size);

  /**
   * @brief Destroy the Button object
   *
   */
  virtual ~Button();

  /**
   * @brief
   *
   * @param text const std::wstring&
   */
  void text(const std::wstring &text);

  /**
   * @brief
   *
   * @param text const std::string&
   */
  void text(const std::string &text);

  /**
   * @brief
   *
   * @param font eq::Font *
   */
  void text_font(Font *font);

  /**
   * @brief
   *
   * @param font_size uint32_t
   */
  void text_font_size(uint32_t font_size);

  /**
   * @brief
   *
   * @param color const eq::Color&
   */
  void text_color(const Color &color);

  /**
   * @brief
   *
   * @param position const eq::Position&
   */
  void text_position(const Position &position);

  /**
   * @brief
   *
   * @param anchor eq::Transform::Anchor
   */
  void text_anchor(Transform::Anchor anchor);

  /**
   * @brief
   *
   * @param fn const eq::ActionPerform&
   */
  void action(const ActionPerform &fn);
};

} // namespace eq::ui
