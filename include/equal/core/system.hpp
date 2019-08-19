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

#include <equal/core/timestep.hpp>

namespace eq {

/**
 * @defgroup systems Systems
 * @ingroup core
 * @brief Systems definitions
 */

/**
 * @ingroup core
 * @brief System base
 */
class System {
public:
  virtual ~System() { end(); };

  virtual void start(){};
  virtual void end(){};
  virtual void update(const Timestep &timestep){};
  virtual void fixed_update(const Timestep &timestep){};
};

} // namespace eq
