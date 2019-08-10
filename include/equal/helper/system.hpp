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
eq::EventSystem *GetEventSystem();

/**
 * @ingroup helpers
 * @brief Get the Component System object
 *
 * @return eq::ComponentSystem*
 */
eq::ComponentSystem *GetComponentSystem();

/**
 * @ingroup helpers
 * @brief Get the Script System object
 *
 * @return eq::ScriptSystem*
 */
eq::ScriptSystem *GetScriptSystem();

/**
 * @ingroup helpers
 * @brief Get the Scene object
 *
 * @return eq::Scene*
 */
eq::Scene *GetScene();

/**
 * @ingroup helpers
 * @brief Get the Window object
 *
 * @return eq::Window*
 */
eq::Window *GetWindow();

/**
 * @ingroup helpers
 * @brief Get the Painter object
 *
 * @return eq::Painter*
 */
eq::Painter *GetPainter();

} // namespace eq
