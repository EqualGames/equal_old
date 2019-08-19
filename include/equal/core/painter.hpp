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

#include <equal/component/renderer_component.hpp>
#include <equal/component/text_component.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/core/game_object.hpp>
#include <equal/core/scene.hpp>
#include <equal/core/types.hpp>

namespace eq {

/**
 * @ingroup core
 * @brief Painter manager to draw elements
 */
class Painter {
private:
  void recursive(const Ref<GameObject> &object);
  virtual void draw(const TextComponent &text, const TransformComponent &transform) = 0;
  virtual void draw(const RendererComponent &renderer, const TransformComponent &transform) = 0;

public:
  /**
   * @brief Create a manager based on selected platform
   *
   * @param options eq::WindowOptions
   * @return eq::Scope<eq::Painter>
   */
  static Scope<Painter> create(const WindowOptions &options = WindowOptions{});

  /**
   * @brief Destroy the Painter
   *
   */
  virtual ~Painter() = default;

  /**
   * @brief Clear screen with color
   *
   * @param color const eq::Color&
   */
  virtual void clear(const Color &color = Color{0, 0, 0, 255}) const = 0;

  /**
   * @brief Display elements in screen
   */
  virtual void display() const = 0;

  /**
   * @brief Get painter object
   *
   * @return void*
   */
  virtual void *native_painter() const = 0;

  /**
   * @brief Draw scene and your elements
   *
   * @param scene const eq::Scope<eq::Scene>&
   */
  void draw(const Scope<Scene> &scene);

  /**
   * @brief Draw game object and your children
   *
   * @param object const eq::Ref<eq::GameObject>&
   */
  void draw(const Ref<GameObject> &object);
};

} // namespace eq
