#include <equal/core/resource.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/text_component.hpp>
#include <equal/helper/string.hpp>
#include <equal/prefab/ui/text.hpp>

namespace eq::ui {

Text::Text(const std::string& id) : GameObject(id) {
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
