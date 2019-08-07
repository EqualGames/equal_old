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
