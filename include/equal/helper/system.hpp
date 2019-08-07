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
