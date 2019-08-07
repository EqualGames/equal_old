#pragma once

#include <string>
#include <equal/core/types.hpp>

namespace eq {

/**
 * @ingroup core
 * @brief Window base class
 */
class Window {
protected:
  eq::WindowOptions m_options;
  bool m_capture_events{false};

public:
  /**
   * @brief Create a window based on selected platform
   *
   * @param options const eq::WindowOptions &
   * @return eq::Window*
   */
  static eq::Window *create(const eq::WindowOptions &options = eq::WindowOptions{});

  /**
   * @brief Destroy the Window object
   */
  virtual ~Window() = default;

  /**
   * @brief Get window options
   *
   * @return const eq::WindowOptions&
   */
  inline const eq::WindowOptions &options() const { return m_options; }

  /**
   * @brief Enable or disable capture events
   */
  inline void capture_events(bool capture) { m_capture_events = capture; }

  /**
   * @brief Check if capture events is enabled or disabled
   *
   * @return bool
   */
  inline bool capture_events() const { return m_capture_events; }

  /**
   * @brief Return if window is opened
   *
   * @return bool
   */
  virtual bool opened() const = 0;

  /**
   * @brief Get native window object
   *
   * @return void*
   */
  virtual void *native_window() const = 0;

  /**
   * @brief Set window title
   *
   * @param title const std::string&
   */
  virtual void title(const std::string &title) = 0;

  /**
   * @brief
   *
   * @return const Size&
   */
  virtual const Size &size() const = 0;

  /**
   * @brief Set window size
   *
   * @param size const eq::Size&
   */
  virtual void size(const eq::Size &size) = 0;

  /**
   * @brief Close window
   */
  virtual void shutdown() = 0;

  /**
   * @brief Window update and poll events
   */
  virtual void update() = 0;

  /**
   * @brief Get window ticks
   *
   * @return float
   */
  virtual float time() const = 0;
};

} // namespace eq
