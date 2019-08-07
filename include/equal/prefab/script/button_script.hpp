#pragma once

#include <type_traits>
#include <functional>
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
class ButtonScript : public Script, public IOnMouseMove, public IOnMousePress, public IOnMouseRelease {
private:
  enum State { Normal = 0, Hovered, Pressed, Dragging };
  State m_state{State::Normal};
  Color m_color_normal{255, 255, 255, 255};
  Color m_color_hover{192, 192, 192, 255};
  Color m_color_pressed{128, 128, 128, 255};
  ActionPerform m_action;

public:
  void start() override;
  void end() override;
  void update(const Timestep &timestep) override;
  void fixed_update(const Timestep &timestep) override;

  void registerAction(const ActionPerform &fn);

  void onMouseMove(const Position &position) override;
  void onMousePress(Mouse::Button button, const Position &position) override;
  void onMouseRelease(Mouse::Button button, const Position &position) override;
};

} // namespace eq
