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
#include <equal/core/scene.hpp>
#include <equal/helper/error.hpp>
#include <equal/helper/string.hpp>
#include <equal/helper/system.hpp>
#include <equal/platform/sdl/input.hpp>
#include <equal/platform/sdl/window.hpp>

namespace eq {

Scope<Window> Window::create(const WindowOptions &options) { return std::make_unique<Window_SDL>(options); }

Window_SDL::Window_SDL(const WindowOptions &options) : Window() {
  m_options = options;

  SDL_SetMainReady();
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    EQ_THROW("Unable to initialize SDL: {}", SDL_GetError());
  }

  m_window = SDL_CreateWindow(options.title.c_str(),  // title
                              SDL_WINDOWPOS_CENTERED, // position x
                              SDL_WINDOWPOS_CENTERED, // position y
                              options.size.x,         // width
                              options.size.y,         // height
                              SDL_WINDOW_SHOWN        // flags
  );

  if (!m_window) {
    SDL_DestroyWindow(m_window);
    EQ_THROW("Couldn't create window: {}", SDL_GetError());
  }

  m_running = true;
}

Window_SDL::~Window_SDL() { SDL_DestroyWindow(m_window); }

bool Window_SDL::opened() const { return m_running; }

void *Window_SDL::native_window() const { return m_window; }

void Window_SDL::shutdown() {
  if (m_running) {
    m_running = false;
  }
}

void Window_SDL::title(const std::string &title) {
  m_options.title = title;
  SDL_SetWindowTitle(m_window, title.c_str());
}

const Size &Window_SDL::size() const { return m_options.size; }

void Window_SDL::size(const Size &size) {
  m_options.size = size;
  SDL_SetWindowSize(m_window, size.x, size.y);
}

float Window_SDL::time() const { return SDL_GetTicks() / 1000.0f; }

void Window_SDL::update() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_WINDOWEVENT) {
      if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
        shutdown();
      }
    }

    // If capture events is enabled
    if (m_capture_events) {
      if (event.type == SDL_MOUSEMOTION) {
        SDL_MouseMotionEvent data = event.motion;
        GetEventSystem()->onMouseMove(Position{data.x, data.y});
      } else if (event.type == SDL_MOUSEBUTTONDOWN) {
        SDL_MouseButtonEvent data = event.button;
        GetEventSystem()->onMousePress(eq::Mouse::from(data.button), Position{data.x, data.y});
      } else if (event.type == SDL_MOUSEBUTTONUP) {
        SDL_MouseButtonEvent data = event.button;
        GetEventSystem()->onMouseRelease(eq::Mouse::from(data.button), Position{data.x, data.y});
      } else if (event.type == SDL_KEYDOWN) {
        SDL_KeyboardEvent data = event.key;
        GetEventSystem()->onKeyPress(eq::Keyboard::from(data.keysym.sym));
      } else if (event.type == SDL_KEYUP) {
        SDL_KeyboardEvent data = event.key;
        GetEventSystem()->onKeyRelease(eq::Keyboard::from(data.keysym.sym));
      } else if (event.type == SDL_TEXTINPUT) {
        SDL_TextInputEvent data = event.text;
        // if (data.text >= 32) {
        std::wstring text = str::utf8_to_wchar(data.text);
        GetEventSystem()->onInsertText(text);
        // }
      }
    }
  }
}

} // namespace eq

#endif
