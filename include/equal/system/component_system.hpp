#pragma once

#include <string>
#include <unordered_map>
#include <typeindex>
#include <type_traits>
#include <equal/core/system.hpp>
#include <equal/core/component.hpp>

namespace eq {

/**
 * @ingroup systems
 * @brief System to manager components
 */
class ComponentSystem : public System {
private:
  std::unordered_map<std::string, std::unordered_map<std::type_index, Component *>> m_components;

public:
  bool has(const std::string &id) const;
  const std::unordered_map<std::type_index, Component *> &get_all(const std::string &id) const;

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
    for (auto &[type, component] : get_all(id)) {
      if (type == std::type_index(typeid(T))) {
        return static_cast<T *>(component);
      }
    }
    return nullptr;
  }

  template <class T>
  void add(const std::string &id, Component *component) {
    if (has(id)) {
      m_components.at(id).try_emplace(std::type_index(typeid(T)), component);
    } else {
      std::unordered_map<std::type_index, Component *> list;
      list.try_emplace(std::type_index(typeid(T)), component);
      m_components.try_emplace(id, list);
    }
  }

  void start() override;
  void end() override;
  void update(const Timestep &timestep) override;
  void fixed_update(const Timestep &timestep) override;
};

} // namespace eq