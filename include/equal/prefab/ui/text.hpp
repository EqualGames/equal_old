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
