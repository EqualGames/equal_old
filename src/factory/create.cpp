#include <equal/core/logger.hpp>
#include <equal/factory/create.hpp>
#include <equal/core/application.hpp>

namespace eq {

void create_application(const WindowOptions &options) {
  g_app.window = Window::create(options);
  g_app.painter = Painter::create(options);
  g_app.scene = new BlankScene();
  g_app.timestep = new Timestep();

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

World *create_world(const Size &tile_size, const Size &chunk_size) {
  World *world = new World;
  world->tile_size = tile_size;
  world->chunk_size = chunk_size;
  return world;
}

Chunk *create_world_chunk(World *world, const Position &position) {
  Chunk *chunk = new Chunk;
  chunk->position = position;
  world->chunks.emplace_back(chunk);
  return chunk;
}

Floor *create_world_floor(World *world, Chunk *chunk, int number) {
  Floor *floor = new Floor;
  floor->chunk = chunk;
  floor->number = number;
  world->floors.emplace_back(floor);
  return floor;
}

Tile *create_world_tile(World *world, Floor *floor, const Position &position) {
  Tile *tile = new Tile;
  tile->floor = floor;
  tile->position = position;
  world->tiles.emplace_back(tile);
  return tile;
}

Thing *create_world_thing(World *world, Tile *tile, uint32_t id) {
  Thing *thing = new Thing;
  thing->id = id;
  thing->tile = tile;
  world->things.emplace_back(thing);
  return thing;
}

void create_world_tileset(World *world, uint32_t first_id, const std::string &texture) {
  world->tilesets.try_emplace(first_id, texture);
}

} // namespace eq
