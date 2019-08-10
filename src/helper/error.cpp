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
#include <equal/helper/error.hpp>
#include <iostream>

namespace eq {

void StackTrace(const std::exception &exception, int level) {
  std::cerr << std::string(level, ' ') << " exception: " << exception.what() << std::endl;
  try {
    std::rethrow_if_nested(exception);
  } catch (const std::exception &ex) {
    StackTrace(ex, level + 1);
  } catch (...) {
    std::cerr << "Unknow error" << std::endl;
  }
}

} // namespace eq
