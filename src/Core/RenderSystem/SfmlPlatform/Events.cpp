/*============================================================================*/
#include <cassert>

#include "Platform.hpp"
#include "EventManager.hpp"
#include "MouseEvent.hpp"
#include "KeyboardEvent.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

bool pollMouseButton(const sf::Event& sf_event) {

    assert(sf_event.type == sf::Event::MouseButtonPressed ||
           sf_event.type == sf::Event::MouseButtonReleased);

    Mouse::ButtonState state = Mouse::DOWN;
    switch (sf_event.type) {

        case sf::Event::MouseButtonPressed:  state = Mouse::DOWN; break;
        case sf::Event::MouseButtonReleased: state = Mouse::UP;   break;

        default:
            return false;

    }

    Vector2<double> where{
            static_cast<double>(sf_event.mouseButton.x),
            static_cast<double>(sf_event.mouseButton.y)
    };

    Mouse::Button button = Mouse::LEFT;
    switch (sf_event.mouseButton.button) {

        case sf::Mouse::Left:   button = Mouse::LEFT;   break;
        case sf::Mouse::Right:  button = Mouse::RIGHT;  break;
        case sf::Mouse::Middle: button = Mouse::MIDDLE; break;

        default:
            return false;
    }

    EventManager::postEvent<MouseButtonEvent>(where, button, state);

    return true;
}

/*----------------------------------------------------------------------------*/

bool pollMouseScroll(const sf::Event& sf_event) {

    assert(sf_event.type == sf::Event::MouseWheelScrolled);

    Vector2<double> where{
            static_cast<double>(sf_event.mouseWheelScroll.x),
            static_cast<double>(sf_event.mouseWheelScroll.y)
    };

    /* todo: make configs of mouse inversion */
    Mouse::ScrollDelta delta = -1.0 * sf_event.mouseWheelScroll.delta;

    Mouse::ScrollType type = Sh::Mouse::VERTICAL;
    if (sf_event.mouseWheelScroll.wheel == sf::Mouse::Wheel::HorizontalWheel) {
        type = Sh::Mouse::HORIZONTAL;
    }

    EventManager::postEvent<MouseScrollEvent>(where, delta, type);

    return true;
}

/*----------------------------------------------------------------------------*/

bool pollMouseMove(const sf::Event& sf_event) {

    assert(sf_event.type == sf::Event::MouseMoved);

    Vector2<double> where{
            static_cast<double>(sf_event.mouseMove.x),
            static_cast<double>(sf_event.mouseMove.y)
    };

    EventManager::postEvent<MouseEvent>(where);

    return true;
}

/*----------------------------------------------------------------------------*/

bool pollKeyboard(const sf::Event& sf_event) {

    assert(sf_event.type == sf::Event::KeyPressed ||
           sf_event.type == sf::Event::KeyReleased);

    Keyboard::Key key = Keyboard::Key::UNKNOWN;
    if (sf_event.key.code <= sf::Keyboard::Num9) {

        key = static_cast<Keyboard::Key>(sf_event.key.code);

    } else {

        key = Keyboard::Key::UNKNOWN;
        /* todo: handle others */

    }

    Keyboard::KeyState state = Keyboard::DOWN;
    if (sf_event.type == sf::Event::KeyPressed) {
        state = Keyboard::DOWN;
    } else {
        state = Keyboard::UP;
    }

    Keyboard::ModifierMask modifiers = 0;
    if (sf_event.key.alt) {
        modifiers |= Keyboard::L_ALT_MOD;
        modifiers |= Keyboard::R_ALT_MOD;
    }
    if (sf_event.key.control) {
        modifiers |= Keyboard::L_CTRL_MOD;
        modifiers |= Keyboard::R_CTRL_MOD;
    }
    if (sf_event.key.shift) {
        modifiers |= Keyboard::L_SHIFT_MOD;
        modifiers |= Keyboard::R_SHIFT_MOD;
    }
    if (sf_event.key.system) {
        modifiers |= Keyboard::META_MOD;
    }

    EventManager::postEvent<KeyboardEvent>(key, state, modifiers);

    return true;
}

/*----------------------------------------------------------------------------*/

bool SfmlPlatform::pollEvent() {

    sf::Event sfml_event = {};

    while (canvas->pollEvent(sfml_event)) {
        switch (sfml_event.type) {

            case sf::Event::Closed:
                is_running = false;
                break;

            case sf::Event::MouseButtonPressed:
            case sf::Event::MouseButtonReleased:
                return pollMouseButton(sfml_event);

            case sf::Event::MouseMoved:
                return pollMouseMove(sfml_event);

            case sf::Event::MouseWheelScrolled:
                return pollMouseScroll(sfml_event);

            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased:
                return pollKeyboard(sfml_event);

            default:
                break;
        }
    }

    return false;
}

/*============================================================================*/