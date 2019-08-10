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

#include <string>
#include <cstdint>
#include <equal/core/component.hpp>

namespace eq {

class GameObject;

/**
 * @ingroup components
 * @brief 
 */
class TextComponent : public Component {
private:
  Text::Style m_style{Text::Style::Regular};
  Text::Alignment m_align{Text::Alignment::Left};
  Text::Overflow m_overflow_x{Text::Overflow::Hidden};
  Text::Overflow m_overflow_y{Text::Overflow::Hidden};
  Position m_offset{0};
  Font *m_font{nullptr};
  uint32_t m_font_size{16};
  Color m_color{255, 255, 255, 255};
  std::wstring m_local_text{L""};
  std::wstring m_text{L""};
  bool m_masked{false};
  bool m_need_update{true};
  BoundingBox m_crop{0};

public:
  TextComponent() = default;
  TextComponent(Font *font);
  TextComponent(const std::string &text, Font *font);
  virtual ~TextComponent();

  const std::wstring &text() const;
  void text(const std::wstring &text);
  void text(const std::string &text);
  bool masked() const;
  void masked(bool masked);

  Font *font() const;
  void font(Font *font);
  uint32_t font_size() const;
  void font_size(uint32_t font_size);

  const BoundingBox &crop() const;
  void crop(const BoundingBox &crop);
  const Position &offset() const;
  void offset(const Position &offset);
  Text::Overflow overflow_x() const;
  void overflow_x(Text::Overflow overflow);
  Text::Overflow overflow_y() const;
  void overflow_y(Text::Overflow overflow);
  const Color &color() const;
  void color(const Color &color);
  void alignment(const Text::Alignment &align);
  void style(const Text::Style &style);

  void update(const Timestep& timestep);
  void fixed_update(const Timestep& timestep);
};

} // namespace eq
