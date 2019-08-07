#pragma once

#include <string>
#include <equal/core/types.hpp>
#include <equal/core/script.hpp>
#include <equal/event/mouse_move.hpp>
#include <equal/event/mouse_press.hpp>
#include <equal/event/mouse_release.hpp>
#include <equal/event/key_press.hpp>
#include <equal/event/insert_text.hpp>

namespace eq {

class GameObject;

/**
 * @ingroup scripts 
 * @brief
 */
class TextInputScript : public Script,
                        public IOnMouseMove,
                        public IOnMousePress,
                        public IOnKeyPress,
                        public IOnInsertText {
private:
  enum State { Normal = 0, Hovered, Focused };
  State m_state{State::Normal};
  bool m_caret_visible{false};

public:
  void start() override;
  void end() override;
  void update(const Timestep &timestep) override;
  void fixed_update(const Timestep &timestep) override;

  void onMouseMove(const Position &position) override;
  void onMousePress(Mouse::Button button, const Position &position) override;
  void onKeyPress(Keyboard::Key key) override;
  void onInsertText(const std::wstring &text) override;
};

} // namespace eq
