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
