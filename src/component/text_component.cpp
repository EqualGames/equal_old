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
#include <equal/helper/string.hpp>
#include <equal/component/text_component.hpp>

#ifdef EQ_SDL
#include <SDL2/SDL_ttf.h>
#endif

namespace eq {

TextComponent::TextComponent(Font *font) { m_font = font; }

TextComponent::TextComponent(const std::string &text, Font *font) {
  m_text = str::utf8_to_wchar(text.c_str());
  m_font = font;
}

TextComponent::~TextComponent() { delete m_font; }

uint32_t TextComponent::font_size() const { return m_font_size; }

void TextComponent::font_size(uint32_t font_size) {
  if (m_font_size != font_size) {
    m_font_size = font_size;
    m_need_update = true;
  }
}

Text::Overflow TextComponent::overflow_x() const { return m_overflow_x; }

void TextComponent::overflow_x(Text::Overflow overflow) {
  if (m_overflow_x != overflow) {
    m_overflow_x = overflow;
  }
}

Text::Overflow TextComponent::overflow_y() const { return m_overflow_y; }

void TextComponent::overflow_y(Text::Overflow overflow) {
  if (m_overflow_y != overflow) {
    m_overflow_y = overflow;
  }
}

const Position &TextComponent::offset() const { return m_offset; }

void TextComponent::offset(const Position &offset) {
  if (m_offset != offset) {
    m_offset = offset;
  }
}

const Color &TextComponent::color() const { return m_color; }

void TextComponent::color(const Color &color) {
  if (m_color != color) {
    m_color = color;
  }
}

const std::wstring &TextComponent::text() const { return m_text; }

void TextComponent::text(const std::wstring &text) {
  if (m_text != text) {
    m_text = text;
    m_need_update = true;
  }
}

void TextComponent::text(const std::string &text) { this->text(str::utf8_to_wchar(text.c_str())); }

bool TextComponent::masked() const { return m_masked; }

void TextComponent::masked(bool masked) {
  if (m_masked != masked) {
    m_masked = masked;
  }
}

void TextComponent::alignment(const Text::Alignment &align) {
  if (m_align != align) {
    m_align = align;
  }
}

void TextComponent::style(const Text::Style &style) {
  if (m_style != style) {
    m_style = style;
  }
}

Font *TextComponent::font() const { return m_font; }

void TextComponent::font(Font *font) {
  if (m_font != font) {
    m_font = font;
    m_need_update = true;
  }
}

const BoundingBox &TextComponent::crop() const { return m_crop; }

void TextComponent::crop(const BoundingBox &crop) {
  if (m_crop != crop) {
    m_crop = crop;
    m_need_update = true;
  }
}

void TextComponent::fixed_update(const Timestep &timestep) {}

void TextComponent::update(const Timestep &timestep) {
  if (m_need_update) {
    m_need_update = false;
    if (!m_text.empty()) {
      m_target->visible(true);
      TransformComponent *transform = m_target->GetComponent<TransformComponent>();

#ifdef EQ_SDL
      std::string text_value = str::wchar_to_utf8(m_text.c_str());

      int w, h;
      if (TTF_SizeText(static_cast<TTF_Font *>(m_font->data()), text_value.c_str(), &w, &h) != 0) {
        EQ_THROW("Can't draw game object: {}", TTF_GetError());
      }

      transform->size(Size{w, h});
#endif
    } else {
      m_target->visible(false);
    }
  }
}

} // namespace eq
