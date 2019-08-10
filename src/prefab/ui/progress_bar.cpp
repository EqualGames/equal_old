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
#include <equal/core/resource.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/helper/string.hpp>
#include <equal/prefab/ui/image.hpp>
#include <equal/prefab/ui/progress_bar.hpp>

namespace eq::ui {

ProgressBar::ProgressBar(const std::string &id) : GameObject(id) {
  name("ProgressBar");
  interactive(false);

  float value{0.0f};
  float max_value{100.0f};
  Size size{300, 64};

  m_background = CreateObject<Image>(Position{0, 0}, size);
  m_background->texture(g_res.getTexture("progress_bar_background"));

  {
    RendererComponent *bg_render = m_background->GetComponent<RendererComponent>();
    bg_render->type(Render::Type::Manual);
    fSize tex_size{bg_render->texture()->size().x, bg_render->texture()->size().y};
    float ratio = tex_size.y / tex_size.x;
    float w = std::floor(static_cast<float>(size.y) / ratio);
    float plug = std::floor(2.0f * w / tex_size.x);
    float fill = size.x - plug * 2.0f;
    // Left
    bg_render->push(Vertex{VertexPoint{0, 0, plug, size.y}, VertexPoint{0, 0, 2, tex_size.y}});
    // Fill
    bg_render->push(Vertex{VertexPoint{plug, 0, fill, size.y}, VertexPoint{2, 0, 1, tex_size.y}});
    // Right
    bg_render->push(Vertex{VertexPoint{fill + plug, 0, plug, size.y}, VertexPoint{2 + 1, 0, 2, tex_size.y}});
  }

  {
    m_foreground = CreateObject<Image>(Position{0, 0}, size);
    m_foreground->texture(g_res.getTexture("progress_bar_foreground"));
    m_foreground->GetComponent<RendererComponent>()->type(Render::Type::Manual);
  }

  m_max_value = max_value;
  this->value(value);
}

ProgressBar::ProgressBar(float value, float max_value, const Position &position, const Size &size)
    : GameObject(position, size) {
  name("ProgressBar");
  interactive(false);

  m_background = CreateObject<Image>(Position{0, 0}, size);
  m_background->texture(g_res.getTexture("progress_bar_background"));

  {
    RendererComponent *bg_render = m_background->GetComponent<RendererComponent>();
    bg_render->type(Render::Type::Manual);
    fSize tex_size{bg_render->texture()->size().x, bg_render->texture()->size().y};
    float ratio = tex_size.y / tex_size.x;
    float w = std::floor(static_cast<float>(size.y) / ratio);
    float plug = std::floor(2.0f * w / tex_size.x);
    float fill = size.x - plug * 2.0f;
    // Left
    bg_render->push(Vertex{VertexPoint{0, 0, plug, size.y}, VertexPoint{0, 0, 2, tex_size.y}});
    // Fill
    bg_render->push(Vertex{VertexPoint{plug, 0, fill, size.y}, VertexPoint{2, 0, 1, tex_size.y}});
    // Right
    bg_render->push(Vertex{VertexPoint{fill + plug, 0, plug, size.y}, VertexPoint{2 + 1, 0, 2, tex_size.y}});
  }

  {
    m_foreground = CreateObject<Image>(Position{0, 0}, size);
    m_foreground->texture(g_res.getTexture("progress_bar_foreground"));
    m_foreground->GetComponent<RendererComponent>()->type(Render::Type::Manual);
  }

  m_max_value = max_value;
  this->value(value);
}

ProgressBar::~ProgressBar() {}

float ProgressBar::value() const { return m_value; }

void ProgressBar::value(float value) {
  m_value = value;

  {
    auto fg_render = m_foreground->GetComponent<RendererComponent>();
    fSize size{m_foreground->GetComponent<TransformComponent>()->size()};

    fSize tex_size{fg_render->texture()->size().x, fg_render->texture()->size().y};
    float ratio = tex_size.y / tex_size.x;
    float w = std::floor(size.y / ratio);
    float plug = std::floor(2.0f * w / tex_size.x);
    float fill = size.x - plug * 2.0f;
    float progress = std::floor(value * fill / m_max_value);
    // Clear old vertex data
    fg_render->reset();
    // Left
    fg_render->push(Vertex{VertexPoint{0, 0, plug, size.y}, VertexPoint{0, 0, 2, tex_size.y}});
    // Fill
    fg_render->push(Vertex{VertexPoint{plug, 0, progress, size.y}, VertexPoint{2, 0, 1, tex_size.y}});
    // Right
    fg_render->push(Vertex{VertexPoint{progress + plug, 0, plug, size.y}, VertexPoint{2 + 1, 0, 2, tex_size.y}});
  }
}

float ProgressBar::max_value() const { return m_max_value; }

void ProgressBar::max_value(float value) { m_max_value = value; }

} // namespace eq::ui
