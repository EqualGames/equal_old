#include <equal/helper/texture.hpp>

namespace eq {

VertexPoint GetVertexTextureByID(uint32_t texture_id, const Size &tile_size, const Size &texture_size) {
  Size texture_tiles = texture_size / tile_size;
  return VertexPoint{(texture_id % texture_tiles.x) * tile_size.x, (texture_id / texture_tiles.y) * tile_size.y,
                     tile_size.x, tile_size.y};
}

Position GetTileTextureByID(uint32_t texture_id, const World &world) {
  Size texture_tiles = world.tileset_size / world.tile_size;
  return Position{((texture_id - 1) % texture_tiles.x), ((texture_id - 1) / texture_tiles.y)};
}

} // namespace eq
