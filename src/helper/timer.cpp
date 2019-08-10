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
#include <equal/helper/timer.hpp>

namespace eq {

Timer::Timer(const std::string &name) {
  m_name = name;
  m_start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() { stop(); }

void Timer::stop() {
  auto end = std::chrono::high_resolution_clock::now();

  auto t_start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
  auto t_end = std::chrono::time_point_cast<std::chrono::microseconds>(end).time_since_epoch().count();

  auto duration = t_end - t_start;
  double ms = duration * 0.001;

  EQ_DEBUG("{} [{} us ({} ms)]", m_name, duration, ms);
}

} // namespace eq
