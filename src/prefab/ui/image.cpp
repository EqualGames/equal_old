#include <equal/core/resource.hpp>
#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/prefab/ui/image.hpp>

namespace eq::ui {

Image::Image(const std::string& id) : GameObject(id) {
  name("Image");
  interactive(false);

  AddComponent<RendererComponent>();
  GetComponent<RendererComponent>()->type(Render::Type::Simple);
}

Image::Image(const Position &position, const Size &size) : GameObject(position, size) {
  name("Image");
  interactive(false);

  AddComponent<RendererComponent>();
  GetComponent<RendererComponent>()->type(Render::Type::Simple);
}

Image::~Image() {}

void Image::texture(Texture *texture) { GetComponent<RendererComponent>()->texture(texture); }

} // namespace eq::ui
