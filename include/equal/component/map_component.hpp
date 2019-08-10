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

#include <string>
#include <unordered_map>
#include <equal/core/types.hpp>
#include <equal/core/component.hpp>
#include <equal/world/data.hpp>

namespace eq {

/**
 * @ingroup components
 * @brief 
 */
class MapComponent : public Component {
private:
  Size m_tile_size{64};
  std::unordered_map<std::string, VertexArray> m_layers; // <texture, vertex_array>
  bool m_need_update{true};

public:
  MapComponent();
  virtual ~MapComponent();

  void update(const Timestep& timestep);
  void fixed_update(const Timestep& timestep);
};

} // namespace eq
