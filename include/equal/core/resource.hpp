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
#include <unordered_map>
#include <equal/core/types.hpp>

namespace eq {

/**
 * @ingroup core
 * @brief Manager to load and store resources
 */
class ResourceManager {
private:
  std::unordered_map<std::string, eq::Texture *> m_textures;
  std::unordered_map<std::string, eq::Font *> m_fonts;

public:
  /**
   * @brief Construct a new Resource Manager object
   */
  ResourceManager() = default;

  /**
   * @brief Destroy the Resource Manager object
   */
  ~ResourceManager() = default;

  /**
   * @brief Load all resources
   */
  void loadAll();

  /**
   * @brief Get the Texture object
   *
   * @param name const std::string&
   * @return eq::Texture*
   */
  eq::Texture *getTexture(const std::string &name);

  /**
   * @brief Get the Font object
   *
   * @param name const std::string&
   * @return eq::Font*
   */
  eq::Font *getFont(const std::string &name);
};

} // namespace eq

extern eq::ResourceManager g_res;
