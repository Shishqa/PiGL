/*============================================================================*/
#ifndef SHISHGL_UIDIALOG_HPP
#define SHISHGL_UIDIALOG_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "WindowManager.hpp"
#include "UITriggers.hpp"
#include "Behaviors.hpp"
#include "Styles.hpp"
/*============================================================================*/
namespace Sh {

    class WindowCloser {
    public:

        explicit WindowCloser(UIWindow* to_close)
                : target(to_close)
                { }

        void operator()() {
            WindowManager::destroy(target);
        }

    private:

        UIWindow* target;
    };

    /*------------------------------------------------------------------------*/

    class DialogBehavior : public Draggable {
    public:

        explicit DialogBehavior(UIWindow* target)
                : Draggable(target)
                { }

        bool onMouseButton(MouseButtonEvent& event) override {

            if (event.state() == Mouse::UP) {
                return Draggable::onMouseButton(event);
            }

            for (auto& child : target<UIWindow>()->getChildren()) {
                if (child->contains(event.where())) {
                    return false;
                }
            }

            return Draggable::onMouseButton(event);
        }
    };

    /*------------------------------------------------------------------------*/


    class UIDialog : public UIWindow {
    public:

        explicit UIDialog(const Frame& frame)
                : UIWindow(frame) {

            addBehavior<DialogBehavior>();
            attach<UIButton<WindowCloser>>(
                    Frame{ {0, 0}, {20, 20} },
                    this
                    )
                    ->applyStyle<UIWindow::NORMAL>(
                        ColorFill(Color::RED)
                        )
                    ->applyStyle<UIWindow::HOVER>(
                        ColorFill(Color::LIGHT_PINK)
                        );
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_UIDIALOG_HPP
/*============================================================================*/
