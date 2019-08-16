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
  Ref<Image> m_image;
  Ref<Button> m_button;

public:
  /**
   * @brief Construct a new Hotkey object
   *
   * @param value
   * @param position
   * @param size
   */
  Hotkey(const std::string &value, const Position &position, const Size &size);

  /**
   * @brief Destroy the Hotkey object
   *
   */
  virtual ~Hotkey();

  /**
   * @brief
   *
   * @param text
   */
  void key(const std::wstring &text);

  /**
   * @brief
   *
   * @param text
   */
  void key(const std::string &text);

  /**
   * @brief
   *
   * @param font
   */
  void key_font(Font *font);

  /**
   * @brief
   *
   * @param color
   */
  void key_color(const Color &color);

  /**
   * @brief
   *
   * @param texture
   */
  void icon(Texture *texture);

  /**
   * @brief
   *
   * @param fn
   */
  void action(const ActionPerform &fn);
};

} // namespace eq::ui
