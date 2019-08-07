#include <equal/world/tilemap.hpp>
#include <equal/component/map_component.hpp>

namespace eq {

Tilemap::Tilemap(const std::string &id): GameObject(id) {
  name("Tilemap");

  AddComponent<MapComponent>();
  // AddScript<MapScript>();
}

Tilemap::Tilemap(World *world, const Position &position) {
  name("Tilemap");

  AddComponent<MapComponent>();
  // AddScript<MapScript>();
}

Tilemap::~Tilemap() {}

} // namespace eq
