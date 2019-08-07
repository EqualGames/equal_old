#include <equal/component/map_component.hpp>

namespace eq {

MapComponent::MapComponent() {}

MapComponent::~MapComponent() {}

// Vertex{VertexPoint{position.x, position.y, m_tile_size.x, m_tile_size.y},
//            VertexPoint{texture.x * m_tile_size.x, texture.y * m_tile_size.y, m_tile_size.x, m_tile_size.y}}

void MapComponent::update(const Timestep& timestep) {}

void MapComponent::fixed_update(const Timestep& timestep) {}

} // namespace eq
