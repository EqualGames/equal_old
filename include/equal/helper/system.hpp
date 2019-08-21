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

#include <equal/core/component.hpp>
#include <equal/core/script.hpp>
#include <equal/core/types.hpp>
#include <equal/system/component_system.hpp>
#include <equal/system/script_system.hpp>

namespace eq {

class EventSystem;
class Window;
class Scene;
class Painter;

/**
 * @ingroup helpers
 * @brief Get the Event System object
 *
 * @return const eq::Scope<eq::EventSystem>&
 */
const Scope<EventSystem> &get_event_system();

/**
 * @ingroup helpers
 * @brief Get the Component System object
 *
 * @return const eq::Scope<eq::ComponentSystem>&
 */
const Scope<ComponentSystem> &get_component_system();

/**
 * @ingroup helpers
 * @brief Get the Script System object
 *
 * @return const eq::Scope<eq::ScriptSystem>&
 */
const Scope<ScriptSystem> &get_script_system();

/**
 * @ingroup helpers
 * @brief Get the Scene object
 *
 * @return const eq::Scope<eq::Scene>&
 */
const Scope<Scene> &get_scene();

/**
 * @ingroup helpers
 * @brief Get the Window object
 *
 * @return const eq::Scope<eq::Window>&
 */
const Scope<Window> &get_window();

/**
 * @ingroup helpers
 * @brief Get the Painter object
 *
 * @return const eq::Scope<eq::Painter>&
 */
const Scope<Painter> &get_painter();

/**
 * @ingroup helpers
 * @brief
 *
 * @tparam T eq::Component
 * @param guid const std::string&
 * @param component eq::Component*
 */
template <typename T>
inline void register_component(const std::string &guid, Component *component) {
  get_component_system()->add<T>(guid, component);
}

/**
 * @ingroup helpers
 * @brief Get the component object
 *
 * @tparam T eq::Component
 * @param guid const std::string&
 * @return T*
 */
template <typename T>
inline T *get_component(const std::string &guid) {
  return get_component_system()->get<T>(guid);
}

/**
 * @ingroup helpers
 * @brief Check if component exists
 *
 * @tparam T
 * @param guid const std::string&
 * @return bool
 */
template <typename T>
inline bool has_component(const std::string &guid) {
  return get_component_system()->has_type<T>(guid);
}

/**
 * @ingroup helpers
 * @brief
 *
 * @tparam T eq::Script
 * @param guid const std::string&
 * @param script eq::Script*
 */
template <typename T>
inline void register_script(const std::string &guid, Script *script) {
  get_script_system()->add<T>(guid, script);
}

/**
 * @ingroup helpers
 * @brief Get the script object
 *
 * @tparam T eq::Script
 * @param guid const std::string&
 * @return T*
 */
template <typename T>
inline T *get_script(const std::string &guid) {
  return get_script_system()->get<T>(guid);
}

/**
 * @ingroup helpers
 * @brief Check if script exists
 *
 * @tparam T eq::Script
 * @param guid const std::string&
 * @return bool
 */
template <typename T>
inline bool has_script(const std::string &guid) {
  return get_script_system()->has_type<T>(guid);
}

} // namespace eq
