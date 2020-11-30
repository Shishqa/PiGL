/*============================================================================*/
#ifndef SHISHGL_SYSTEM_OBJECT_HPP
#define SHISHGL_SYSTEM_OBJECT_HPP
/*============================================================================*/
#include "Listener.hpp"
/*============================================================================*/
namespace Sh {

    class PlatformListener : public Listener {
    public:

        ~PlatformListener() override = default;

    protected:

        /*---------------------------------------------------------*/
        virtual bool onMouseMove(class MouseEvent&);

        virtual bool onMouseButton(class MouseButtonEvent&);

        virtual bool onMouseScroll(class MouseScrollEvent&);

        virtual bool onKeyboard(class KeyboardEvent&);

        virtual bool onTimer(class TimerEvent&);
        /*---------------------------------------------------------*/

        friend class MouseEvent;
        friend class MouseButtonEvent;
        friend class MouseScrollEvent;
        friend class KeyboardEvent;
        friend class TimerEvent;

    };

}
/*============================================================================*/
#endif //SHISHGL_SYSTEM_OBJECT_HPP
/*============================================================================*/
