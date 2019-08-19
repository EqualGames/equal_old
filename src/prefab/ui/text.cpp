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
#include <equal/component/text_component.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/core/resource.hpp>
#include <equal/helper/string.hpp>
#include <equal/prefab/ui/text.hpp>

namespace eq::ui {

Text::Text(const std::string &id) : GameObject(id) {
  name("Text");
  interactive(false);

  AddComponent<TextComponent>(g_res.getFont("consola_16"));
}

Text::Text(const std::string &value, const Position &position) : GameObject(position) {
  name("Text");
  interactive(false);

  AddComponent<TextComponent>(value, g_res.getFont("consola_16"));
}

Text::~Text() {}

std::wstring Text::text() { return GetComponent<TextComponent>()->text(); }

void Text::text(const std::wstring &text) { GetComponent<TextComponent>()->text(text); }

void Text::text(const std::string &text) { GetComponent<TextComponent>()->text(text); }

void Text::font(Font *font) { GetComponent<TextComponent>()->font(font); }

void Text::font_size(uint32_t font_size) { GetComponent<TextComponent>()->font_size(font_size); }

void Text::color(const Color &color) { GetComponent<TextComponent>()->color(color); }

void Text::alignment(const eq::Text::Alignment &align) { GetComponent<TextComponent>()->alignment(align); }

void Text::style(const eq::Text::Style &style) { GetComponent<TextComponent>()->style(style); }

} // namespace eq::ui
