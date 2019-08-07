#include <equal/core/resource.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/component/text_component.hpp>
#include <equal/helper/string.hpp>
#include <equal/prefab/script/text_input_script.hpp>
#include <equal/prefab/ui/text_input.hpp>

namespace eq::ui {

TextInput::TextInput(const std::string &id) : GameObject(id) {
  name("TextInput");

  AddComponent<RendererComponent>(g_res.getTexture("container"));
  GetComponent<RendererComponent>()->type(Render::Type::Sliced);

  m_value = CreateObject<Text>("", Position{5, 0});
  m_value->GetComponent<TransformComponent>()->anchor(Transform::Anchor::CL);

  m_caret = CreateObject<Image>(Position{0, 0}, Size{4, 26});
  m_caret->GetComponent<TransformComponent>()->anchor(Transform::Anchor::CL);
  m_caret->visible(false);

  AddScript<TextInputScript>();
}

TextInput::TextInput(const std::string &value, const Position &position, const Size &size)
    : GameObject(position, size) {
  name("TextInput");

  AddComponent<RendererComponent>(g_res.getTexture("container"));
  GetComponent<RendererComponent>()->type(Render::Type::Sliced);

  m_value = CreateObject<Text>(value, Position{5, 0});
  m_value->GetComponent<TransformComponent>()->anchor(Transform::Anchor::CL);

  m_caret = CreateObject<Image>(Position{0, 0}, Size{4, size.y - 10});
  m_caret->GetComponent<TransformComponent>()->anchor(Transform::Anchor::CL);
  m_caret->visible(false);

  AddScript<TextInputScript>();

}

TextInput::~TextInput() {}

void TextInput::move_caret() {
  TransformComponent *transform = GetComponent<TransformComponent>();
  TransformComponent *text_transform = m_value->GetComponent<TransformComponent>();

  Size box_size{transform->size()};
  Size text_size{text_transform->size()};
  Size caret_size{m_caret->GetComponent<TransformComponent>()->size()};
  Position caret_pos{text_size.x + caret_size.x * 2, 0};

  if (caret_pos.x < int(box_size.x - caret_size.x)) {
    m_caret->GetComponent<TransformComponent>()->position(caret_pos);
  } else {
    m_caret->GetComponent<TransformComponent>()->position(Position{box_size.x - caret_size.x * 2, 0});
  }
}

void TextInput::masked(bool masked) { m_value->GetComponent<TextComponent>()->masked(masked); }

bool TextInput::caret() const { return m_caret->visible(); }

void TextInput::caret(bool visible) { m_caret->visible(visible); }

std::wstring TextInput::text() { return m_value->text(); }

void TextInput::text(const std::string &value) { m_value->text(value); }

void TextInput::text(const std::wstring &value) { m_value->text(value); }

void TextInput::text_font(Font *font) { m_value->font(font); }

void TextInput::text_font_size(uint32_t font_size) { m_value->font_size(font_size); }

void TextInput::text_color(const Color &color) { m_value->color(color); }

} // namespace eq::ui
