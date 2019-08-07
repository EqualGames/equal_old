#pragma once

#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>

namespace eq::ui {

/**
 * @ingroup ui
 * @brief UI image
 */
class Image : public GameObject {
public:
  Image(const std::string& id = "");
  Image(const Position &position, const Size &size);
  virtual ~Image();

  void texture(Texture *texture);
};

} // namespace eq::ui
