#pragma once

#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>

namespace eq::ui {

/**
 * @ingroup ui
 * @brief UI canvas
 */
class Canvas : public GameObject {
public:
  Canvas(const Position &position, const Size &size);
  virtual ~Canvas() = default;
};

} // namespace eq::ui
