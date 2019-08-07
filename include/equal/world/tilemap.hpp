#pragma once

#include <string>
#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>
#include <equal/world/data.hpp>

namespace eq {

class Tilemap : public GameObject {
private:
  World *m_world{nullptr};

public:
  Tilemap(const std::string &id = "");
  Tilemap(World *world, const Position &position);
  virtual ~Tilemap();
};

} // namespace eq
