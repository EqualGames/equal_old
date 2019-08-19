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
#include <equal/prefab/script/window_script.hpp>
#include <equal/prefab/ui/button.hpp>
#include <equal/prefab/ui/container.hpp>
#include <equal/prefab/ui/text.hpp>
#include <equal/prefab/ui/window.hpp>

namespace eq::ui {

Window::Window(const std::string &id) : GameObject(id) {
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
