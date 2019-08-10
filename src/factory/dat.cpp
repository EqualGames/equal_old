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
