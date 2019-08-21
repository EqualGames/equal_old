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

bool ComponentSystem::has(const std::string &guid) const { return m_components.find(guid) != m_components.end(); }

const std::unordered_map<std::type_index, Component *> &ComponentSystem::get_all(const std::string &guid) const {
  if (m_components.empty()) {
    EQ_THROW("Can't find components, because no have any component instantiated.");
  }

  if (has(guid)) {
    return m_components.at(guid);
  }

  EQ_THROW("Invalid game object guid({})", guid);
}

void ComponentSystem::update(const Timestep &timestep) {
  for (auto &[guid, list] : m_components) {
    for (auto &[type, component] : list) {
      if (component->active()) {
        component->update(timestep);
      }
    }
  }
}

void ComponentSystem::fixed_update(const Timestep &timestep) {
  for (auto &[guid, list] : m_components) {
    for (auto &[type, component] : list) {
      if (component->active()) {
        component->fixed_update(timestep);
      }
    }
  }
}

} // namespace eq
