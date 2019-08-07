#pragma once

namespace eq {

class GameObject;

/**
 * @defgroup commands Commands
 * @ingroup core
 * @brief Commands definitions
 */

/**
 * @ingroup core
 * @brief Command base
 */
class Command {
public:
  virtual ~Command();

  virtual void execute(GameObject *object) = 0;
};

} // namespace eq
