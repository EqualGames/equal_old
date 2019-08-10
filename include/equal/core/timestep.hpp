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
#pragma once

#include <functional>
#include <equal/core/types.hpp>

namespace eq {

/**
 * @ingroup core
 * @brief Class to measure and generate informations
 */
class Timestep {
private:
  float last_time{0.0f};
  float last_fixed_time{0.0f};

public:
  /**
   * @brief Constant value represent 60FPS
   */
  const float FIXED_FPS = 0.016666667f;
  /**
   * @brief Constant value represent 300FPS
   */
  const float MAX_FPS = 3.333333333f;
  /**
   * @brief Frames per second (read-only)
   */
  ReadOnly<int, Timestep> fps{0};
  /**
   * @brief Delta Time (read-only)
   */
  ReadOnly<float, Timestep> time{0.0f};
  /**
   * @brief Fixed Delta Time (read-only)
   */
  ReadOnly<float, Timestep> fixed_time{0.0f};

  /**
   * @brief Construct a new Timestep object
   */
  Timestep();

  /**
   * @brief Destroy the Timestep object
   */
  ~Timestep();

  /**
   * @brief Cast to float
   *
   * @return float
   */
  operator float() const;

  /**
   * @brief Fix time loop
   *
   * @param fn const std::function<void(const eq::Timestep &timestep)> &
   */
  void fix(const std::function<void(const Timestep &timestep)> &fn);

  /**
   * @brief Mark elpased time
   */
  void reset();
};

} // namespace eq
