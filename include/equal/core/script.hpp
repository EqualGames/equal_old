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
