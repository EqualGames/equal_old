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
#include <equal/core/logger.hpp>
#include <equal/helper/error.hpp>
#include <equal/core/resource.hpp>
#include <equal/core/game_object.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>

namespace eq {

RendererComponent::RendererComponent(Texture *texture) { m_texture = texture; }

RendererComponent::~RendererComponent() {
  delete m_texture;
  m_vao.clear();
}

Render::Type RendererComponent::type() const { return m_type; }

void RendererComponent::type(Render::Type type) {
  if (m_type != type) {
    m_type = type;
    m_need_update = true;
  }
}

Render::Method RendererComponent::fill_method() const { return m_fill_method; }

void RendererComponent::fill_method(Render::Method method) {
  if (m_fill_method != method) {
    m_fill_method = method;
    m_need_update = true;
  }
}

const Position &RendererComponent::tile_position() const { return m_tile_position; }

void RendererComponent::tile_position(const Position &position) {
  if (m_tile_position != position) {
    m_tile_position = position;
    m_need_update = true;
  }
}

const Size &RendererComponent::tile_size() const { return m_tile_size; }

void RendererComponent::tile_size(const Size &size) {
  if (m_tile_size != size) {
    m_tile_size = size;
    m_need_update = true;
  }
}

Render::Origin RendererComponent::fill_origin() const { return m_fill_origin; }

void RendererComponent::fill_origin(Render::Origin origin) {
  if (m_fill_origin != origin) {
    m_fill_origin = origin;
    m_need_update = true;
  }
}

float RendererComponent::fill_ammount() const { return m_fill_amount; }

void RendererComponent::fill_ammount(float amount) {
  if (amount < 0.0f && amount > 1.0f) {
    EQ_THROW("The amount value must be between 0 and 1");
  } else if (m_fill_amount != amount) {
    m_fill_amount = amount;
    m_need_update = true;
  }
}

bool RendererComponent::clockwise() const { return m_clockwise; }

void RendererComponent::clockwise(bool clockwise) {
  if (m_clockwise != clockwise) {
    m_clockwise = clockwise;
    m_need_update = true;
  }
}

bool RendererComponent::preserve_aspect() const { return m_preserve_aspect; }

void RendererComponent::preserve_aspect(bool preserve) {
  if (m_preserve_aspect != preserve) {
    m_preserve_aspect = preserve;
    m_need_update = true;
  }
}

Texture *RendererComponent::texture() const { return m_texture; }

void RendererComponent::texture(Texture *texture) {
  if (m_texture != texture) {
    m_texture = texture;
    m_need_update = true;
  }
}

Color RendererComponent::color() const { return m_color; }

void RendererComponent::color(const Color &color) {
  if (m_color != color) {
    m_color = color;
  }
}

const VertexArray &RendererComponent::vao() const { return m_vao; }

void RendererComponent::push(const Vertex &vertex) {
  m_vao.emplace_back(vertex);
  m_need_update = true;
}

void RendererComponent::reset() {
  if (!m_vao.empty()) {
    m_vao.clear();
    m_need_update = true;
  }
}

void RendererComponent::fixed_update(const Timestep& timestep) {}

void RendererComponent::update(const Timestep& timestep) {
  if (m_need_update && m_texture) {
    m_need_update = false;

    if (m_type != Render::Type::Manual) {
      m_vao.clear();
      const fSize size{m_target->GetComponent<TransformComponent>()->size()};
      const fSize texture_size{m_texture->size};

      if (m_type == Render::Type::Simple) {
        m_vao.emplace_back(
            Vertex{VertexPoint{0, 0, size.x, size.y}, VertexPoint{0, 0, texture_size.x, texture_size.y}});
      } else if (m_type == Render::Type::Sliced) {

        const fSize sliced_edge{Render::sliced_edge};
        const fSize sliced_border_TB{Render::sliced_border_TB};
        const fSize sliced_border_LR{Render::sliced_border_LR};
        const float sliced_shadow = static_cast<float>(Render::sliced_shadow);

        // Top Left
        m_vao.emplace_back(
            Vertex{VertexPoint{0, 0, sliced_edge.x, sliced_edge.y}, VertexPoint{0, 0, sliced_edge.x, sliced_edge.y}});

        // Top Right
        m_vao.emplace_back(Vertex{VertexPoint{size.x - sliced_edge.x, 0, sliced_edge.x, sliced_edge.y},
                                  VertexPoint{texture_size.x - sliced_edge.x, 0, sliced_edge.x, sliced_edge.y}});
        // Bottom Right
        m_vao.emplace_back(
            Vertex{VertexPoint{size.x - sliced_edge.x, size.y - sliced_edge.y - sliced_shadow, sliced_edge.x,
                               sliced_edge.y + sliced_shadow},
                   VertexPoint{texture_size.x - sliced_edge.x, texture_size.y - sliced_edge.y - sliced_shadow,
                               sliced_edge.x, sliced_edge.y + sliced_shadow}});
        // Bottom Left
        m_vao.emplace_back(
            Vertex{VertexPoint{0, size.y - sliced_edge.y - sliced_shadow, sliced_edge.x, sliced_edge.y + sliced_shadow},
                   VertexPoint{0, texture_size.y - sliced_edge.y - sliced_shadow, sliced_edge.x,
                               sliced_edge.y + sliced_shadow}});

        float border_TB_size = size.x - (sliced_edge.x * 2);
        for (float i = 0; i <= border_TB_size; ++i) {
          // Border Top
          m_vao.emplace_back(
              Vertex{VertexPoint{sliced_edge.x + (i * sliced_border_TB.x), 0, sliced_border_TB.x, sliced_border_TB.y},
                     VertexPoint{sliced_edge.x, 0, sliced_border_TB.x, sliced_border_TB.y}});

          // Border Bottom
          m_vao.emplace_back(
              Vertex{VertexPoint{sliced_edge.x + (i * sliced_border_TB.x), size.y - sliced_border_TB.y - sliced_shadow,
                                 sliced_border_TB.x, sliced_border_TB.y + sliced_shadow},
                     VertexPoint{sliced_edge.x, texture_size.y - sliced_border_TB.y - sliced_shadow, sliced_border_TB.x,
                                 sliced_border_TB.y + sliced_shadow}});
        }

        float border_LR_size = size.y - (sliced_edge.y * 2);
        for (float i = 0; i <= border_LR_size; ++i) {
          // Border Left
          m_vao.emplace_back(
              Vertex{VertexPoint{0, sliced_edge.y + (i * sliced_border_LR.y), sliced_border_LR.x, sliced_border_LR.y},
                     VertexPoint{0, sliced_edge.y, sliced_border_LR.x, sliced_border_LR.y}});
          // Border Right
          m_vao.emplace_back(Vertex{
              VertexPoint{size.x - sliced_edge.x, sliced_edge.y + (i * sliced_border_LR.y), sliced_border_LR.x,
                          sliced_border_LR.y},
              VertexPoint{texture_size.x - sliced_border_LR.x, sliced_edge.y, sliced_border_LR.x, sliced_border_LR.y}});
        }

        // Fill
        m_vao.emplace_back(Vertex{
            VertexPoint{sliced_edge.x, sliced_edge.y, size.x - (sliced_edge.x * 2), size.y - (sliced_edge.y * 2)},
            VertexPoint{sliced_edge.x, sliced_edge.y, texture_size.x - (sliced_edge.x * 2),
                        texture_size.y - (sliced_edge.y * 2)}});

      } else if (m_type == Render::Type::Tiled) {
        m_vao.emplace_back(Vertex{VertexPoint{0, 0, size.x, size.y},
                                  VertexPoint{m_tile_position.x * m_tile_size.x, m_tile_position.y * m_tile_size.y,
                                              m_tile_size.x, m_tile_size.y}});
      } else if (m_type == Render::Type::Filled) {
        float ratio{0.0f};
        float progress{0.0f};

        if (m_fill_method == Render::Method::Progress) {
          if (m_fill_origin == Render::Origin::Top || m_fill_origin == Render::Origin::Bottom) {
            ratio = static_cast<float>(size.y) / static_cast<float>(texture_size.y);
            progress = std::floor(size.y - std::floor(m_fill_amount * size.y / 1.0f));
          } else if (m_fill_origin == Render::Origin::Left || m_fill_origin == Render::Origin::Right) {
            ratio = static_cast<float>(size.x) / static_cast<float>(texture_size.x);
            progress = std::floor(size.x - std::floor(m_fill_amount * size.x / 1.0f));
          }

          if (m_fill_origin == Render::Origin::Top) {
            m_vao.emplace_back(Vertex{VertexPoint{0, 0, size.x, size.y - progress},
                                      VertexPoint{0, 0, texture_size.x, texture_size.y - progress / ratio}});
          } else if (m_fill_origin == Render::Origin::Bottom) {
            m_vao.emplace_back(
                Vertex{VertexPoint{0, progress, size.x, size.y - progress},
                       VertexPoint{0, progress / ratio, texture_size.x, texture_size.y - progress / ratio}});
          } else if (m_fill_origin == Render::Origin::Left) {
            m_vao.emplace_back(Vertex{VertexPoint{0, 0, size.x - progress, size.y},
                                      VertexPoint{0, 0, texture_size.x - progress / ratio, texture_size.y}});
          } else if (m_fill_origin == Render::Origin::Right) {
            m_vao.emplace_back(
                Vertex{VertexPoint{progress, 0, size.x - progress, size.y},
                       VertexPoint{progress / ratio, 0, texture_size.x - progress / ratio, texture_size.y}});
          }
        } else if (m_fill_method == Render::Method::Radial) {
          // TODO: Make a radial render with clockwise option
        }
      }
    }
  }
}

} // namespace eq
