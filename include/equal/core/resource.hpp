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
