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

#include <equal/core/types.hpp>
#include <equal/core/component.hpp>

namespace eq {

class GameObject;
/**
 * @ingroup components
 * @brief 
 */
class RendererComponent : public Component {
private:
  VertexArray m_vao;
  Texture *m_texture{nullptr};
  Color m_color{255, 255, 255, 255};
  Render::Type m_type{Render::Type::Simple};
  Render::Method m_fill_method{Render::Method::Progress};
  Render::Origin m_fill_origin{Render::Origin::Left};
  Position m_tile_position{0};
  Size m_tile_size{0};
  float m_fill_amount{0.0f};
  bool m_clockwise{false};
  bool m_preserve_aspect{false};
  bool m_need_update{true};

public:
  RendererComponent() = default;
  RendererComponent(Texture *texture);
  virtual ~RendererComponent();

  Render::Type type() const;
  void type(Render::Type type);
  Render::Method fill_method() const;
  void fill_method(Render::Method method);
  const Position &tile_position() const;
  void tile_position(const Position &position);
  const Size &tile_size() const;
  void tile_size(const Size &size);
  Render::Origin fill_origin() const;
  void fill_origin(Render::Origin origin);
  float fill_ammount() const;
  /* Value only between 0 and 1 */
  void fill_ammount(float amount);
  bool clockwise() const;
  void clockwise(bool clockwise);

  bool preserve_aspect() const;
  void preserve_aspect(bool preserve);

  Texture *texture() const;
  void texture(Texture *texture);
  Color color() const;
  void color(const Color &color);
  const VertexArray &vao() const;
  void push(const Vertex &vertex);
  void reset();

  void update(const Timestep& timestep);
  void fixed_update(const Timestep& timestep);
};

} // namespace eq
