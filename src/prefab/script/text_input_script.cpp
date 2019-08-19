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
#include <equal/component/renderer_component.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/core/game_object.hpp>
#include <equal/prefab/script/text_input_script.hpp>
#include <equal/prefab/ui/text_input.hpp>
#include <memory>

namespace eq {

void TextInputScript::start() {
  register_event(Input::Event::MouseMove, [&](Input::EventData *event) { this->onMouseMove(event->mouse); });
  register_event(Input::Event::MousePress,
                 [&](Input::EventData *event) { this->onMousePress(event->mouse_button, event->mouse); });
  register_event(Input::Event::KeyPress, [&](Input::EventData *event) { this->onKeyPress(event->key); });
  register_event(Input::Event::InsertText, [&](Input::EventData *event) { this->onInsertText(event->text); });
}

void TextInputScript::end() {}

void TextInputScript::update(const Timestep &timestep) {
  if (m_caret_visible) {
    Ref<ui::TextInput> input = std::dynamic_pointer_cast<ui::TextInput>(m_target);
    input->move_caret();
  }
}

void TextInputScript::fixed_update(const Timestep &timestep) {}

void TextInputScript::onMouseMove(const Position &position) {
  if (m_state != State::Focused) {
    if (m_target->GetComponent<TransformComponent>()->contain(position)) {
      m_state = State::Hovered;
      // Change cursor to text caret
    } else if (!m_target->focused()) {
      m_state = State::Normal;
      Ref<ui::TextInput> input = std::dynamic_pointer_cast<ui::TextInput>(m_target);
      m_caret_visible = false;
      input->caret(false);
    }
  }
}

void TextInputScript::onMousePress(Mouse::Button button, const Position &position) {
  if (m_state == State::Focused) {
    m_state = State::Normal;
    m_target->focused(false);
    Ref<ui::TextInput> input = std::dynamic_pointer_cast<ui::TextInput>(m_target);
    m_caret_visible = false;
    input->caret(false);
  } else if (m_target->GetComponent<TransformComponent>()->contain(position)) {
    m_state = State::Focused;
    m_target->focused(true);
    Ref<ui::TextInput> input = std::dynamic_pointer_cast<ui::TextInput>(m_target);
    m_caret_visible = true;
    input->caret(true);
  }
}

void TextInputScript::onKeyPress(Keyboard::Key key) {
  if (m_state == State::Focused) {
    Ref<ui::TextInput> input = std::dynamic_pointer_cast<ui::TextInput>(m_target);
    if (key == Keyboard::Key::Backspace && input->text().size()) {
      std::wstring new_text = input->text();
      new_text.erase(new_text.size() - 1, 1);
      input->text(new_text);
    }
  }
}

void TextInputScript::onInsertText(const std::wstring &text) {
  if (m_state == State::Focused) {
    Ref<ui::TextInput> input = std::dynamic_pointer_cast<ui::TextInput>(m_target);
    input->text(input->text() + text);
  }
}

} // namespace eq
