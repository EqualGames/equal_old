#include <equal/core/game_object.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/prefab/ui/text_input.hpp>
#include <equal/prefab/script/text_input_script.hpp>

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
    ui::TextInput *input = static_cast<ui::TextInput *>(m_target);
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
      ui::TextInput *input = static_cast<ui::TextInput *>(m_target);
      m_caret_visible = false;
      input->caret(false);
    }
  }
}

void TextInputScript::onMousePress(Mouse::Button button, const Position &position) {
  if (m_state == State::Focused) {
    m_state = State::Normal;
    m_target->focused(false);
    ui::TextInput *input = static_cast<ui::TextInput *>(m_target);
    m_caret_visible = false;
    input->caret(false);
  } else if (m_target->GetComponent<TransformComponent>()->contain(position)) {
    m_state = State::Focused;
    m_target->focused(true);
    ui::TextInput *input = static_cast<ui::TextInput *>(m_target);
    m_caret_visible = true;
    input->caret(true);
  }
}

void TextInputScript::onKeyPress(Keyboard::Key key) {
  if (m_state == State::Focused) {
    ui::TextInput *input = static_cast<ui::TextInput *>(m_target);
    if (key == Keyboard::Key::Backspace && input->text().size()) {
      std::wstring new_text = input->text();
      new_text.erase(new_text.size() - 1, 1);
      input->text(new_text);
    }
  }
}

void TextInputScript::onInsertText(const std::wstring &text) {
  if (m_state == State::Focused) {
    ui::TextInput *input = static_cast<ui::TextInput *>(m_target);
    input->text(input->text() + text);
  }
}

} // namespace eq
