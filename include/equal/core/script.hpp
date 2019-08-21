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
  bool m_active{true};
  Ref<GameObject> m_target;
  Input::OnMouseMove SignalOnMouseMove;
  Input::OnMousePress SignalOnMousePress;
  Input::OnMouseRelease SignalOnMouseRelease;
  Input::OnKeyPress SignalOnKeyPress;
  Input::OnKeyRelease SignalOnKeyRelease;
  Input::OnInsertText SignalOnInsertText;

  void register_event(Input::Event event, const Input::EventHandler &fn);

public:
  /**
   * @brief Construct a new Script object
   */
  Script() = default;

  /**
   * @brief Destroy the Script object
   */
  virtual ~Script();

  /**
   * @brief Return if script has active
   *
   * @return bool
   */
  bool active() const;

  /**
   * @brief Set if script has active
   *
   * @param active bool
   */
  void active(bool active);

  /**
   * @brief
   *
   * @param object eq::Ref<eq::GameObject>&
   */
  void target(Ref<GameObject> &object);

  /**
   * @brief
   *
   * @param event eq::Input::Event
   * @param data eq::Input::EventData*
   */
  void dispatch(Input::Event event, Input::EventData *data);

  /**
   * @brief
   */
  virtual void start();

  /**
   * @brief
   */
  virtual void end();

  /**
   * @brief
   *
   * @param timestep
   */
  virtual void update(const Timestep &timestep);

  /**
   * @brief
   *
   * @param timestep
   */
  virtual void fixed_update(const Timestep &timestep);
};

} // namespace eq
