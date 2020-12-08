/*============================================================================*/
#ifndef SHISHGL_UI_BUTTON_HPP
#define SHISHGL_UI_BUTTON_HPP
/*============================================================================*/
#include <cstdint>

#include "DefaultBehavior.hpp"
/*============================================================================*/
namespace Sh {

    class Clickable : public DefaultBehavior {
    public:

        explicit Clickable(UIWindow* target);

        virtual void reactOnPress(MouseButtonEvent& event);

        virtual void reactOnRelease(MouseButtonEvent& event);

        bool onMouseButton(MouseButtonEvent& event) override;

    };

    /*------------------------------------------------------------------------*/

    class Holdable : public Clickable {
    public:

        explicit Holdable(UIWindow* target);

        [[nodiscard]]
        bool isHeld() const;

        [[nodiscard]]
        uint8_t numHeld() const;

        virtual void reactOnHold(TimerEvent& event);

        bool onTimer(TimerEvent& event) override;

        bool onMouseButton(MouseButtonEvent& event) override;

    protected:

        uint8_t n_held;

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_BUTTON_HPP
/*============================================================================*/
