#include <equal/core/application.hpp>
#include <equal/core/painter.hpp>
#include <equal/core/scene.hpp>
#include <equal/core/window.hpp>
#include <equal/system/script_system.hpp>
#include <equal/system/component_system.hpp>
#include <equal/system/event_system.hpp>
#include <equal/helper/system.hpp>

namespace eq {

EventSystem *GetEventSystem() { return g_app.scene->event_system(); }

ComponentSystem *GetComponentSystem() { return g_app.scene->component_system(); }

ScriptSystem *GetScriptSystem() { return g_app.scene->script_system(); }

Scene *GetScene() { return g_app.scene; }

Window *GetWindow() { return g_app.window; }

Painter *GetPainter() { return g_app.painter; }

} // namespace eq
