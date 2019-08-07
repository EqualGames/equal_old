#pragma once

#include <equal/core/timestep.hpp>

namespace eq {

class GameObject;

/**
 * @defgroup components Components
 * @ingroup core
 * @brief Components definitions
 */

/**
 * @brief Component Base
 * @ingroup core
 */
class Component {
protected:
  GameObject *m_target{nullptr};

public:
  virtual ~Component();

  void target(GameObject *target);

  virtual void update(const Timestep &timestep) = 0;
  virtual void fixed_update(const Timestep &timestep) = 0;
};

} // namespace eq
