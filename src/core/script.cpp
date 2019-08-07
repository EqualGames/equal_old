#include <equal/core/logger.hpp>
#include <equal/core/game_object.hpp>
#include <equal/helper/error.hpp>
#include <equal/helper/system.hpp>
#include <equal/core/script.hpp>
#include <equal/system/event_system.hpp>

namespace eq {

Script::~Script() {
  end();
  delete m_target;
}

void Script::target(GameObject *target) { m_target = target; }

void Script::register_event(Input::Event event, const Input::EventHandler &fn) {
  switch (event) {
  case Input::Event::MouseMove:
    SignalOnMouseMove.connect(fn);
    break;
  case Input::Event::MousePress:
    SignalOnMousePress.connect(fn);
    break;
  case Input::Event::MouseRelease:
    SignalOnMouseRelease.connect(fn);
    break;
  case Input::Event::KeyPress:
    SignalOnKeyPress.connect(fn);
    break;
  case Input::Event::KeyRelease:
    SignalOnKeyRelease.connect(fn);
    break;
  case Input::Event::InsertText:
    SignalOnInsertText.connect(fn);
    break;

  default:
    EQ_CORE_WARN("Event \"{0}\" is not mapped by program", int(event));
    break;
  }
}

void Script::dispatch(Input::Event event, Input::EventData *data) {
  switch (event) {
  case Input::Event::MouseMove:
    SignalOnMouseMove(data);
    break;
  case Input::Event::MousePress:
    SignalOnMousePress(data);
    break;
  case Input::Event::MouseRelease:
    SignalOnMouseRelease(data);
    break;
  case Input::Event::KeyPress:
    SignalOnKeyPress(data);
    break;
  case Input::Event::KeyRelease:
    SignalOnKeyRelease(data);
    break;
  case Input::Event::InsertText:
    SignalOnInsertText(data);
    break;

  default:
    EQ_CORE_WARN("Event \"{0}\" is not mapped by program", int(event));
    break;
  }
}

void Script::start() {}

void Script::end() {}

void Script::update(const Timestep &timestep) {}

void Script::fixed_update(const Timestep &timestep) {}

} // namespace eq
