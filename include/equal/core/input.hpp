/*
 * Copyright 2019 Equal Games
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <equal/core/types.hpp>

namespace eq {

/**
 * @ingroup core
 * @brief Cursor types and functions
 */
class Cursor {
public:
  /**
   * @brief Cursor types
   */
  enum Type {
    Arrow,
    ArrowWait,
    Wait,
    Text,
    Hand,
    SizeHorizontal,
    SizeVertical,
    SizeTopLeftBottomRight,
    SizeBottomLeftTopRight,
    SizeAll,
    Cross,
    Help,
    NotAllowed
  };
};

/**
 * @ingroup core
 * @brief Keyboard keys and functions
 */
class Keyboard {
public:
  /**
   * @brief Keyboard keys
   */
  enum Key {
    Unknown = -1,
    A = 0,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    Num0,
    Num1,
    Num2,
    Num3,
    Num4,
    Num5,
    Num6,
    Num7,
    Num8,
    Num9,
    Escape,
    LControl,
    LShift,
    LAlt,
    LSystem,
    RControl,
    RShift,
    RAlt,
    RSystem,
    Menu,
    LBracket,
    RBracket,
    Semicolon,
    Comma,
    Period,
    Quote,
    Slash,
    Backslash,
    Tilde,
    Equal,
    Hyphen,
    Space,
    Enter,
    Backspace,
    Tab,
    PageUp,
    PageDown,
    End,
    Home,
    Insert,
    Delete,
    Add,
    Subtract,
    Multiply,
    Divide,
    Left,
    Right,
    Up,
    Down,
    Numpad0,
    Numpad1,
    Numpad2,
    Numpad3,
    Numpad4,
    Numpad5,
    Numpad6,
    Numpad7,
    Numpad8,
    Numpad9,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    F13,
    F14,
    F15,
    Pause,
    KeyCount
  };

  /**
   * @brief Convert key code to eq::Keyboard::Key
   *
   * Overrided by selected platform to convert key codes
   *
   * @param key int
   * @return eq::Keyboard::Key
   */
  static eq::Keyboard::Key from(int key);
};

/**
 * @ingroup core
 * @brief Mouse buttons and functions
 */
class Mouse {
public:
  /**
   * @brief Mouse buttons
   */
  enum Button { Left, Right, Middle, XButton1, XButton2, ButtonCount };

  /**
   * @brief Mouse wheel directions
   */
  enum Wheel { VerticalWheel, HorizontalWheel };

  /**
   * @brief Parser generic code to eq::Mouse::Button
   *
   * @param button
   * @return eq::Mouse::Button
   */
  static eq::Mouse::Button from(uint8_t button);
};

/**
 * @ingroup core
 * @brief Input types and data
 */
class Input {
public:
  /**
   * @brief Input Events
   */
  enum Event { MouseMove, MousePress, MouseRelease, KeyPress, KeyRelease, InsertText };

  /**
   * @brief Event data structure
   */
  struct EventData {
    eq::Position mouse{0, 0};
    eq::Mouse::Button mouse_button{Mouse::Button::ButtonCount};
    eq::Keyboard::Key key{Keyboard::Key::Unknown};
    std::wstring text;
  };

  /**
   * @see https://www.boost.org/doc/libs/1_67_0/doc/html/signals2.html
   */
  using EventHandler = std::function<void(EventData *)>;

  /**
   * @see https://www.boost.org/doc/libs/1_67_0/doc/html/signals2.html
   */
  using OnMouseMove = boost::signals2::signal<void(EventData *)>;

  /**
   * @see https://www.boost.org/doc/libs/1_67_0/doc/html/signals2.html
   */
  using OnMousePress = boost::signals2::signal<void(EventData *)>;

  /**
   * @see https://www.boost.org/doc/libs/1_67_0/doc/html/signals2.html
   */
  using OnMouseRelease = boost::signals2::signal<void(EventData *)>;

  /**
   * @see https://www.boost.org/doc/libs/1_67_0/doc/html/signals2.html
   */
  using OnKeyPress = boost::signals2::signal<void(EventData *)>;

  /**
   * @see https://www.boost.org/doc/libs/1_67_0/doc/html/signals2.html
   */
  using OnKeyRelease = boost::signals2::signal<void(EventData *)>;

  /**
   * @see https://www.boost.org/doc/libs/1_67_0/doc/html/signals2.html
   */
  using OnInsertText = boost::signals2::signal<void(EventData *)>;
};

} // namespace eq
