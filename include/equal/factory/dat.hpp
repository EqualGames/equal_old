#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <fstream>
#include <equal/core/logger.hpp>
#include <equal/helper/error.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/unordered_map.hpp>

namespace eq {

/**
 * @ingroup factories
 * @brief
 */
struct TextureDAT {
  std::string name;
  uint32_t first_id{0};
  uint16_t width{0};
  uint16_t height{0};
  uint8_t depth{0};
  int pitch{0};
  uint32_t format{0};
  bool compressed{false};
  std::vector<uint8_t> buffer;
};

/**
 * @ingroup factories
 * @brief
 */
struct FontDAT {
  std::string name;
  bool compressed{false};
  std::vector<uint8_t> buffer;
};

/**
 * @ingroup factories
 * @brief
 */
struct ResourceDAT {
  std::vector<TextureDAT> textures;
  std::vector<FontDAT> fonts;
};

/**
 * @ingroup factories
 * @brief
 *
 * @param filename
 * @return std::string_view
 */
std::string_view ReadFile(const std::string &filename);

/**
 * @ingroup factories
 * @brief
 *
 * @tparam T
 * @param name
 * @param data
 */
template <typename T>
void ReadDAT(const std::string &name, T &data) {
  std::ifstream reader(fmt::format("{0}.dat", name), std::ios::in | std::ios::binary);
  boost::archive::binary_iarchive ia(reader);
  ia >> data;
  reader.close();
}

/**
 * @ingroup factories
 * @brief
 *
 * @tparam T
 * @param name
 * @param data
 */
template <typename T>
void WriteDAT(const std::string &name, T &data) {
  std::ofstream writer(fmt::format("{0}.dat", name), std::ios::out | std::ios::binary);
  boost::archive::binary_oarchive oa(writer);
  oa << data;
  writer.close();
}

} // namespace eq

#include <equal/factory/dat.inl>
