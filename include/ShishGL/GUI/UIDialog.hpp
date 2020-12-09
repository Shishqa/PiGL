/*============================================================================*/
#ifndef SHISHGL_UIDIALOG_HPP
#define SHISHGL_UIDIALOG_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "UIButton.hpp"
#include "Draggable.hpp"
/*============================================================================*/
namespace Sh {

    class WindowCloser : public Clickable {
    public:

        explicit WindowCloser(UIWindow* target, Window* close_target,
                              int signal);

        void reactOnRelease(MouseButtonEvent& event) override;

    private:

        Window* to_close;
        int to_send;
    };

    class UIDialog : public UIWindow {
    public:

        static constexpr double HEADER_SIZE = 30;
        static constexpr double BORDER_SIZE = 5;
        static constexpr Vector2<double> BUTTON_SIZE = {
            HEADER_SIZE - 2 * BORDER_SIZE,
            HEADER_SIZE - 2 * BORDER_SIZE
        };

        explicit UIDialog(UIWindow* contents);

        UIButton<WindowCloser>* closer;
        UIWindow* contents;
    };

    class DialogBehavior : public Draggable {
    public:

        explicit DialogBehavior(UIWindow* target);

        bool onMouseButton(MouseButtonEvent& event) override;

        bool onWindowClose(WindowCloseEvent& event) override {
            if (event.who() == target<UIDialog>()->contents) {
                WindowManager::destroy(target<UIDialog>());
                return true;
            }
            return false;
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_UIDIALOG_HPP
/*============================================================================*/