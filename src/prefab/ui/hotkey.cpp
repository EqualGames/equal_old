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
#include <equal/component/renderer_component.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/core/resource.hpp>
#include <equal/helper/string.hpp>
#include <equal/prefab/ui/button.hpp>
#include <equal/prefab/ui/hotkey.hpp>
#include <equal/prefab/ui/image.hpp>

namespace eq::ui {

Hotkey::Hotkey(const std::string &value, const Position &position, const Size &size) : GameObject(position, size) {
  name("Hotkey");

  m_image = create_object<Image>(Position{5, 5}, size - Size{10, 10});

  m_button = create_object<Button>(value, Position{0, 0}, size);
  m_button->text_font_size(12);
  m_button->text_anchor(Transform::Anchor::BR);
  m_button->text_position(Position{8, 9});

  RendererComponent *btn_renderer = m_button->get<RendererComponent>();
  btn_renderer->type(Render::Type::Simple);
  btn_renderer->texture(g_res.getTexture("hotkey"));
}

Hotkey::~Hotkey() {}

void Hotkey::key(const std::wstring &text) { m_button->text(text); }

void Hotkey::key(const std::string &text) { m_button->text(text); }

void Hotkey::key_font(Font *font) { m_button->text_font(font); }

void Hotkey::key_color(const Color &color) { m_button->text_color(color); }

void Hotkey::icon(Texture *texture) { m_image->texture(texture); }

void Hotkey::action(const ActionPerform &fn) { m_button->action(fn); }

} // namespace eq::ui
