#pragma once

#include <equal/core/input.hpp>
#include <equal/core/types.hpp>

namespace eq {

/**
 * @ingroup events
 * @interface IOnMouseRelease
 * @brief Event interface for mouse release
 *
 */
class IOnMouseRelease {
public:
  /**
   * @brief Method called on mouse release
   * 
   * @param button eq::Mouse::Button
   * @param position const eq::Position&
   */
  virtual void onMouseRelease(eq::Mouse::Button button, const eq::Position &position) = 0;
};

} // namespace eq
