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

#include <chrono>
#include <equal/core/scene.hpp>
#include <equal/core/timestep.hpp>
#include <equal/core/window.hpp>
#include <equal/platform/platform.hpp>
#include <equal/prefab/scene/blank.hpp>
#include <memory>
#include <thread>

namespace eq {

/**
 * @ingroup core
 * @brief Application
 */
struct Application {
  Scope<Window> window;
  Scope<Painter> painter;
  Scope<Scene> scene;
  Scope<Timestep> timestep;
};

extern Application g_app;

/**
 * @brief Load scene
 *
 * @tparam T eq::Scene
 */
template <typename T>
void LoadScene() {
  g_app.scene.reset(new T());
}

/**
 * @ingroup core
 * @brief
 */
void Init();

/**
 * @ingroup core
 * @brief Close application
 */
void Quit();

} // namespace eq
