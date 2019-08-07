#include <equal/core/game_object.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/prefab/script/window_script.hpp>

namespace eq {

void WindowScript::start() {
  m_drag_area.z = m_target->GetComponent<TransformComponent>()->size().x;
  register_event(Input::Event::MouseMove, [&](Input::EventData *event) { this->onMouseMove(event->mouse); });
  register_event(Input::Event::MousePress,
                 [&](Input::EventData *event) { this->onMousePress(event->mouse_button, event->mouse); });
  register_event(Input::Event::MouseRelease,
                 [&](Input::EventData *event) { this->onMouseRelease(event->mouse_button, event->mouse); });
}

void WindowScript::end() {}

void WindowScript::update(const Timestep &timestep) {}

void WindowScript::fixed_update(const Timestep &timestep) {}

bool WindowScript::in_drag_area(const Position &position) {
  TransformComponent *transform = m_target->GetComponent<TransformComponent>();
  Position pos{transform->position() - transform->origin()};

  return (position.x > (pos.x + m_drag_area.x) && position.x < (pos.x + m_drag_area.z)) &&
         (position.y > (pos.y + m_drag_area.y) && position.y < (pos.y + m_drag_area.w));
}

void WindowScript::onMouseMove(const Position &position) {
  if (m_state == State::Dragging) {
    m_target->GetComponent<TransformComponent>()->position(position + m_dragging_offset);
  }
}

void WindowScript::onMousePress(Mouse::Button button, const Position &position) {
  if (m_state != State::Dragging && in_drag_area(position)) {
    m_state = State::Dragging;
    m_dragging_offset = m_target->GetComponent<TransformComponent>()->local_position() - position;
  }
}

void WindowScript::onMouseRelease(Mouse::Button button, const Position &position) {
  if (m_state == State::Dragging) {
    m_state = State::Normal;
    m_dragging_offset = Position{0};
  }
}

} // namespace eq
