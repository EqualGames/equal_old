#include <equal/core/resource.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/prefab/ui/container.hpp>

namespace eq::ui {

Container::Container(const std::string& id) : GameObject(id) {
  name("Container");
  interactive(false);

  AddComponent<RendererComponent>(g_res.getTexture("container"));
  GetComponent<RendererComponent>()->type(Render::Type::Sliced);
}

Container::Container(const Position &position, const Size &size) : GameObject(position, size) {
  name("Container");
  interactive(false);

  AddComponent<RendererComponent>(g_res.getTexture("container"));
  GetComponent<RendererComponent>()->type(Render::Type::Sliced);
}

Container::~Container() {}

} // namespace eq::ui
