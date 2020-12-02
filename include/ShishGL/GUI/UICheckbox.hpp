/*============================================================================*/
#ifndef SHISHGL_UICHECKBOX_HPP
#define SHISHGL_UICHECKBOX_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "Clickable.hpp"
/*============================================================================*/
namespace Sh {

    template <typename Toggler>
    class UICheckbox : public UIWindow {
    public:

        enum States {
            CHECKED = HOLD + 1
        };

        template <typename... Args>
        explicit UICheckbox(const Frame& frame, Args&&... args);

    };

    template <typename Toggler>
    class CheckboxBehavior : public Clickable {
    public:

        template <typename... Args>
        explicit CheckboxBehavior(UIWindow* target, Args&&... args)
                : Clickable(target)
                , toggler(std::forward<Args>(args)...)
                , is_toggled(false)
                { }

        void reactOnRelease(MouseButtonEvent& event) override {
            if (is_toggled) {
                target<UICheckbox<Toggler>>()->setState(UIWindow::NORMAL);
                is_toggled = false;
                toggler.off();
            } else {
                target<UICheckbox<Toggler>>()->setState(UICheckbox<Toggler>::CHECKED);
                is_toggled = true;
                toggler.on();
            }
        }

    private:

        Toggler toggler;
        bool is_toggled;

    };

    /*------------------------------------------------------------------------*/

    template <typename Toggler>
    template <typename... Args>
    UICheckbox<Toggler>::UICheckbox(const Frame& frame, Args&&... args)
            : UIWindow(frame) {
        addBehavior<CheckboxBehavior<Toggler>>(std::forward<Args>(args)...);
    }

}
/*============================================================================*/
#endif //SHISHGL_UICHECKBOX_HPP
/*============================================================================*/
