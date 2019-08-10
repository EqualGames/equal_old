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
#include <equal/core/resource.hpp>
#include <equal/helper/string.hpp>
#include <equal/helper/error.hpp>
#include <equal/helper/string.hpp>
#include <equal/factory/texture.hpp>
#include <equal/factory/font.hpp>

eq::ResourceManager g_res;

namespace eq {

void ResourceManager::loadAll() {
  m_textures = eq::LoadTextureFromDAT();
  m_fonts = eq::LoadFontFromDAT();
}

Texture *ResourceManager::getTexture(const std::string &filename) {
  if (m_textures.find(filename) != m_textures.end()) {
    return m_textures.at(filename);
  }

  return nullptr;
}

Font *ResourceManager::getFont(const std::string &filename) {
  if (m_fonts.find(filename) != m_fonts.end()) {
    return m_fonts.at(filename);
  }

  return nullptr;
}

} // namespace eq
