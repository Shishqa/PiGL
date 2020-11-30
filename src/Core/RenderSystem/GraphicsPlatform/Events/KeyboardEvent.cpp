/*============================================================================*/
#include "KeyboardEvent.hpp"
#include "PlatformListener.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

KeyboardEvent::KeyboardEvent(Keyboard::Key key,
                             Keyboard::KeyState state,
                             Keyboard::ModifierMask modifiers)
                             : k_key(key)
                             , k_state(state)
                             , k_modifiers(modifiers)
                             { }

/*----------------------------------------------------------------------------*/

bool KeyboardEvent::happen(Listener* listener) {
    return dynamic_cast<PlatformListener*>(listener)->onKeyboard(*this);
}

/*----------------------------------------------------------------------------*/

Keyboard::Key KeyboardEvent::key() const {
    return k_key;
}

/*----------------------------------------------------------------------------*/

Keyboard::KeyState KeyboardEvent::state() const {
    return k_state;
}

/*----------------------------------------------------------------------------*/

Keyboard::ModifierMask KeyboardEvent::modifiers() const {
    return k_modifiers;
}

/*============================================================================*/
