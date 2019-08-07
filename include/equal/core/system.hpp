#pragma once

#include <equal/core/timestep.hpp>

namespace eq {

/**
 * @defgroup systems Systems
 * @ingroup core
 * @brief Systems definitions
 */

/**
 * @ingroup core
 * @brief System base
 */
class System {
public:
  virtual ~System() { end(); };

  virtual void start(){};
  virtual void end(){};
  virtual void update(const Timestep& timestep){};
  virtual void fixed_update(const Timestep& timestep){};
};

} // namespace eq
