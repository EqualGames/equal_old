#pragma once

#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>

namespace eq::ui {

class Image;

/**
 * @ingroup ui
 * @brief UI flask bar
 */
class FlaskBar : public GameObject {
private:
  float m_max_value{0};
  Image *m_foreground{nullptr};
  Image *m_background{nullptr};

public:
  FlaskBar(float value, float max_value, const Position &position, const Size &size);
  virtual ~FlaskBar();

  void value(float value);
  void max_value(float value);
  void color(const Color &color);
};

} // namespace eq::ui
