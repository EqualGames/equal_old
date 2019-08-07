#include <equal/core/painter.hpp>

namespace eq {

void Painter::recursive(const GameObject &object) {
  if (object.visible()) {
    draw(object);

    for (GameObject *child : object.GetComponent<TransformComponent>()->children()) {
      recursive(*child);
    }
  }
}

void Painter::draw(const Scene &scene) {
  for (GameObject *object : scene.objects()) {
    recursive(*object);
  }

  recursive(*static_cast<GameObject *>(scene.canvas()));
}

void Painter::draw(const GameObject &object) {
  if (object.HasComponent<RendererComponent>()) {
    draw(*object.GetComponent<RendererComponent>(), *object.GetComponent<TransformComponent>());
  } else if (object.HasComponent<TextComponent>()) {
    draw(*object.GetComponent<TextComponent>(), *object.GetComponent<TransformComponent>());
  }
}

} // namespace eq
