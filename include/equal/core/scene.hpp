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

#include <equal/core/timestep.hpp>
#include <equal/core/game_object.hpp>
#include <equal/prefab/ui/canvas.hpp>
#include <equal/system/event_system.hpp>
#include <equal/system/component_system.hpp>
#include <equal/system/script_system.hpp>
#include <equal/world/data.hpp>

namespace eq {

/**
 * @defgroup scenes Scenes
 * @ingroup prefabs
 */

/**
 * @ingroup core
 * @brief Scene class
 */
class Scene {
protected:
  Ref<World> m_world;
  bool m_initialized{false};
  // ---------- Systems ----------
  Scope<EventSystem> m_event;
  Scope<ComponentSystem> m_component;
  Scope<ScriptSystem> m_script;
  // ---------- Game Objects ----------
  Ref<ui::Canvas> m_canvas;
  std::vector<Ref<GameObject>> m_objects;

public:
  /**
   * @brief Construct a new Scene object
   */
  Scene();

  /**
   * @brief Destroy the Scene object
   */
  virtual ~Scene();

  /**
   * @brief Call on start scene after constructor
   */
  inline virtual void start(){};

  /**
   * @brief Call on end scene before desconstructor
   */
  inline virtual void end(){};

  /**
   * @brief Get world data
   *
   * @return const eq::Ref<eq::World>&
   */
  const Ref<World> &world() const;

  /**
   * @brief Set world data
   *
   * @param world eq::Ref<eq::World>&
   */
  void world(Ref<World> &world);

  /**
   * @brief Set ui canvas
   *
   * @param canvas eq::Ref<eq::ui::Canvas>&
   */
  void canvas(Ref<ui::Canvas> &canvas);

  /**
   * @brief Get ui canvas
   *
   * @return const eq::Ref<eq::ui::Canvas>&
   */
  const Ref<ui::Canvas> &canvas() const;

  /**
   * @brief Get all game objects in scene
   *
   * @return const std::vector<eq::Ref<GameObject>>&
   */
  const std::vector<Ref<GameObject>> &objects() const;

  /**
   * @brief Add game object in scene
   *
   * @param object eq::Ref<eq::GameObject>&
   */
  void add(Ref<GameObject> &object);

  /**
   * @brief Update scene loop
   *
   * @param timestep const eq::Timestep&
   */
  virtual void update(const Timestep &timestep);

  /**
   * @brief Fixed update scene loop
   *
   * @param timestep const eq::Timestep&
   */
  virtual void fixed_update(const Timestep &timestep);

  /**
   * @brief get event system
   *
   * @return const eq::Scope<eq::EventSystem>&
   */
  const Scope<EventSystem> &event_system() const;

  /**
   * @brief Get component system
   *
   * @return const eq::Scope<eq::ComponentSystem>&
   */
  const Scope<ComponentSystem> &component_system() const;

  /**
   * @brief Get script system
   *
   * @return const Scope<ScriptSystem>&
   */
  const Scope<ScriptSystem> &script_system() const;

  /**
   * @brief Update scene loop
   *
   * @param world eq::Ref<eq::World>&
   * @param timestep const eq::Timestep&
   */
  virtual void update(Ref<World> &world, const Timestep &timestep) = 0;

  /**
   * @brief Fixed update scene loop
   *
   * @param world eq::Ref<eq::World>&
   * @param timestep const eq::Timestep&
   */
  virtual void fixed_update(Ref<World> &world, const Timestep &timestep) = 0;
};

} // namespace eq
