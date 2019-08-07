#pragma once

#include <vector>
#include <equal/core/types.hpp>
#include <equal/core/component.hpp>

namespace eq {

class GameObject;

/**
 * @ingroup components
 * @brief
 */
class TransformComponent : public Component {
private:
  Position m_local_position{0};
  Position m_position{0};
  Rotation m_local_rotation{0};
  Rotation m_rotation{0};
  Size m_size{0};
  Origin m_local_origin{0};
  Origin m_origin{0};
  Transform::Anchor m_anchor{Transform::Anchor::TL};
  BoundingBox m_bbox{0};
  bool m_need_update{true};
  GameObject *m_parent{nullptr};
  std::vector<GameObject *> m_children;

public:
  TransformComponent() = default;
  TransformComponent(const Position &position);
  TransformComponent(const Position &position, const Size &size);
  virtual ~TransformComponent();

  GameObject *parent() const;
  void parent(GameObject *object);
  const std::vector<GameObject *> &children();
  GameObject *child(int index) const;
  void add(GameObject *parent, GameObject *object);
  void remove(GameObject *object);
  void parentUpdate();

  Transform::Anchor anchor() const;
  void anchor(Transform::Anchor anchor);
  void position(const Position &position);
  const Position &position() const;
  const Position &local_position() const;
  void rotation(const Rotation &position);
  const Rotation &rotation() const;
  const Rotation &local_rotation() const;
  void size(const Size &size);
  const Size &size() const;
  void origin(const Origin &origin);
  const Origin &origin() const;
  const Origin &local_origin() const;
  void bbox(const BoundingBox &bbox);
  const BoundingBox &bbox() const;
  bool contain(const Position &position) const;

  void update(const Timestep &timestep);
  void fixed_update(const Timestep &timestep);
};

} // namespace eq
