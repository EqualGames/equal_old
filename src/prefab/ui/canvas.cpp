#include <equal/component/transform_component.hpp>
#include <equal/component/renderer_component.hpp>
#include <equal/prefab/ui/canvas.hpp>

namespace eq::ui {

Canvas::Canvas(const Position &position, const Size &size) : GameObject(position, size) {
  name("Canvas");
  interactive(true);
}

} // namespace eq::ui
