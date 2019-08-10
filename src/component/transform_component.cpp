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
#include <equal/core/application.hpp>
#include <equal/core/game_object.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/helper/system.hpp>

namespace eq {

TransformComponent::TransformComponent(const Position &position) { m_local_position = position; }

TransformComponent::TransformComponent(const Position &position, const Size &size) {
  m_local_position = position;
  m_size = size;
}

TransformComponent::~TransformComponent() {
  delete m_parent;
  m_children.clear();
}

void TransformComponent::parentUpdate() { m_need_update = true; }

Transform::Anchor TransformComponent::anchor() const { return m_anchor; }

void TransformComponent::anchor(Transform::Anchor anchor) {
  if (m_anchor != anchor) {
    m_anchor = anchor;
    m_need_update = true;
  }
}

void TransformComponent::position(const Position &position) {
  if (m_local_position != position) {
    m_local_position = position;
    m_need_update = true;
  }
}

const Position &TransformComponent::position() const { return m_position; }

const Position &TransformComponent::local_position() const { return m_local_position; }

void TransformComponent::rotation(const Rotation &rotation) {
  if (m_rotation != rotation) {
    m_rotation = rotation;
    m_need_update = true;
  }
}

const Rotation &TransformComponent::rotation() const { return m_rotation; }

const Rotation &TransformComponent::local_rotation() const { return m_local_rotation; }

void TransformComponent::size(const Size &size) {
  if (m_size != size) {
    m_size = size;
    m_need_update = true;
  }
}

const Size &TransformComponent::size() const { return m_size; }

void TransformComponent::origin(const Origin &origin) {
  if (m_local_origin != origin) {
    m_local_origin = origin;
    m_need_update = true;
  }
}

const Origin &TransformComponent::origin() const { return m_origin; }

const Origin &TransformComponent::local_origin() const { return m_local_origin; }

void TransformComponent::bbox(const BoundingBox &bbox) {
  if (m_bbox != bbox) {
    m_bbox = bbox;
    m_need_update = true;
  }
}

const BoundingBox &TransformComponent::bbox() const { return m_bbox; }

bool TransformComponent::contain(const Position &position) const {
  Position pos{m_position - m_origin};
  Position size{m_size};

  return (position.x > pos.x && position.x < (pos.x + size.x)) && (position.y > pos.y && position.y < (pos.y + size.y));
}

GameObject *TransformComponent::parent() const { return m_parent; }

void TransformComponent::parent(GameObject *object) {
  m_parent = object;
  m_need_update = true;
}

const std::vector<GameObject *> &TransformComponent::children() { return m_children; }

GameObject *TransformComponent::child(int index) const {
  if (!m_children.empty()) {
    if (index >= 0 && index < static_cast<int>(m_children.size())) {
      return m_children.at(index);
    }
  }
  return nullptr;
}

void TransformComponent::add(GameObject *parent, GameObject *object) {
  object->GetComponent<TransformComponent>()->parent(parent);
  object->order(static_cast<int>(m_children.size()) + 1);
  m_children.push_back(object);
}

void TransformComponent::remove(GameObject *object) {
  m_children.erase(std::remove_if(m_children.begin(), m_children.end(),
                                  [object](GameObject *child) { return child->id() == object->id(); }));
}

void TransformComponent::fixed_update(const Timestep& timestep) {}

void TransformComponent::update(const Timestep& timestep) {
  if (m_need_update) {
    m_need_update = false;

    Position area_pos{0};
    Size area_size{0};

    if (m_parent) {
      TransformComponent *parentTransform = m_parent->GetComponent<TransformComponent>();
      area_pos = Position{parentTransform->position() - parentTransform->origin()};
      area_size = parentTransform->size();
    } else if (m_bbox != BoundingBox{0}) {
      area_pos = Position{m_bbox.x, m_bbox.y};
      area_size = Size{m_bbox.z, m_bbox.w};
    } else {
      area_pos = Position{0.0f, 0.0f};
      area_size = GetWindow()->size();
    }

    switch (m_anchor) {
      // Top
    case Transform::Anchor::TL:
      m_origin = Origin{0, 0};
      m_position = area_pos + m_local_position;
      break;
    case Transform::Anchor::TC:
      m_origin = Origin{m_size.x / 2, 0} + m_local_origin;
      m_position.x = area_pos.x + (area_size.x / 2) + m_local_position.x;
      m_position.y = area_pos.y + m_local_position.y;
      break;
    case Transform::Anchor::TR:
      m_origin = Origin{m_size.x, 0} + m_local_origin;
      m_position.x = area_pos.x + area_size.x - m_local_position.x;
      m_position.y = area_pos.y + m_local_position.y;
      break;
      // Center
    case Transform::Anchor::CL:
      m_origin = Origin{0, m_size.y / 2} + m_local_origin;
      m_position.x = area_pos.x + m_local_position.x;
      m_position.y = area_pos.y + (area_size.y / 2) + m_local_position.y;
      break;
    case Transform::Anchor::CC:
      m_origin = Origin{m_size.x / 2, m_size.y / 2} + m_local_origin;
      m_position.x = area_pos.x + (area_size.x / 2) + m_local_position.x;
      m_position.y = area_pos.y + (area_size.y / 2) + m_local_position.y;
      break;
    case Transform::Anchor::CR:
      m_origin = Origin{m_size.x, m_size.y / 2} + m_local_origin;
      m_position.x = area_pos.x + area_size.x + m_local_position.x;
      m_position.y = area_pos.y + (area_size.y / 2) + m_local_position.y;
      break;
      // Bottom
    case Transform::Anchor::BL:
      m_origin = Origin{0, m_size.y} + m_local_origin;
      m_position.x = area_pos.x + m_local_position.x;
      m_position.y = area_pos.y + area_size.y - m_local_position.y;
      break;
    case Transform::Anchor::BC:
      m_origin = Origin{m_size.x / 2, m_size.y} + m_local_origin;
      m_position.x = area_pos.x + (area_size.x / 2) + m_local_position.x;
      m_position.y = area_pos.y + area_size.y - m_local_position.y;
      break;
    case Transform::Anchor::BR:
      m_origin = Origin{m_size.x, m_size.y} + m_local_origin;
      m_position.x = area_pos.x + area_size.x - m_local_position.x;
      m_position.y = area_pos.y + area_size.y - m_local_position.y;
      break;
    default:
      break;
    }

    // FIXME: Need review
    for (GameObject *child : m_children) {
      child->GetComponent<TransformComponent>()->parentUpdate();
      child->GetComponent<TransformComponent>()->update(timestep);
    }
  }
}

} // namespace eq
