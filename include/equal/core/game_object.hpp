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

#include <equal/component/transform_component.hpp>
#include <equal/helper/error.hpp>
#include <equal/helper/system.hpp>
#include <equal/system/component_system.hpp>
#include <equal/system/script_system.hpp>
#include <memory>
#include <string>
#include <type_traits>

namespace eq {

class Component;
class Script;

/**
 * @ingroup core
 * @brief Game object is a.k.a. Entity
 */
class GameObject {
protected:
  std::string m_guid;
  std::string m_id;
  std::string m_name{"GameObject"};
  bool m_initialized{false};
  bool m_interactive{true};
  bool m_focused{false};
  bool m_visible{true};
  int m_order{0};

public:
  /**
   * @brief Construct a new Game Object object
   *
   * @param id const std::string&
   */
  GameObject(const std::string &id = "");

  /**
   * @brief Construct a new Game Object object
   *
   * @param position const eq::Position&
   */
  GameObject(const Position &position);

  /**
   * @brief Construct a new Game Object object
   *
   * @param position const eq::Position&
   * @param size const eq::Size&
   */
  GameObject(const Position &position, const Size &size);

  /**
   * @brief Destroy the Game Object object
   */
  virtual ~GameObject() = default;

  /**
   * @brief Get game object guid
   *
   * @return const std::string&
   */
  const std::string &guid() const;

  /**
   * @brief Get game object id
   *
   * @return const std::string&
   */
  const std::string &id() const;

  /**
   * @brief Set id for game object
   *
   * @param id const std::string&
   */
  void id(const std::string &id);

  /**
   * @brief Get game object name
   *
   * @return const std::string&
   */
  const std::string &name() const;

  /**
   * @brief Set game object name
   *
   * @param name const std::string&
   */
  void name(const std::string &name);

  /**
   * @brief Return if element is visible
   *
   * @return bool
   */
  bool visible() const;

  /**
   * @brief Set game object visibility
   *
   * @param visible bool
   */
  void visible(bool visible);

  /**
   * @brief Return if element is interactive
   *
   * @return bool
   */
  bool interactive() const;

  /**
   * @brief Set game object is interactive
   *
   * @param interact
   */
  void interactive(bool interact);

  /**
   * @brief Return if element is focused
   *
   * @return bool
   */
  bool focused() const;

  /**
   * @brief Set game object is focused
   *
   * @param focus bool
   */
  void focused(bool focus);

  /**
   * @brief Get game object order based on parent
   *
   * @return int
   */
  int order() const;

  /**
   * @brief Set game object order based on parent
   *
   * @param order int
   */
  void order(int order);

  /**
   * @brief
   *
   * @param query const std::string&
   * @return const eq::Ref<eq::GameObject>
   */
  const Ref<GameObject> find(const std::string &query);

  /**
   * @brief Create a game object with a child
   *
   * @tparam T eq::GameObject
   * @tparam Args
   * @param args Args
   * @return eq::Ref<eq::GameObject>
   */
  template <typename T, typename... Args>
  inline Ref<T> create_object(Args... args) {
    if (!std::is_base_of_v<GameObject, T>) {
      EQ_THROW("Invalid object type, the type has need be a derived of eq::GameObject");
    }

    Ref<T> object = std::make_shared<T>(args...);
    Ref<GameObject> parent(this);
    get<TransformComponent>()->add(parent, std::dynamic_pointer_cast<GameObject>(object));
    return object;
  }

  /**
   * @brief Add element on game object
   *
   * @tparam T
   * @tparam Args
   * @param args Args
   */
  template <typename T, typename... Args>
  inline void add(Args... args) {
    if (!std::is_base_of_v<Component, T> && !std::is_base_of_v<Script, T>) {
      EQ_THROW("Invalid object type, the type has need be a derived of eq::Component or eq::Script");
    }

    T *object = new T(args...);
    Ref<GameObject> parent(this);
    object->target(parent);

    if (std::is_base_of_v<Component, T>) {
      register_component<T>(m_guid, dynamic_cast<Component *>(object));
    } else if (std::is_base_of_v<Script, T>) {
      register_script<T>(m_guid, dynamic_cast<Script *>(object));
    }
  }

  /**
   * @brief Check if game object has element
   *
   * @tparam T
   * @return bool
   */
  template <typename T>
  inline bool has() const {
    if (std::is_base_of_v<Component, T>) {
      return has_component<T>(m_guid);
    } else if (std::is_base_of_v<Script, T>) {
      return has_script<T>(m_guid);
    } else {
      EQ_THROW("Invalid object type, the type has need be a derived of eq::Component or eq::Script");
    }
  }

  /**
   * @brief Get the element of game object
   *
   * @tparam T 
   * @return T*
   */
  template <typename T>
  inline T *get() const {
    if (std::is_base_of_v<Component, T>) {
      return get_component<T>(m_guid);
    } else if (std::is_base_of_v<Script, T>) {
      return get_script<T>(m_guid);
    } else {
      EQ_THROW("Invalid object type, the type has need be a derived of eq::Component or eq::Script");
    }
  }
};

} // namespace eq
