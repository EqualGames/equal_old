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

class GameObject;

/**
 * @brief Component Base
 * @ingroup core
 */
class Component {
protected:
  bool m_active{true};
  Ref<GameObject> m_target;

public:
  virtual ~Component();

  void target(Ref<GameObject> &target);

  /**
   * @brief Return if component has active
   *
   * @return bool
   */
  bool active() const;

  /**
   * @brief Set if component has active
   *
   * @param active bool
   */
  void active(bool active);


  /**
   * @brief
   *
   * @param timestep const eq::Timestep&
   */
  virtual void update(const Timestep &timestep) = 0;

  /**
   * @brief
   *
   * @param timestep const eq::Timestep&
   */
  virtual void fixed_update(const Timestep &timestep) = 0;
};

} // namespace eq
