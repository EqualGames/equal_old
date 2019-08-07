#pragma once

/**
 * @defgroup core Core
 * @brief Core classes and structures of engine.
 */

#include <equal/core/application.hpp>
#include <equal/core/component.hpp>
#include <equal/core/game_object.hpp>
#include <equal/core/input.hpp>
#include <equal/core/logger.hpp>
#include <equal/core/painter.hpp>
#include <equal/core/resource.hpp>
#include <equal/core/scene.hpp>
#include <equal/core/script.hpp>
#include <equal/core/system.hpp>
#include <equal/core/timestep.hpp>
#include <equal/core/types.hpp>
#include <equal/core/window.hpp>

#include <equal/component/map_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/component/text_component.hpp>
#include <equal/component/transform_component.hpp>

/**
 * @defgroup factories Factories
 * @brief Factories definitions
 */
#include <equal/factory/create.hpp>
#include <equal/factory/dat.hpp>
#include <equal/factory/font.hpp>
#include <equal/factory/texture.hpp>
#include <equal/factory/map.hpp>

/**
 * @defgroup helpers Helpers
 * @brief Helpers definitions
 */
#include <equal/helper/error.hpp>
#include <equal/helper/guid.hpp>
#include <equal/helper/math.hpp>
#include <equal/helper/parser.hpp>
#include <equal/helper/system.hpp>
#include <equal/helper/string.hpp>
#include <equal/helper/texture.hpp>

/**
 * @defgroup prefabs Prefabs
 * @brief Prefabs definitions
 */
#include <equal/prefab/ui/ui.hpp>
#include <equal/prefab/scene/blank.hpp>

/**
 * @defgroup worlds Worlds
 * @brief Worlds definitions
 */
#include <equal/world/data.hpp>
#include <equal/world/tilemap.hpp>
