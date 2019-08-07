#pragma once

#include <string>
#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>

namespace eq::ui {

/**
 * @ingroup ui
 * @brief UI container
 */
class Container : public GameObject {
public:
  Container(const std::string& id = "");
  Container(const Position &position, const Size &size);
  virtual ~Container();
};

} // namespace eq::ui
