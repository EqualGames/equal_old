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
#include <equal/component/text_component.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/core/resource.hpp>
#include <equal/helper/string.hpp>
#include <equal/prefab/script/text_input_script.hpp>
#include <equal/prefab/ui/text_input.hpp>

namespace eq::ui {

TextInput::TextInput(const std::string &id) : GameObject(id) {
  name("TextInput");

  add<RendererComponent>(g_res.getTexture("container"));
  get<RendererComponent>()->type(Render::Type::Sliced);

  m_value = create_object<Text>("", Position{5, 0});
  m_value->get<TransformComponent>()->anchor(Transform::Anchor::CL);

  m_caret = create_object<Image>(Position{0, 0}, Size{4, 26});
  m_caret->get<TransformComponent>()->anchor(Transform::Anchor::CL);
  m_caret->visible(false);

  add<TextInputScript>();
}

TextInput::TextInput(const std::string &value, const Position &position, const Size &size)
    : GameObject(position, size) {
  name("TextInput");

  add<RendererComponent>(g_res.getTexture("container"));
  get<RendererComponent>()->type(Render::Type::Sliced);

  m_value = create_object<Text>(value, Position{5, 0});
  m_value->get<TransformComponent>()->anchor(Transform::Anchor::CL);

  m_caret = create_object<Image>(Position{0, 0}, Size{4, size.y - 10});
  m_caret->get<TransformComponent>()->anchor(Transform::Anchor::CL);
  m_caret->visible(false);

  add<TextInputScript>();
}

TextInput::~TextInput() {}

void TextInput::move_caret() {
  TransformComponent *transform{get<TransformComponent>()};
  TransformComponent *text_transform{m_value->get<TransformComponent>()};

  Size box_size{transform->size()};
  Size text_size{text_transform->size()};
  Size caret_size{m_caret->get<TransformComponent>()->size()};
  Position caret_pos{text_size.x + caret_size.x * 2, 0};

  if (caret_pos.x < int(box_size.x - caret_size.x)) {
    m_caret->get<TransformComponent>()->position(caret_pos);
  } else {
    m_caret->get<TransformComponent>()->position(Position{box_size.x - caret_size.x * 2, 0});
  }
}

void TextInput::masked(bool masked) { m_value->get<TextComponent>()->masked(masked); }

bool TextInput::caret() const { return m_caret->visible(); }

void TextInput::caret(bool visible) { m_caret->visible(visible); }

std::wstring TextInput::text() { return m_value->text(); }

void TextInput::text(const std::string &value) { m_value->text(value); }

void TextInput::text(const std::wstring &value) { m_value->text(value); }

void TextInput::text_font(Font *font) { m_value->font(font); }

void TextInput::text_font_size(uint32_t font_size) { m_value->font_size(font_size); }

void TextInput::text_color(const Color &color) { m_value->color(color); }

} // namespace eq::ui
