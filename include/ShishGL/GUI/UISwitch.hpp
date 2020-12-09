/*============================================================================*/
#ifndef SHISHGL_UISWITCH_HPP
#define SHISHGL_UISWITCH_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "Clickable.hpp"
/*============================================================================*/
namespace Sh {

    class ClickSwitchable : public Clickable {
    public:

        explicit ClickSwitchable(UIWindow* target, bool turned = false)
                : Clickable(target)
                , turned_on(turned)
                { }

        void reactOnRelease(MouseButtonEvent& event) override {
            if (!turned_on) {
                select();
            } else {
                deselect();
            }
        }

        void select() {
            turned_on = true;
            target<UIWindow>()->setState(UIWindow::SELECTED);
            onSelect();
        }

        void deselect() {
            turned_on = false;
            target<UIWindow>()->setState(UIWindow::NORMAL);
            onDeselect();
        }

        virtual void onSelect() { }

        virtual void onDeselect() { }

    private:

        bool turned_on;
    };

}
/*============================================================================*/
#endif //SHISHGL_UISWITCH_HPP
/*============================================================================*/
