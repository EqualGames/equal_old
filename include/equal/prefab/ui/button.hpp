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
