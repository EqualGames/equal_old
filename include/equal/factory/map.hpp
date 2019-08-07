#pragma once

#include <equal/core/types.hpp>

namespace eq {

/**
 * @ingroup factories
 * @brief Get the Tiles In Viewport object
 *
 * @param viewport const eq::Size&
 * @param tile_size const eq::Size&
 * @return eq::Size
 */
eq::Size GetTilesInViewport(const eq::Size &viewport, const eq::Size &tile_size);

} // namespace eq
