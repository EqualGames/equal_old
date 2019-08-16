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
#include <equal/core/application.hpp>
#include <equal/core/painter.hpp>
#include <equal/core/scene.hpp>
#include <equal/core/window.hpp>
#include <equal/system/script_system.hpp>
#include <equal/system/component_system.hpp>
#include <equal/system/event_system.hpp>
#include <equal/helper/system.hpp>

namespace eq {

const Scope<EventSystem> &GetEventSystem() { return g_app.scene->event_system(); }

const Scope<ComponentSystem> &GetComponentSystem() { return g_app.scene->component_system(); }

const Scope<ScriptSystem> &GetScriptSystem() { return g_app.scene->script_system(); }

const Scope<Scene> &GetScene() { return g_app.scene; }

const Scope<Window> &GetWindow() { return g_app.window; }

const Scope<Painter> &GetPainter() { return g_app.painter; }

} // namespace eq
