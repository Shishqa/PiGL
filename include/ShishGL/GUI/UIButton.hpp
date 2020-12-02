/*============================================================================*/
#ifndef SHISHGL_UIBUTTON_HPP
#define SHISHGL_UIBUTTON_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "Clickable.hpp"
/*============================================================================*/
namespace Sh {

    template <typename Callback>
    class ButtonBehavior : public Clickable {
    public:

        template <typename... Args>
        explicit ButtonBehavior(UIWindow* target, Args&&... args)
                : Clickable(target)
                , callback(std::forward<Args>(args)...)
                { }

        void reactOnRelease(MouseButtonEvent& event) override {
            callback();
        }

    private:

        Callback callback;

    };

    /*------------------------------------------------------------------------*/

    template <typename Callback>
    class UIButton : public UIWindow {
    public:

        template <typename... Args>
        explicit UIButton(const Frame& frame, Args&&... args)
                : UIWindow(frame) {
            addBehavior<ButtonBehavior<Callback>>(std::forward<Args>(args)...);
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_UIBUTTON_HPP
/*============================================================================*/