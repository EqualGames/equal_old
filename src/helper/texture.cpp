/*
 * Copyright 2019 Equal Games
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
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
