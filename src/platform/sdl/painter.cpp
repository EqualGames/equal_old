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
#ifdef EQ_SDL
#include <equal/core/logger.hpp>
#include <equal/core/application.hpp>
#include <equal/core/resource.hpp>
#include <equal/core/painter.hpp>
#include <equal/helper/error.hpp>
#include <equal/helper/system.hpp>
#include <equal/helper/string.hpp>
#include <equal/platform/sdl/painter.hpp>

namespace eq {

Painter *Painter::create(const WindowOptions &options) { return new Painter_SDL(options); }

Painter_SDL::Painter_SDL(const WindowOptions &options) : Painter() {
  m_scale = options.scale;

  m_window = static_cast<SDL_Window *>(GetWindow()->native_window());
  if (!m_window) {
    SDL_DestroyWindow(m_window);
    EQ_THROW("Can't access the window");
  }

  uint32_t renderer_flags = SDL_RENDERER_SOFTWARE;
  if (options.vsync) {
    renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  }
  m_renderer = SDL_CreateRenderer(m_window, -1, renderer_flags);
  if (!m_renderer) {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    EQ_THROW("Can't create renderer: {}", SDL_GetError());
  }

  if (TTF_Init() != 0) {
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    EQ_THROW("Unable to initialize TTF: {}", TTF_GetError());
  }
}

Painter_SDL::~Painter_SDL() {
  TTF_Quit();
  SDL_DestroyRenderer(m_renderer);
}

void *Painter_SDL::native_painter() const { return m_renderer; }

void Painter_SDL::display() const { SDL_RenderPresent(m_renderer); }

void Painter_SDL::clear(const Color &color) const {
  SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
  SDL_RenderClear(m_renderer);
}

void Painter_SDL::draw(const RendererComponent &renderer, const TransformComponent &transform) {
  glm::ivec2 size{transform.size()};
  glm::ivec2 position{transform.position()};
  glm::ivec2 origin{transform.origin()};

  SDL_Rect obj_rect;
  obj_rect.x = position.x - origin.x;
  obj_rect.y = position.y - origin.y;
  obj_rect.w = size.x;
  obj_rect.h = size.y;

  if (renderer.vao().empty()) {
    if (SDL_SetRenderDrawColor(m_renderer, renderer.color().r, renderer.color().g, renderer.color().b,
                               renderer.color().a) != 0) {
      EQ_THROW("Can't draw game object: {}", SDL_GetError());
    }

    if (SDL_RenderFillRect(m_renderer, &obj_rect) != 0) {
      EQ_THROW("Can't draw game object: {}", SDL_GetError());
    }
  } else if (!renderer.texture()) {
    for (auto &vertex : renderer.vao()) {
      glm::ivec4 quad{vertex[0]};

      SDL_Rect quad_rect;
      quad_rect.x = obj_rect.x + quad.x;
      quad_rect.y = obj_rect.y + quad.y;
      quad_rect.w = quad.z;
      quad_rect.h = quad.w;

      if (SDL_SetRenderDrawColor(m_renderer, renderer.color().r, renderer.color().g, renderer.color().b,
                                 renderer.color().a) != 0) {
        EQ_THROW("Can't draw game object: {}", SDL_GetError());
      }

      if (SDL_RenderFillRect(m_renderer, &quad_rect) != 0) {
        EQ_THROW("Can't draw game object: {}", SDL_GetError());
      }
    }
  } else {
    for (auto &vertex : renderer.vao()) {
      glm::ivec4 quad{vertex[0]};
      glm::ivec4 tex{vertex[1]};

      SDL_Rect quad_rect;
      quad_rect.x = obj_rect.x + quad.x;
      quad_rect.y = obj_rect.y + quad.y;
      quad_rect.w = quad.z;
      quad_rect.h = quad.w;

      SDL_Rect tex_rect;
      tex_rect.x = tex.x;
      tex_rect.y = tex.y;
      tex_rect.w = tex.z;
      tex_rect.h = tex.w;

      if (SDL_SetTextureColorMod(static_cast<SDL_Texture *>(renderer.texture()->data()), renderer.color().r,
                                 renderer.color().g, renderer.color().b) != 0) {
        EQ_THROW("Can't draw game object: {}", SDL_GetError());
      }

      if (SDL_RenderCopy(m_renderer, static_cast<SDL_Texture *>(renderer.texture()->data()), &tex_rect, &quad_rect) !=
          0) {
        EQ_THROW("Can't draw game object: {}", SDL_GetError());
      }
    }
  }
}

void Painter_SDL::draw(const TextComponent &text, const TransformComponent &transform) {
  glm::ivec2 origin{transform.origin()};
  glm::ivec2 position{transform.position()};
  glm::ivec2 size{transform.size()};

  SDL_Color color;
  color.r = text.color().r;
  color.g = text.color().g;
  color.b = text.color().b;
  color.a = text.color().a;

  std::string text_value = str::wchar_to_utf8(text.text().c_str());

  SDL_Surface *surface =
      TTF_RenderUTF8_Blended(static_cast<TTF_Font *>(text.font()->data()), text_value.c_str(), color);
  if (!surface) {
    EQ_THROW("Can't draw game object: {}", TTF_GetError());
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
  if (!texture) {
    SDL_FreeSurface(surface);
    EQ_THROW("Can't draw game object: {}", SDL_GetError());
  }

  SDL_Rect quad_rect;
  quad_rect.x = position.x - origin.x;
  quad_rect.y = position.y - origin.y;
  quad_rect.w = size.x;
  quad_rect.h = size.y;

  if (SDL_RenderCopy(m_renderer, texture, &surface->clip_rect, &quad_rect) != 0) {
    SDL_DestroyTexture(texture);
    EQ_THROW("Can't draw game object: {}", SDL_GetError());
  }

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}

} // namespace eq

#endif
