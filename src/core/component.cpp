#include <equal/core/game_object.hpp>
#include <equal/core/component.hpp>

namespace eq {

Component::~Component() { delete m_target; }

void Component::target(GameObject *target) { m_target = target; }

} // namespace eq
