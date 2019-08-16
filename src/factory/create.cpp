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
#include <equal/core/logger.hpp>
#include <equal/factory/create.hpp>
#include <equal/core/application.hpp>
#include <memory>

namespace eq {

void create_application(const WindowOptions &options) {
  g_app.window = Window::create(options);
  g_app.painter = Painter::create(options);
  g_app.scene.reset(new BlankScene());
  g_app.timestep = std::make_unique<Timestep>();

#ifdef EQ_SDL
  // Informations
  EQ_CORE_INFO("Base path: {}", SDL_GetBasePath());
  EQ_CORE_INFO("Platform: {}", SDL_GetPlatform());
  EQ_CORE_INFO("Number of logical CPU cores: {}", SDL_GetCPUCount());
  EQ_CORE_INFO("Number of line size CPU cache: {}", SDL_GetCPUCacheLineSize());
  EQ_CORE_INFO("Number of system RAM: {}", SDL_GetSystemRAM());
  auto audio = SDL_GetCurrentAudioDriver();
  EQ_CORE_INFO("Audio device: {}", audio ? audio : "none");
  auto video = SDL_GetCurrentVideoDriver();
  EQ_CORE_INFO("Video driver: {}", video ? video : "none");
  {
    SDL_RendererInfo info;
    SDL_GetRenderDriverInfo(0, &info);
    int major_version, minor_version;
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &major_version);
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &minor_version);

    EQ_CORE_INFO("Render: {}", info.name);
    EQ_CORE_INFO("Render version: {}.{}", major_version, minor_version);
    EQ_CORE_INFO("Max texture width: {}", info.max_texture_width);
    EQ_CORE_INFO("Max texture height: {}", info.max_texture_height);
  }

  EQ_CORE_INFO("Creating window {} x {}", options.size.x, options.size.y);
#endif
}

Ref<World> create_world(const Size &tile_size, const Size &chunk_size) {
  Ref<World> world = std::make_shared<World>();
  world->tile_size = tile_size;
  world->chunk_size = chunk_size;
  return world;
}

Ref<Chunk> create_world_chunk(Ref<World> &world, const Position &position) {
  Ref<Chunk> chunk = std::make_shared<Chunk>();
  chunk->position = position;
  world->chunks.emplace_back(chunk);
  return chunk;
}

Ref<Floor> create_world_floor(Ref<World> &world, Ref<Chunk> &chunk, int number) {
  Ref<Floor> floor = std::make_shared<Floor>();
  floor->chunk = chunk;
  floor->number = number;
  world->floors.emplace_back(floor);
  return floor;
}

Ref<Tile> create_world_tile(Ref<World> &world, Ref<Floor> &floor, const Position &position) {
  Ref<Tile> tile = std::make_shared<Tile>();
  tile->floor = floor;
  tile->position = position;
  world->tiles.emplace_back(tile);
  return tile;
}

Ref<Thing> create_world_thing(Ref<World> &world, Ref<Tile> &tile, uint32_t id) {
  Ref<Thing> thing = std::make_shared<Thing>();
  thing->id = id;
  thing->tile = tile;
  world->things.emplace_back(thing);
  return thing;
}

void create_world_tileset(Ref<World> &world, uint32_t first_id, const std::string &texture) {
  world->tilesets.try_emplace(first_id, texture);
}

} // namespace eq
