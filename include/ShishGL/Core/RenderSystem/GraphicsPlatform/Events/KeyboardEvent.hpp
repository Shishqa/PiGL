/*============================================================================*/
#ifndef SHISHGL_KEYBOARD_EVENT_HPP
#define SHISHGL_KEYBOARD_EVENT_HPP
/*============================================================================*/
#include "Event.hpp"
#include "Keyboard.hpp"
#include "PlatformListener.hpp"
/*============================================================================*/
namespace ShishGL {

    class KeyboardEvent : public Event {
    public:

        KeyboardEvent(Keyboard::Key key,
                      Keyboard::KeyState state,
                      Keyboard::ModifierMask modifiers);

        ~KeyboardEvent() override = default;

        EventMask mask() override {
            return KEYBOARD;
        }

        [[nodiscard]]
        inline Keyboard::Key key() const;

        [[nodiscard]]
        inline Keyboard::KeyState state() const;

        [[nodiscard]]
        inline Keyboard::ModifierMask modifiers() const;

        bool happen(Listener* listener) override;

    protected:

        Keyboard::Key k_key;
        Keyboard::KeyState k_state;
        Keyboard::ModifierMask k_modifiers;

    };

}
/*============================================================================*/
#endif //SHISHGL_KEYBOARD_EVENT_HPP
/*============================================================================*/
