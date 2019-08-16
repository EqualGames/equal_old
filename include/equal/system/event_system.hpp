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
#include <equal/core/system.hpp>
#include <equal/event/mouse_move.hpp>
#include <equal/event/mouse_press.hpp>
#include <equal/event/mouse_release.hpp>
#include <equal/event/key_press.hpp>
#include <equal/event/key_release.hpp>
#include <equal/event/insert_text.hpp>

namespace eq {

/**
 * @ingroup systems
 * @brief System to manager and dispatch events
 */
class EventSystem : public System,
                    public IOnMouseMove,
                    public IOnMousePress,
                    public IOnMouseRelease,
                    public IOnKeyPress,
                    public IOnKeyRelease,
                    public IOnInsertText {
private:
  bool m_dragging{false};
  Ref<GameObject> m_focused;

  void emit(Input::Event event, Ref<GameObject> &object, Input::EventData *data) const;
  Ref<GameObject> check_tree(Ref<GameObject> &object, const Position &position) const;

public:
  void start() override;
  void end() override;

  void onMouseMove(const Position &position) override;
  void onMousePress(Mouse::Button button, const Position &position) override;
  void onMouseRelease(Mouse::Button button, const Position &position) override;
  void onKeyPress(Keyboard::Key key) override;
  void onKeyRelease(Keyboard::Key key) override;
  void onInsertText(const std::wstring &text) override;
};

} // namespace eq
