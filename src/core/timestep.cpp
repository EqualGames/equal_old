#include <equal/core/timestep.hpp>
#include <equal/core/window.hpp>
#include <equal/helper/system.hpp>

namespace eq {

Timestep::Timestep() { reset(); }

Timestep::~Timestep() {}

Timestep::operator float() const { return time; }

void Timestep::fix(const std::function<void(const Timestep &timestep)> &fn) {
  while (last_fixed_time >= FIXED_FPS) {
    fixed_time = last_fixed_time / FIXED_FPS;
    fn(*this);
    last_fixed_time -= FIXED_FPS;
  }
}

void Timestep::reset() {
  if (eq::GetWindow()) {
    const float now = eq::GetWindow()->time();
    time = now - last_time;
    fps = static_cast<int>(1.0f / time);
    last_fixed_time = last_fixed_time + time;
    last_time = now;
  }
}

} // namespace eq
