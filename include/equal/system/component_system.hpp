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

#include <equal/core/component.hpp>
#include <equal/core/system.hpp>
#include <string>
#include <type_traits>
#include <typeindex>
#include <unordered_map>

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
