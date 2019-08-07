#pragma once

#include <equal/core/input.hpp>

namespace eq {

/**
 * @ingroup events
 * @interface IOnKeyPress
 * @brief Event interface for key press
 */
class IOnKeyPress {
public:
  /**
   * @brief Method called on key pess
   * 
   * @param key eq::Keyboard::Key
   */
  virtual void onKeyPress(eq::Keyboard::Key key) = 0;
};

} // namespace eq
