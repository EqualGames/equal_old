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

void Painter::recursive(const Ref<GameObject> &object) {
  if (object->visible()) {
    draw(object);

    for (auto child : object->get<TransformComponent>()->children()) {
      recursive(child);
    }
  }
}

void Painter::draw(const Scope<Scene> &scene) {
  for (const Ref<GameObject> &object : scene->objects()) {
    recursive(object);
  }

  recursive(static_cast<Ref<GameObject>>(scene->canvas()));
}

void Painter::draw(const Ref<GameObject> &object) {
  if (object->has<RendererComponent>()) {
    draw(*object->get<RendererComponent>(), *object->get<TransformComponent>());
  } else if (object->has<TextComponent>()) {
    draw(*object->get<TextComponent>(), *object->get<TransformComponent>());
  }
}

} // namespace eq
