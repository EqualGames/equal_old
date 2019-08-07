#include <equal/factory/map.hpp>

namespace eq {

Size GetTilesInViewport(const Size &viewport, const Size &tile_size) {
  return Size{viewport.x / tile_size.x + 1, viewport.y / tile_size.y + 1};
}

} // namespace eq
