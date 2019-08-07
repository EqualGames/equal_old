#pragma once

#include <equal/core/input.hpp>
#include <equal/core/types.hpp>

namespace eq {

/**
 * @ingroup events
 * @interface IOnMousePress
 * @brief Event interface for mouse press
 *
 */
class IOnMousePress {
public:
  /**
   * @brief Method called on mouse press
   * 
   * @param button eq::Mouse::Button
   * @param position const eq::Position&
   */
  virtual void onMousePress(eq::Mouse::Button button, const eq::Position &position) = 0;
};

} // namespace eq
