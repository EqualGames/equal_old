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
  /**
   * @brief
   *
   * @param guid
   * @return true
   * @return false
   */
  bool has(const std::string &guid) const;

  /**
   * @brief Get the all object
   *
   * @param guid
   * @return const std::unordered_map<std::type_index, Component *>&
   */
  const std::unordered_map<std::type_index, Component *> &get_all(const std::string &guid) const;

  /**
   * @brief
   *
   * @tparam T
   * @param guid
   * @return true
   * @return false
   */
  template <class T>
  bool has_type(const std::string &guid) const {
    if (has(guid)) {
      auto list = get_all(guid);
      return list.find(std::type_index(typeid(T))) != list.end();
    }

    return false;
  }

  /**
   * @brief
   *
   * @tparam T
   * @param guid
   * @return T*
   */
  template <class T>
  T *get(const std::string &guid) const {
    for (auto &[type, component] : get_all(guid)) {
      if (type == std::type_index(typeid(T))) {
        return dynamic_cast<T *>(component);
      }
    }
    return nullptr;
  }

  /**
   * @brief
   *
   * @tparam T
   * @param guid
   * @param component
   */
  template <class T>
  void add(const std::string &guid, Component *component) {
    if (has(guid)) {
      m_components.at(guid).try_emplace(std::type_index(typeid(T)), component);
    } else {
      std::unordered_map<std::type_index, Component *> list;
      list.try_emplace(std::type_index(typeid(T)), component);
      m_components.try_emplace(guid, list);
    }
  }

  /**
   * @brief
   *
   */
  void start() override;

  /**
   * @brief
   *
   */
  void end() override;

  /**
   * @brief
   *
   * @param timestep
   */
  void update(const Timestep &timestep) override;

  /**
   * @brief
   *
   * @param timestep
   */
  void fixed_update(const Timestep &timestep) override;
};

} // namespace eq
