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
#include <equal/prefab/ui/flask_bar.hpp>
#include <equal/prefab/ui/image.hpp>

namespace eq::ui {

FlaskBar::FlaskBar(float value, float max_value, const Position &position, const Size &size)
    : GameObject(position, size) {
  name("FlaskBar");
  interactive(false);
  m_max_value = max_value;

  m_background = CreateObject<Image>(Position{0, 0}, size);
  m_background->texture(g_res.getTexture("container_bar_background"));

  m_foreground = CreateObject<Image>(Position{0, 0}, size);
  m_foreground->texture(g_res.getTexture("container_bar_background"));

  RendererComponent *f_renderer = m_foreground->GetComponent<RendererComponent>();
  f_renderer->type(Render::Type::Filled);
  f_renderer->fill_method(Render::Method::Progress);
  f_renderer->fill_origin(Render::Origin::Bottom);
  f_renderer->fill_ammount(value / max_value);
}

FlaskBar::~FlaskBar() {}

void FlaskBar::value(float value) {
  m_foreground->GetComponent<RendererComponent>()->fill_ammount(value / m_max_value);
}

void FlaskBar::max_value(float value) { m_max_value = value; }

void FlaskBar::color(const Color &color) { m_foreground->GetComponent<RendererComponent>()->color(color); }

} // namespace eq::ui
