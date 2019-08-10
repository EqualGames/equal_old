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
