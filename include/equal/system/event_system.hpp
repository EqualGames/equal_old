#pragma once

#include <string>
#include <equal/core/types.hpp>
#include <equal/core/game_object.hpp>
#include <equal/core/system.hpp>
#include <equal/event/mouse_move.hpp>
#include <equal/event/mouse_press.hpp>
#include <equal/event/mouse_release.hpp>
#include <equal/event/key_press.hpp>
#include <equal/event/key_release.hpp>
#include <equal/event/insert_text.hpp>

namespace eq {

/**
 * @ingroup systems
 * @brief System to manager and dispatch events
 */
class EventSystem : public System,
                    public IOnMouseMove,
                    public IOnMousePress,
                    public IOnMouseRelease,
                    public IOnKeyPress,
                    public IOnKeyRelease,
                    public IOnInsertText {
private:
  bool m_dragging{false};
  GameObject *m_focused{nullptr};

  void emit(Input::Event event, const GameObject &object, Input::EventData *data) const;
  GameObject *check_tree(GameObject *object, const Position &position) const;

public:
  void start() override;
  void end() override;

  void onMouseMove(const Position &position) override;
  void onMousePress(Mouse::Button button, const Position &position) override;
  void onMouseRelease(Mouse::Button button, const Position &position) override;
  void onKeyPress(Keyboard::Key key) override;
  void onKeyRelease(Keyboard::Key key) override;
  void onInsertText(const std::wstring &text) override;
};

} // namespace eq
