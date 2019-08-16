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
#pragma once

#include <equal/core/application.hpp>
#include <equal/core/game_object.hpp>
#include <equal/core/scene.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/text_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/helper/system.hpp>
#include <equal/prefab/ui/canvas.hpp>
#include <equal/world/data.hpp>

namespace eq {

/**
 * @ingroup factories
 * @brief Create a Canvas object
 *
 * @tparam T eq::GameObject a UI objects
 * @tparam Args
 * @param args Args
 * @return eq::GameObject*
 */
template <typename T, typename... Args>
T *create_canvas(Args... args) {
  T *object = new T(args...);
  ui::Canvas *canvas = GetScene()->canvas();
  canvas->GetComponent<eq::TransformComponent>()->add(canvas, object);
  return object;
}

/**
 * @brief Create a world object
 *
 * @param tile_size uint8_t
 * @param chunk_size const eq::Size&
 * @return eq::Ref<eq::World>
 */
Ref<World> create_world(const Size &tile_size = Size{32}, const Size &chunk_size = Size{16});

/**
 * @brief Create a world chunk object
 *
 * @param world eq::Ref<eq::World>&
 * @param position const eq::Position&
 * @return eq::Ref<eq::Chunk>
 */
Ref<Chunk> create_world_chunk(Ref<World> &world, const Position &position = Position{0});

/**
 * @brief Create a world floor object
 *
 * @param world eq::Ref<eq::World>&
 * @param chunk eq::Ref<eq::Chunk>&
 * @param number int
 * @return eq::Ref<eq::Floor>
 */
Ref<Floor> create_world_floor(Ref<World> &world, Ref<Chunk> &chunk, int number = 0);

/**
 * @brief Create a world tile object
 *
 * @param world eq::Ref<eq::World>&
 * @param floor eq::Ref<eq::Floor>&
 * @param position const Position&
 * @return eq::Ref<eq::Tile>
 */
Ref<Tile> create_world_tile(Ref<World> &world, Ref<Floor> &floor, const Position &position = Position{0});

/**
 * @brief Create a world thing object
 *
 * @param world eq::Ref<eq::World>&
 * @param tile eq::Ref<eq::Tile>&
 * @param id uint32_t
 * @return eq::Ref<eq::Thing>
 */
Ref<Thing> create_world_thing(Ref<World> &world, Ref<Tile> &tile, uint32_t id = 1);

/**
 * @brief Create a world tileset object
 *
 * @param world eq::Ref<eq::World>&
 * @param first_id uint32_t
 * @param texture const std::string&
 */
void create_world_tileset(Ref<World> &world, uint32_t first_id, const std::string &texture);

/**
 * @ingroup factories
 * @brief Create a Application object
 */
void create_application(const WindowOptions &options);

/**
 * @ingroup factories
 * @brief Init game
 *
 * To be defined in **client**
 */
void create_game();

} // namespace eq
