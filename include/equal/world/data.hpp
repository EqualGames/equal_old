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

#include <equal/core/types.hpp>
#include <unordered_map>
#include <tuple>

#define continue(x) if (x) continue;

namespace eq {

/**
 * @ingroup worlds
 * @brief Chunk data structure
 */
struct Chunk {
  Position position{0};

  bool operator==(const Chunk &rhs) const { return std::tie(position) == std::tie(rhs.position); }
  bool operator!=(const Chunk &rhs) const { return std::tie(position) != std::tie(rhs.position); }
};

/**
 * @ingroup worlds
 * @brief Floor data structure
 */
struct Floor {
  Ref<Chunk> chunk;
  int number;

  bool operator==(const Floor &rhs) const { return std::tie(chunk, number) == std::tie(rhs.chunk, rhs.number); }
  bool operator!=(const Floor &rhs) const { return std::tie(chunk, number) != std::tie(rhs.chunk, rhs.number); }
};

/**
 * @ingroup worlds
 * @brief
 */
enum TileFlags : uint8_t {
  None = 1 << 0,      ///< None
  Collision = 1 << 1, ///< Has collision
};

/**
 * @ingroup worlds
 * @brief Tile data structure
 */
struct Tile {
  Ref<Floor> floor;
  Position position{0};
  uint8_t flags;
};

/**
 * @ingroup worlds
 * @brief
 */
enum ThingType : uint8_t {
  Unknown = 0, ///< Unknown
  Creature,    ///< Any creature
  Item,        ///< Any item
  NPC,         ///< Non player creature
  Monster,     ///< Monster
  Player,      ///< Player
  Wall,        ///< Any type of wall
  Ground,      ///< Any type of ground
  Roof,        ///< Any type of roof
  Door,        ///< Any type of doors
  Furniture,   ///< Any type of furnitures
  Ornament,    ///< Any type of ornaments
  Plants,      ///< Any type of plants and derivations
  Container,   ///< Item container and liquid container
  Consumible,  ///< Food, plants, herbs, potions and liquids
  Key,         ///< Key for opening doors and chests
  Tool,        ///< Picks, shovel, rope, knifes and others
  Weapon,      ///< Wands, rods, swords, axes, clubs and others
  Shield,      ///< Shields
  Codice,      ///< Books for magicians
  Helmet,      ///< Helmets, masks, tiaras, crows, hats and caps
  Armor,       ///< Armors
  Legs,        ///< Legs and kilts
  Boots,       ///< Boots, shoes and sandals
  Last = Boots ///< Get the last thing type
};

/**
 * @ingroup worlds
 * @brief Thing data structure
 */
struct Thing {
  Ref<Tile> tile;
  uint32_t id;
  ThingType type;
};

/**
 * @ingroup worlds
 * @brief World data structure
 */
struct World {
  Size tile_size{32};
  Size tileset_size{256};
  Size chunk_size{16};
  std::unordered_map<uint32_t, std::string> tilesets;
  std::vector<Ref<Chunk>> chunks;
  std::vector<Ref<Floor>> floors;
  std::vector<Ref<Tile>> tiles;
  std::vector<Ref<Thing>> things;

  const std::vector<Ref<Tile>> get_chunk_tiles(const Position &position, int floor) {
    std::vector<Ref<Tile>> chunk_tiles;
    const Ref<Tile> &ref_tile = get_tile(position, floor);

    for (const Ref<Tile> &tile : tiles) {
      continue(tile->floor != ref_tile->floor);
      chunk_tiles.emplace_back(tile);
    }

    return chunk_tiles;
  }

  Ref<Tile> get_tile(const Position &position, int floor) {
    auto it = std::find_if(tiles.begin(), tiles.end(), [position, floor](const Ref<Tile> &tile) -> bool {
      return ((tile->floor->number == floor) && (tile->position == position));
    });
    return *it;
  }

  Ref<Floor> get_floor(int number) {
    auto it = std::find_if(floors.begin(), floors.end(),
                           [number](const Ref<Floor> &floor) -> bool { return floor->number == number; });
    return *it;
  }

  Ref<Chunk> get_chunk(const Position &position) {
    auto it = std::find_if(chunks.begin(), chunks.end(),
                           [position](const Ref<Chunk> &chunk) -> bool { return chunk->position == position; });
    return *it;
  }
};

} // namespace eq
