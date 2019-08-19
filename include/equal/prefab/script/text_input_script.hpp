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

#include <equal/core/script.hpp>
#include <equal/core/types.hpp>
#include <equal/event/insert_text.hpp>
#include <equal/event/key_press.hpp>
#include <equal/event/mouse_move.hpp>
#include <equal/event/mouse_press.hpp>
#include <equal/event/mouse_release.hpp>
#include <string>

namespace eq {

class GameObject;

/**
 * @ingroup scripts
 * @brief
 */
class TextInputScript : public Script,
                        public IOnMouseMove,
                        public IOnMousePress,
                        public IOnKeyPress,
                        public IOnInsertText {
private:
  enum State { Normal = 0, Hovered, Focused };
  State m_state{State::Normal};
  bool m_caret_visible{false};

public:
  void start() override;
  void end() override;
  void update(const Timestep &timestep) override;
  void fixed_update(const Timestep &timestep) override;

  void onMouseMove(const Position &position) override;
  void onMousePress(Mouse::Button button, const Position &position) override;
  void onKeyPress(Keyboard::Key key) override;
  void onInsertText(const std::wstring &text) override;
};

} // namespace eq
