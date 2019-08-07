#pragma once

#include <string>
#include <unordered_map>
#include <equal/core/types.hpp>

namespace eq {

/**
 * @ingroup factories
 * @brief Load textures stored in DAT file
 * 
 * @return std::unordered_map<std::string, eq::Texture *> 
 */
std::unordered_map<std::string, eq::Texture *> LoadTextureFromDAT();

} // namespace eq
