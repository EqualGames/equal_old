#pragma once

#include <equal/core/input.hpp>
#include <equal/core/timestep.hpp>
#include <equal/core/types.hpp>

namespace eq {

class GameObject;

/**
 * @defgroup scripts Scripts
 * @ingroup prefabs
 */

/**
 * @ingroup core
 * @brief Scripts definitions
 */
class Script {
protected:
  GameObject *m_target{nullptr};
  Input::OnMouseMove SignalOnMouseMove;
  Input::OnMousePress SignalOnMousePress;
  Input::OnMouseRelease SignalOnMouseRelease;
  Input::OnKeyPress SignalOnKeyPress;
  Input::OnKeyRelease SignalOnKeyRelease;
  Input::OnInsertText SignalOnInsertText;

  void register_event(Input::Event event, const Input::EventHandler &fn);

public:
  Script() = default;
  virtual ~Script();

  void target(GameObject *object);

  void dispatch(Input::Event event, Input::EventData *data);
  virtual void start();
  virtual void end();
  virtual void update(const Timestep &timestep);
  virtual void fixed_update(const Timestep &timestep);
};

} // namespace eq
