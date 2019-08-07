#pragma once

#include <equal/core/input.hpp>

namespace eq {

/**
 * @ingroup events
 * @interface IOnKeyRelease
 * @brief Event interface for key release
 *
 */
class IOnKeyRelease {
public:

  /**
   * @brief Method called on key release
   * 
   * @param key eq::Keyboard::Key
   */
  virtual void onKeyRelease(eq::Keyboard::Key key) = 0;
};

} // namespace eq
