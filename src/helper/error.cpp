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
