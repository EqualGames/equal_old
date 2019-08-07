#pragma once

#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>

namespace eq::ui {

class Image;

/**
 * @ingroup ui
 * @brief UI progress bar
 */
class ProgressBar : public GameObject {
private:
  float m_value{0};
  float m_max_value{0};
  Image *m_foreground{nullptr};
  Image *m_background{nullptr};

public:
  ProgressBar(const std::string &id);
  ProgressBar(float value, float max_value, const Position &position, const Size &size);
  virtual ~ProgressBar();

  void value(float value);
  float value() const;
  void max_value(float value);
  float max_value() const;
};

} // namespace eq::ui
