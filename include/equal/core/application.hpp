#pragma once

#include <chrono>
#include <thread>
#include <memory>
#include <equal/core/window.hpp>
#include <equal/core/scene.hpp>
#include <equal/core/timestep.hpp>
#include <equal/prefab/scene/blank.hpp>
#include <equal/platform/platform.hpp>

namespace eq {

/**
 * @ingroup core
 * @brief Application
 */
struct Application {
  Window *window{nullptr};
  Painter *painter{nullptr};
  Scene *scene{nullptr};
  Timestep *timestep{nullptr};
};

extern Application g_app;

/**
 * @brief Load scene
 *
 * @tparam T eq::Scene
 */
template <typename T>
void LoadScene() {
  delete g_app.scene;
  g_app.scene = new T();
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
