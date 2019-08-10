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
