#pragma once

#include <equal/core/types.hpp>

namespace eq {

/**
 * @ingroup events
 * @interface IOnMouseMove
 * @brief Event interface for mouse move
 *
 */
class IOnMouseMove {
public:
  /**
   * @brief Method called on mouse move
   *
   * @param position const eq::Position&
   */
  virtual void onMouseMove(const eq::Position &position) = 0;
};

} // namespace eq
