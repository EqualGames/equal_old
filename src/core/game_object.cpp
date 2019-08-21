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
#include <equal/component/transform_component.hpp>
#include <equal/core/game_object.hpp>
#include <equal/core/script.hpp>
#include <equal/helper/guid.hpp>
#include <equal/helper/string.hpp>

namespace eq {

GameObject::GameObject(const std::string &id) {
  m_guid = GenerateUUID();
  m_id = id;

  add<TransformComponent>();
}

GameObject::GameObject(const Position &position) {
  m_guid = GenerateUUID();
  add<TransformComponent>(position);
}

GameObject::GameObject(const Position &position, const Size &size) {
  m_guid = GenerateUUID();
  add<TransformComponent>(position, size);
}

const std::string &GameObject::guid() const { return m_guid; }

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

const Ref<GameObject> GameObject::find(const std::string &query) {
  auto children = get<TransformComponent>()->children();
  std::pair<std::string, std::string> p = str::split_pair(query, '#');

  auto result = std::find_if(children.begin(), children.end(), [&p](const Ref<GameObject> &child) {
    return child->name() == p.first && child->id() == p.second;
  });

  if (result != children.end()) {
    return *result;
  } else {
    return nullptr;
  }
}

} // namespace eq
