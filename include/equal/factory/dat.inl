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
#include <equal/world/data.hpp>

/**
 * @brief A custom serialize methods for boost::serialization
 */
namespace boost::serialization {

/**
 * @ingroup factories
 * @brief Serialize method for eq::Position
 */
template <class Archive>
void serialize(Archive &ar, eq::Position &data, const unsigned int version) {
  ar &data.x;
  ar &data.y;
}
/**
 * @ingroup factories
 * @brief Serialize method for eq::Size
 */
template <class Archive>
void serialize(Archive &ar, eq::Size &data, const unsigned int version) {
  ar &data.x;
  ar &data.y;
}

/**
 * @ingroup factories
 * @brief Serialize method for eq::World
 */
template <class Archive>
void serialize(Archive &ar, eq::World &data, const unsigned int version) {
  ar &data.tile_size;
  ar &data.tileset_size;
  ar &data.chunk_size;
  ar &data.tilesets;
  ar &data.chunks;
  ar &data.floors;
  ar &data.tiles;
  ar &data.things;
}

/**
 * @ingroup factories
 * @brief Serialize method for eq::Chunk
 */
template <class Archive>
void serialize(Archive &ar, eq::Chunk &data, const unsigned int version) {
  ar &data.position;
}

/**
 * @ingroup factories
 * @brief Serialize method for eq::Floor
 */
template <class Archive>
void serialize(Archive &ar, eq::Floor &data, const unsigned int version) {
  ar &data.chunk;
  ar &data.number;
}
/**
 * @ingroup factories
 * @brief Serialize method for eq::Tile
 */
template <class Archive>
void serialize(Archive &ar, eq::Tile &data, const unsigned int version) {
  ar &data.floor;
  ar &data.position;
  ar &data.flags;
}

/**
 * @ingroup factories
 * @brief Serialize method for eq::Thing
 */
template <class Archive>
void serialize(Archive &ar, eq::Thing &data, const unsigned int version) {
  ar &data.tile;
  ar &data.id;
  ar &data.type;
}

/**
 * @ingroup factories
 * @brief Serialize method for eq::ResourceDAT
 */
template <class Archive>
void serialize(Archive &ar, eq::ResourceDAT &data, const unsigned int version) {
  ar &data.textures;
  ar &data.fonts;
}

/**
 * @ingroup factories
 * @brief Serialize method for eq::FontDAT
 */
template <class Archive>
void serialize(Archive &ar, eq::FontDAT &data, const unsigned int version) {
  ar &data.name;
  ar &data.compressed;
  ar &data.buffer;
}

/**
 * @ingroup factories
 * @brief Serialize method for eq::TextureDAT
 */
template <class Archive>
void serialize(Archive &ar, eq::TextureDAT &data, const unsigned int version) {
  ar &data.name;
  ar &data.first_id;
  ar &data.width;
  ar &data.height;
  ar &data.depth;
  ar &data.pitch;
  ar &data.format;
  ar &data.compressed;
  ar &data.buffer;
}

} // namespace boost::serialization
