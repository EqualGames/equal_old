#pragma once

#include <equal/core/scene.hpp>
#include <equal/core/game_object.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/component/text_component.hpp>

namespace eq {

/**
 * @ingroup core
 * @brief Painter manager to draw elements
 */
class Painter {
private:
  void recursive(const GameObject &object);
  virtual void draw(const TextComponent &text, const TransformComponent &transform) = 0;
  virtual void draw(const RendererComponent &renderer, const TransformComponent &transform) = 0;

public:
  /**
   * @brief Create a manager based on selected platform
   *
   * @param options eq::WindowOptions
   * @return eq::Painter*
   */
  static eq::Painter *create(const WindowOptions &options = WindowOptions{});

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
   * @param scene const eq::Scene&
   */
  void draw(const Scene &scene);

  /**
   * @brief Draw game object and your children
   * 
   * @param object const eq::GameObject&
   */
  void draw(const GameObject &object);
};

} // namespace eq
