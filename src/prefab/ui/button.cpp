#include <equal/core/resource.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/component/text_component.hpp>
#include <equal/helper/string.hpp>
#include <equal/prefab/ui/text.hpp>
#include <equal/prefab/ui/button.hpp>
#include <equal/prefab/script/button_script.hpp>

namespace eq::ui {

Button::Button(const std::string& id) : GameObject(id) {
  name("Button");

  AddComponent<RendererComponent>(g_res.getTexture("container"));
  GetComponent<RendererComponent>()->type(Render::Type::Sliced);

  m_label = CreateObject<Text>();
  m_label->GetComponent<TransformComponent>()->anchor(Transform::Anchor::CC);

  AddScript<ButtonScript>();
}

Button::Button(const std::string &value, const Position &position, const Size &size) : GameObject(position, size) {
  name("Button");

  AddComponent<RendererComponent>(g_res.getTexture("container"));
  GetComponent<RendererComponent>()->type(Render::Type::Sliced);

  m_label = CreateObject<Text>(value, Position{0, 0});
  m_label->GetComponent<TransformComponent>()->anchor(Transform::Anchor::CC);

  AddScript<ButtonScript>();
}

Button::~Button() {}

void Button::text(const std::wstring &text) { m_label->text(text); }

void Button::text(const std::string &text) { m_label->text(text); }

void Button::text_font(Font *font) { m_label->font(font); }

void Button::text_font_size(uint32_t font_size) { m_label->font_size(font_size); }

void Button::text_color(const Color &color) { m_label->color(color); }

void Button::text_position(const Position &position) {
  m_label->GetComponent<TransformComponent>()->position(position);
}

void Button::text_anchor(Transform::Anchor anchor) { m_label->GetComponent<TransformComponent>()->anchor(anchor); }

void Button::action(const ActionPerform &fn) { GetScript<ButtonScript>()->registerAction(fn); }

} // namespace eq::ui
