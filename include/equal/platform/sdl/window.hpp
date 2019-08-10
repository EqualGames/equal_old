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
#include <string>
#include <equal/core/types.hpp>
#include <equal/core/window.hpp>
#include <SDL2/SDL.h>

namespace eq {

/**
 * @ingroup sdl
 * @brief SDL Window
 */
class Window_SDL : public Window {
private:
  SDL_Window *m_window{nullptr};
  bool m_running{false};

public:
  Window_SDL(const WindowOptions &options);
  ~Window_SDL();

  bool opened() const;
  void *native_window() const;
  void shutdown();
  void title(const std::string &title);
  const Size &size() const;
  void size(const Size &size);
  void update();
  float time() const;
};

} // namespace eq

#endif
