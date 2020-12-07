/*============================================================================*/
#ifndef SHISHGL_UITRIGGERS_HPP
#define SHISHGL_UITRIGGERS_HPP
/*============================================================================*/
#include "Behaviors.hpp"
#include "UIWindow.hpp"
/*============================================================================*/
namespace Sh {

    template <typename Callback>
    class ClickReactive : public Clickable {
    public:

        template <typename... Args>
        explicit ClickReactive(UIWindow* target, Args&&... args)
                : Clickable(target)
                , callback(std::forward<Args>(args)...)
        { }

        void reactOnRelease(MouseButtonEvent& event) override {
            callback();
        }

    private:

        Callback callback;
    };

    template <typename Switch>
    class Switchable : public ClickReactive<Switch> {
    public:

        template <typename... Args>
        explicit Switchable(UIWindow* target, Args&&... args)
                : Clickable(target)
                , sw(std::forward<Args>(args)...)
                , on(false)
        { }

        void reactOnRelease(MouseButtonEvent& event) override {
            if (on) {
                ClickReactive<Switch>::template target<UIWindow>()->setState(UIWindow::NORMAL);
                on = false;
                sw.off();
            } else {
                ClickReactive<Switch>::template target<UIWindow>()->setState(UIWindow::SELECTED);
                on = true;
                sw.on();
            }
        }

    private:

        Switch sw;
        bool on;

    };

    /*------------------------------------------------------------------------*/

    template <typename Callback>
    class UIButton : public UIWindow {
    public:

        template <typename... Args>
        explicit UIButton(const Frame& frame, Args&&... args)
                : UIWindow(frame) {
            addBehavior<ClickReactive<Callback>>(std::forward<Args>(args)...);
        }

    };

    template <typename Switch>
    class UICheckbox : public UIWindow {
    public:

        template <typename... Args>
        explicit UICheckbox(const Frame& frame, Args&&... args)
                : UIWindow(frame) {
            addBehavior<Switchable<Switch>>(std::forward<Args>(args)...);
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_UITRIGGERS_HPP
/*============================================================================*/