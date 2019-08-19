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

#ifdef EQ_SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <equal/core/painter.hpp>
#include <equal/core/types.hpp>

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
