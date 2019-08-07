#pragma once

#include <string>
#include <unordered_map>
#include <typeindex>
#include <equal/core/script.hpp>
#include <equal/core/system.hpp>

namespace eq {

/**
 * @ingroup systems
 * @brief System to manager scripts attached in game objects
 */
class ScriptSystem : public System {
private:
  std::unordered_map<std::string, std::unordered_map<std::type_index, Script *>> m_scripts;

public:
  bool has(const std::string &id) const;
  const std::unordered_map<std::type_index, Script *> &get_all(const std::string &id) const;

  template <class T>
  bool has_type(const std::string &id) const {
    if (has(id)) {
      auto list = get_all(id);
      return list.find(std::type_index(typeid(T))) != list.end();
    }

    return false;
  }

  template <class T>
  T *get(const std::string &id) const {
    for (auto &[type, script] : get_all(id)) {
      if (type == std::type_index(typeid(T))) {
        return static_cast<T *>(script);
      }
    }
    return nullptr;
  }

  template <class T>
  void add(const std::string &id, Script *script) {
    if (has(id)) {
      m_scripts.at(id).try_emplace(std::type_index(typeid(T)), script);
    } else {
      std::unordered_map<std::type_index, Script *> list;
      list.try_emplace(std::type_index(typeid(T)), script);
      m_scripts.try_emplace(id, list);
    }
  }

  void start() override;
  void end() override;
  void update(const Timestep &timestep) override;
  void fixed_update(const Timestep &timestep) override;
};

} // namespace eq
