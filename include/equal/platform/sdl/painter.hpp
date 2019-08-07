#pragma once

#ifdef EQ_SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <equal/core/types.hpp>
#include <equal/core/painter.hpp>

namespace eq {

/**
 * @ingroup sdl
 * @brief SDL Render
 */
class Painter_SDL : public Painter {
private:
  SDL_Window *m_window{nullptr};
  SDL_Renderer *m_renderer{nullptr};
  float m_scale{0};

  void draw(const TextComponent &text, const TransformComponent &transform);
  void draw(const RendererComponent &renderer, const TransformComponent &transform);

public:
  Painter_SDL(const WindowOptions &options);
  ~Painter_SDL();

  void *native_painter() const;
  void clear(const Color &color = Color{0, 0, 0, 255}) const;
  void display() const;
};

} // namespace eq

#endif
