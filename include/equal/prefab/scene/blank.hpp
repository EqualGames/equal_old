#pragma once

#include <equal/core/scene.hpp>

namespace eq {

/**
 * @ingroup scenes
 * @brief Default empty scene
 */
class BlankScene : public Scene {
public:
  void start() override;
  void update(eq::World *world, const eq::Timestep &timestep);
  void fixed_update(eq::World *world, const eq::Timestep &timestep);
  void end() override;
};

} // namespace eq
