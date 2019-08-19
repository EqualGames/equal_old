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
#include <equal/system/script_system.hpp>

namespace eq {

void ScriptSystem::start() {
  for (auto &[id, list] : m_scripts) {
    for (auto &[type, script] : list) {
      script->start();
    }
  }
}

void ScriptSystem::end() {
  for (auto &[id, list] : m_scripts) {
    for (auto &[type, script] : list) {
      script->end();
    }
  }

  m_scripts.clear();
}

bool ScriptSystem::has(const std::string &id) const { return m_scripts.find(id) != m_scripts.end(); }

const std::unordered_map<std::type_index, Script *> &ScriptSystem::get_all(const std::string &id) const {
  if (has(id)) {
    return m_scripts.at(id);
  }

  EQ_THROW("Invalid game object id");
}

void ScriptSystem::update(const Timestep &timestep) {
  for (auto &[id, list] : m_scripts) {
    for (auto &[type, script] : list) {
      script->update(timestep);
    }
  }
}

void ScriptSystem::fixed_update(const Timestep &timestep) {
  for (auto &[id, list] : m_scripts) {
    for (auto &[type, script] : list) {
      script->fixed_update(timestep);
    }
  }
}

} // namespace eq
