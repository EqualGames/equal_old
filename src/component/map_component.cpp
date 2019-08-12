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
#include <equal/component/map_component.hpp>

namespace eq {

MapComponent::MapComponent() {}

MapComponent::~MapComponent() {}

// Vertex{VertexPoint{position.x, position.y, m_tile_size.x, m_tile_size.y},
//            VertexPoint{texture.x * m_tile_size.x, texture.y * m_tile_size.y, m_tile_size.x, m_tile_size.y}}

void MapComponent::update(const Timestep& timestep) {}

void MapComponent::fixed_update(const Timestep& timestep) {}

} // namespace eq