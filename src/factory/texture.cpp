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

#include <equal/core/logger.hpp>
#include <equal/core/painter.hpp>
#include <equal/helper/error.hpp>
#include <equal/helper/string.hpp>
#include <equal/helper/system.hpp>
#include <equal/factory/dat.hpp>
#include <equal/factory/texture.hpp>
#ifdef EQ_SDL
#include <SDL2/SDL.h>
#endif

namespace eq {

std::unordered_map<std::string, Texture *> LoadTextureFromDAT() {
  std::unordered_map<std::string, Texture *> textures;

  ResourceDAT res;
  ReadDAT<ResourceDAT>("resources", res);

  for (auto &texture_dat : res.textures) {
    Texture *texture = new Texture();
    texture->name = texture_dat.name;
    texture->size = Size{texture_dat.width, texture_dat.height};

#ifdef EQ_SDL
    SDL_Surface *sdl_surface =
        SDL_CreateRGBSurfaceWithFormatFrom(texture_dat.buffer.data(), texture_dat.width, texture_dat.height,
                                           texture_dat.depth, texture_dat.pitch, texture_dat.format);
    if (!sdl_surface) {
      SDL_FreeSurface(sdl_surface);
      EQ_THROW("Can't create surface: {}", SDL_GetError());
    }

    Uint32 colorkey = SDL_MapRGB(sdl_surface->format, 255, 0, 255);
    if (SDL_SetColorKey(sdl_surface, SDL_TRUE, colorkey) != 0) {
      SDL_FreeSurface(sdl_surface);
      EQ_THROW("Can't set color key: {}", SDL_GetError());
    }

    SDL_Renderer *sdl_renderer = static_cast<SDL_Renderer *>(GetPainter()->native_painter());
    if (!sdl_renderer) {
      SDL_FreeSurface(sdl_surface);
      EQ_THROW("Can't access the renderer");
    }

    SDL_Texture *sdl_texture = SDL_CreateTextureFromSurface(sdl_renderer, sdl_surface);
    SDL_FreeSurface(sdl_surface);
    if (!sdl_texture) {
      EQ_THROW("Can't create texture: {}", SDL_GetError());
    }

    texture->data = static_cast<void *>(sdl_texture);
#endif
    textures.try_emplace(texture->name, texture);
  }

  return textures;
}

} // namespace eq
