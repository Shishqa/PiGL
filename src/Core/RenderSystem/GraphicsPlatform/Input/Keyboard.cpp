/*============================================================================*/
#include "Keyboard.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

bool Keyboard::isConvertible(Keyboard::Key key) {
    return (Key::UNKNOWN < key && key < Key::LAST_CONVERTIBLE);
}

/*----------------------------------------------------------------------------*/

uint8_t Keyboard::convertToChar(Keyboard::Key key) {

    if (!isConvertible(key)) {
        return 0;
    }

    if (key <= Keyboard::Key::Z) {

        return static_cast<uint8_t>(key - Keyboard::Key::A) + 'a';

    } else if (key <= Keyboard::Key::Num9) {

        return static_cast<uint8_t>(key - Keyboard::Key::Num0) + '0';
    }

    switch (key) {

        case Key::SPACE:  return (' ');
        case Key::RETURN: return ('\n');
        case Key::COMMA:  return (',');
        case Key::DOT:    return ('.');

        default: return 0;

    }
}

/*============================================================================*/
