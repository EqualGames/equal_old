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

class Text;
class Button;

/**
 * @ingroup ui
 * @brief UI window
 */
class Window : public GameObject {
private:
  Text *m_title{nullptr};
  Button *m_button_close{nullptr};

public:
  Window(const std::string& id = "");
  Window(const std::string &value, const Position &position, const Size &size);
  virtual ~Window();

  void title(const std::wstring &text);
  void title(const std::string &text);
  void title_font(Font *font);
  void title_color(const Color &color);
};

} // namespace eq::ui
