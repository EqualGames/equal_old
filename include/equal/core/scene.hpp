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
  World *m_world{nullptr};
  bool m_initialized{false};
  // ---------- Systems ----------
  EventSystem *m_event{nullptr};
  ComponentSystem *m_component{nullptr};
  ScriptSystem *m_script{nullptr};
  // ---------- Game Objects ----------
  ui::Canvas *m_canvas{nullptr};
  std::vector<GameObject *> m_objects;

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
   * @return eq::World*
   */
  World *world() const;

  /**
   * @brief Set world data
   */
  void world(World *world);

  /**
   * @brief Set ui canvas
   *
   * @param canvas eq::ui::Canvas
   */
  void canvas(ui::Canvas *canvas);

  /**
   * @brief Get ui canvas
   *
   * @return eq::ui::Canvas*
   */
  ui::Canvas *canvas() const;

  /**
   * @brief Get all game objects in scene
   *
   * @return std::vector<eq::GameObject *>
   */
  std::vector<GameObject *> objects() const;

  /**
   * @brief Add game object in scene
   *
   * @param object eq::GameObject
   */
  void add(GameObject *object);

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
   * @return eq::World*
   */
  EventSystem *event_system() const;

  /**
   * @brief Get component system
   *
   * @return eq::ComponentSystem*
   */
  ComponentSystem *component_system() const;

  /**
   * @brief Get script system
   *
   * @return eq::ScriptSystem*
   */
  ScriptSystem *script_system() const;

  /**
   * @brief Update scene loop
   *
   * @param world eq::World*
   * @param timestep const eq::Timestep&
   */
  virtual void update(World *world, const Timestep &timestep) = 0;

  /**
   * @brief Fixed update scene loop
   *
   * @param world eq::World*
   * @param timestep const eq::Timestep&
   */
  virtual void fixed_update(World *world, const Timestep &timestep) = 0;
};

} // namespace eq
