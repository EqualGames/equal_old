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

#include <string>
#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>

namespace eq::ui {

/**
 * @ingroup ui
 * @brief UI container
 */
class Container : public GameObject {
public:
  Container(const std::string& id = "");
  Container(const Position &position, const Size &size);
  virtual ~Container();
};

} // namespace eq::ui
