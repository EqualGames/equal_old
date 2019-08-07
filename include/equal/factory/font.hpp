#pragma once

#include <string>
#include <unordered_map>
#include <equal/core/types.hpp>

namespace eq {

/**
 * @ingroup factories
 * @brief Load fonts stored in DAT file
 * 
 * @return std::unordered_map<std::string, eq::Font *> 
 */
std::unordered_map<std::string, eq::Font *> LoadFontFromDAT();

} // namespace eq
