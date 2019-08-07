#include <equal/core/game_object.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/helper/string.hpp>
#include <equal/helper/guid.hpp>
#include <equal/core/script.hpp>

namespace eq {

GameObject::GameObject(const std::string &id) {
  if (!id.empty()) {
    m_id = id;
  } else {
    m_id = GenerateUUID();
  }

  AddComponent<TransformComponent>();
}

GameObject::GameObject(const Position &position) {
  m_id = GenerateUUID();
  AddComponent<TransformComponent>(position);
}

GameObject::GameObject(const Position &position, const Size &size) {
  m_id = GenerateUUID();
  AddComponent<TransformComponent>(position, size);
}

void GameObject::id(const std::string &id) { m_id = id; }

const std::string &GameObject::id() const { return m_id; }

const std::string &GameObject::name() const { return m_name; }

void GameObject::name(const std::string &name) { m_name = name; }

bool GameObject::visible() const { return m_visible; }

void GameObject::visible(bool visible) { m_visible = visible; }

bool GameObject::interactive() const { return m_interactive; }

void GameObject::interactive(bool interact) { m_interactive = interact; }

bool GameObject::focused() const { return m_focused; }

void GameObject::focused(bool focus) { m_focused = focus; }

int GameObject::order() const { return m_order; }

void GameObject::order(int order) { m_order = order; }

GameObject *GameObject::find(const std::string &query) {
  auto children = GetComponent<TransformComponent>()->children();
  std::pair<std::string, std::string> p = str::split_pair(query, '#');
  std::string name = p.first;
  std::string id = p.second;

  auto result = std::find_if(children.begin(), children.end(), [name, id](GameObject *child) {
    return child->name() == name && child->id() == id;
  });

  if (result != children.end()) {
    return *result;
  } else {
    return nullptr;
  }
}

} // namespace eq
