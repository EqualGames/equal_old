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
