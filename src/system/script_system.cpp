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

void ScriptSystem::update(const Timestep& timestep) {
  for (auto &[id, list] : m_scripts) {
    for (auto &[type, script] : list) {
      script->update(timestep);
    }
  }
}

void ScriptSystem::fixed_update(const Timestep& timestep) {
  for (auto &[id, list] : m_scripts) {
    for (auto &[type, script] : list) {
      script->fixed_update(timestep);
    }
  }
}

} // namespace eq
