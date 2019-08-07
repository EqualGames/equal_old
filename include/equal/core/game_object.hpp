#pragma once

#include <string>
#include <equal/component/transform_component.hpp>
#include <equal/helper/system.hpp>
#include <equal/system/component_system.hpp>
#include <equal/system/script_system.hpp>

namespace eq {

class Component;
class Script;

/**
 * @ingroup core
 * @brief Game object is a.k.a. Entity
 */
class GameObject {
protected:
  std::string m_id{""};
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
  GameObject(const eq::Position &position);

  /**
   * @brief Construct a new Game Object object
   *
   * @param position const eq::Position&
   * @param size const eq::Size&
   */
  GameObject(const eq::Position &position, const eq::Size &size);

  /**
   * @brief Destroy the Game Object object
   */
  virtual ~GameObject() = default;

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
   * @return GameObject*
   */
  eq::GameObject *find(const std::string &query);

  /**
   * @brief Create a game object with a child
   *
   * @tparam T eq::GameObject
   * @tparam Args
   * @param args Args
   * @return eq::GameObject*
   */
  template <class T, typename... Args>
  inline T *CreateObject(Args... args) {
    T *object = new T(args...);
    GetComponent<eq::TransformComponent>()->add(this, object);
    return object;
  }

  /**
   * @brief Add component on game object
   *
   * @tparam T eq::Component
   * @tparam Args
   * @param args Args
   */
  template <class T, typename... Args>
  inline void AddComponent(Args... args) {
    T *component = new T(args...);
    component->target(this);
    eq::GetComponentSystem()->add<T>(m_id, component);
  }

  /**
   * @brief Check if game object has component
   *
   * @tparam T eq::Component
   * @return bool
   */
  template <class T>
  inline bool HasComponent() const {
    return eq::GetComponentSystem()->has_type<T>(m_id);
  }

  /**
   * @brief Get the component of game object
   *
   * @tparam T eq::Component
   * @return eq::Component*
   */
  template <class T>
  inline T *GetComponent() const {
    return eq::GetComponentSystem()->get<T>(m_id);
  }

  /**
   * @brief Add script on game object
   *
   * @tparam T eq::Script
   * @tparam Args
   */
  template <class T, typename... Args>
  inline void AddScript() {
    T *script = new T();
    script->target(this);
    eq::GetScriptSystem()->add<T>(m_id, script);
  }

  /**
   * @brief Check if game object has script
   *
   * @tparam T eq::Script
   * @return bool
   */
  template <class T>
  inline bool HasScript() const {
    return eq::GetScriptSystem()->has_type<T>(m_id);
  }

  /**
   * @brief Get the script of game object
   *
   * @tparam T eq::Script
   * @return eq::Script*
   */
  template <class T>
  inline T *GetScript() const {
    return eq::GetScriptSystem()->get<T>(m_id);
  }
};

} // namespace eq
