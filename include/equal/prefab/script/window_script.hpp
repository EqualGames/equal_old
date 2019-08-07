#pragma once

#include <equal/core/types.hpp>
#include <equal/core/script.hpp>
#include <equal/event/mouse_move.hpp>
#include <equal/event/mouse_press.hpp>
#include <equal/event/mouse_release.hpp>

namespace eq {

/**
 * @ingroup scripts
 * @brief 
 */
class WindowScript : public Script, public IOnMouseMove, public IOnMousePress, public IOnMouseRelease {
private:
  enum State { Normal = 0, Dragging };
  State m_state{State::Normal};
  Position m_dragging_offset{0};
  BoundingBox m_drag_area{0, 0, 100, 24};

  bool in_drag_area(const Position &position);

public:
  void start() override;
  void end() override;
  void update(const Timestep& timestep) override;
  void fixed_update(const Timestep& timestep) override;

  void onMouseMove(const Position &position) override;
  void onMousePress(Mouse::Button button, const Position &position) override;
  void onMouseRelease(Mouse::Button button, const Position &position) override;
};

} // namespace eq
