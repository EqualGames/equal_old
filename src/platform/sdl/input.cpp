#ifdef EQ_SDL

#include <equal/platform/sdl/input.hpp>

namespace eq {

eq::Keyboard::Key eq::Keyboard::from(int key) {
  switch (key) {
  case SDLK_a:
    return Keyboard::Key::A;
    break;
  case SDLK_b:
    return Keyboard::Key::B;
    break;
  case SDLK_c:
    return Keyboard::Key::C;
    break;
  case SDLK_d:
    return Keyboard::Key::D;
    break;
  case SDLK_e:
    return Keyboard::Key::E;
    break;
  case SDLK_f:
    return Keyboard::Key::F;
    break;
  case SDLK_g:
    return Keyboard::Key::G;
    break;
  case SDLK_h:
    return Keyboard::Key::H;
    break;
  case SDLK_i:
    return Keyboard::Key::I;
    break;
  case SDLK_j:
    return Keyboard::Key::J;
    break;
  case SDLK_k:
    return Keyboard::Key::K;
    break;
  case SDLK_l:
    return Keyboard::Key::L;
    break;
  case SDLK_m:
    return Keyboard::Key::M;
    break;
  case SDLK_n:
    return Keyboard::Key::N;
    break;
  case SDLK_o:
    return Keyboard::Key::O;
    break;
  case SDLK_p:
    return Keyboard::Key::P;
    break;
  case SDLK_q:
    return Keyboard::Key::Q;
    break;
  case SDLK_r:
    return Keyboard::Key::R;
    break;
  case SDLK_s:
    return Keyboard::Key::S;
    break;
  case SDLK_t:
    return Keyboard::Key::T;
    break;
  case SDLK_u:
    return Keyboard::Key::U;
    break;
  case SDLK_v:
    return Keyboard::Key::V;
    break;
  case SDLK_w:
    return Keyboard::Key::W;
    break;
  case SDLK_x:
    return Keyboard::Key::X;
    break;
  case SDLK_y:
    return Keyboard::Key::Y;
    break;
  case SDLK_z:
    return Keyboard::Key::Z;
    break;
  case SDLK_BACKSPACE:
    return Keyboard::Key::Backspace;
    break;
  case SDLK_SPACE:
    return Keyboard::Key::Space;
    break;
  case SDLK_UNKNOWN:
  default:
    return Keyboard::Key::Unknown;
    break;
  }
}

eq::Mouse::Button eq::Mouse::from(uint8_t button) {
  if (button == SDL_BUTTON_LEFT) {
    return Mouse::Button::Left;
  } else if (button == SDL_BUTTON_MIDDLE) {
    return Mouse::Button::Middle;
  } else if (button == SDL_BUTTON_RIGHT) {
    return Mouse::Button::Right;
  } else if (button == SDL_BUTTON_X1) {
    return Mouse::Button::XButton1;
  } else if (button == SDL_BUTTON_X2) {
    return Mouse::Button::XButton2;
  } else {
    return Mouse::Button::ButtonCount;
  }
}

} // namespace eq

#endif
