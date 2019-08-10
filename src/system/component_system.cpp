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
#include <equal/helper/error.hpp>
#include <equal/system/component_system.hpp>

namespace eq {

void ComponentSystem::start() {}

void ComponentSystem::end() { m_components.clear(); }

bool ComponentSystem::has(const std::string &id) const { return m_components.find(id) != m_components.end(); }

const std::unordered_map<std::type_index, Component *> &ComponentSystem::get_all(const std::string &id) const {
  if (has(id)) {
    return m_components.at(id);
  }

  EQ_THROW("Invalid game object id");
}

void ComponentSystem::update(const Timestep& timestep) {
  for (auto &[id, list] : m_components) {
    for (auto &[type, component] : list) {
      component->update(timestep);
    }
  }
}

void ComponentSystem::fixed_update(const Timestep& timestep) {
  for (auto &[id, list] : m_components) {
    for (auto &[type, component] : list) {
      component->fixed_update(timestep);
    }
  }
}

} // namespace eq
