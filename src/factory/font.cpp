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
#include <equal/factory/dat.hpp>
#include <equal/factory/font.hpp>
#include <equal/helper/error.hpp>
#include <equal/helper/string.hpp>
#include <equal/helper/system.hpp>
#ifdef EQ_SDL
#include <SDL2/SDL_ttf.h>
#endif

namespace eq {

std::unordered_map<std::string, Font *> LoadFontFromDAT() {
  std::unordered_map<std::string, Font *> fonts;

  ResourceDAT res;
  ReadDAT<ResourceDAT>("resources", res);

  for (auto &font_dat : res.fonts) {
    Font *font = new Font();
    font->name = fmt::format("{0}_{1}", font_dat.name, 16);

#ifdef EQ_SDL
    TTF_Font *sdl_font = TTF_OpenFontRW(SDL_RWFromMem(font_dat.buffer.data(), font_dat.buffer.size()), 1, 16);

    if (!sdl_font) {
      TTF_CloseFont(sdl_font);
      EQ_THROW("Can't load font({}): {}", font->name, TTF_GetError());
    }

    font->data = static_cast<void *>(sdl_font);
#endif

    fonts.try_emplace(font->name, font);
  }

  return fonts;
}

} // namespace eq
