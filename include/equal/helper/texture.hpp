#pragma once

#include <equal/core/types.hpp>
#include <equal/world/data.hpp>

namespace eq {

/**
 * @ingroup helpers
 * @brief Get the Tile Texture By ID object
 *
 * @param texture_id unsigned int
 * @param tile_size const eq::Size &
 * @param texture_size const eq::Size &
 * @return eq::VertexPoint
 */
VertexPoint GetVertexTextureByID(uint32_t texture_id, const Size &tile_size, const Size &texture_size);

/**
 * @brief Get the Tile Texture By ID object
 *
 * @param texture_id uint32_t
 * @param world const eq::World&
 * @return eq::Position
 */
Position GetTileTextureByID(uint32_t texture_id, const World &world);

} // namespace eq
