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

#include <equal/core/types.hpp>

namespace eq {

class EventSystem;
class ComponentSystem;
class ScriptSystem;
class Window;
class Scene;
class Painter;

/**
 * @ingroup helpers
 * @brief Get the Event System object
 *
 * @return eq::EventSystem*
 */
EventSystem *GetEventSystem();

/**
 * @ingroup helpers
 * @brief Get the Component System object
 *
 * @return eq::ComponentSystem*
 */
ComponentSystem *GetComponentSystem();

/**
 * @ingroup helpers
 * @brief Get the Script System object
 *
 * @return eq::ScriptSystem*
 */
ScriptSystem *GetScriptSystem();

/**
 * @ingroup helpers
 * @brief Get the Scene object
 *
 * @return const Scope<Scene> &
 */
const Scope<Scene> &GetScene();

/**
 * @ingroup helpers
 * @brief Get the Window object
 *
 * @return const Scope<Window> &
 */
const Scope<Window> &GetWindow();

/**
 * @ingroup helpers
 * @brief Get the Painter object
 *
 * @return const Scope<Painter> &
 */
const Scope<Painter> &GetPainter();

} // namespace eq
