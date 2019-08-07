#include <equal/core/game_object.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/prefab/script/button_script.hpp>

namespace eq {

void ButtonScript::start() {
  register_event(Input::Event::MouseMove, [&](Input::EventData *event) { this->onMouseMove(event->mouse); });
  register_event(Input::Event::MousePress,
                 [&](Input::EventData *event) { this->onMousePress(event->mouse_button, event->mouse); });
  register_event(Input::Event::MouseRelease,
                 [&](Input::EventData *event) { this->onMouseRelease(event->mouse_button, event->mouse); });
}

void ButtonScript::end() {}

void ButtonScript::update(const Timestep &timestep) {}

void ButtonScript::fixed_update(const Timestep &timestep) {}

void ButtonScript::registerAction(const ActionPerform &fn) { m_action = fn; }

void ButtonScript::onMouseMove(const Position &position) {
  if (m_state != State::Pressed) {
    if (m_target->GetComponent<TransformComponent>()->contain(position)) {
      m_state = State::Hovered;
      m_target->GetComponent<RendererComponent>()->color(m_color_hover);
    } else {
      m_state = State::Normal;
      m_target->GetComponent<RendererComponent>()->color(m_color_normal);
    }
  }
}

void ButtonScript::onMousePress(Mouse::Button button, const Position &position) {
  m_state = State::Pressed;
  m_target->GetComponent<RendererComponent>()->color(m_color_pressed);
}

void ButtonScript::onMouseRelease(Mouse::Button button, const Position &position) {
  if (m_state == State::Pressed) {
    if (m_target->GetComponent<TransformComponent>()->contain(position)) {
      m_state = State::Hovered;
      m_target->GetComponent<RendererComponent>()->color(m_color_hover);
      // Call Button Action
      m_action();
    } else {
      m_state = State::Normal;
      m_target->GetComponent<RendererComponent>()->color(m_color_normal);
    }
  }
}

} // namespace eq
