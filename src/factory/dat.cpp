#include <equal/factory/dat.hpp>

namespace eq {

std::string_view ReadFile(const std::string &filename) {
  std::ifstream reader(filename, std::ios::in | std::ios::binary | std::ios::ate);
  if (!reader) {
    EQ_THROW("Can't open file");
  }

  int size = static_cast<int>(reader.tellg());
  reader.seekg(0, reader.beg);
  char *data = new char[size];
  reader.read(data, size);
  reader.close();

  if (!reader.good()) {
    EQ_THROW("Error occurred at reading time");
  }

  return std::string_view(data, size);
}

} // namespace eq
