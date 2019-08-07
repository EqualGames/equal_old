#include <equal/core/resource.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/component/text_component.hpp>
#include <equal/helper/string.hpp>
#include <equal/prefab/script/window_script.hpp>
#include <equal/prefab/ui/container.hpp>
#include <equal/prefab/ui/text.hpp>
#include <equal/prefab/ui/button.hpp>
#include <equal/prefab/ui/window.hpp>

namespace eq::ui {

Window::Window(const std::string& id) : GameObject(id) {
  name("Window");

  AddComponent<RendererComponent>(g_res.getTexture("container"));
  GetComponent<RendererComponent>()->type(Render::Type::Sliced);

  m_title = CreateObject<Text>("", Position{10, 4});

  m_button_close = CreateObject<Button>("", Position{0, 0}, Size{24, 24});
  m_button_close->action([&]() { visible(false); });
  m_button_close->GetComponent<TransformComponent>()->anchor(Transform::Anchor::TR);
  m_button_close->GetComponent<RendererComponent>()->texture(g_res.getTexture("close_container_button"));

  AddScript<WindowScript>();
}

Window::Window(const std::string &value, const Position &position, const Size &size) : GameObject(position, size) {
  name("Window");

  AddComponent<RendererComponent>(g_res.getTexture("container"));
  GetComponent<RendererComponent>()->type(Render::Type::Sliced);

  m_title = CreateObject<Text>(value, Position{10, 4});

  m_button_close = CreateObject<Button>("x", Position{0, 0}, Size{24, 24});
  m_button_close->action([&]() { visible(false); });
  m_button_close->GetComponent<TransformComponent>()->anchor(Transform::Anchor::TR);

  AddScript<WindowScript>();
}

Window::~Window() {}

void Window::title(const std::wstring &text) { m_title->text(text); }

void Window::title(const std::string &text) { m_title->text(text); }

void Window::title_font(Font *font) { m_title->font(font); }

void Window::title_color(const Color &color) { m_title->color(color); }

} // namespace eq::ui
