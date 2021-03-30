/*============================================================================*/
#include "UIDialog.hpp"
#include "UIButton.hpp"
#include "Behaviors.hpp"
#include "Styles.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

DialogBehavior::DialogBehavior(UIWindow* target)
        : Draggable(target)
        { }

bool DialogBehavior::onMouseButton(MouseButtonEvent& event) {

    for (auto& child : target<UIWindow>()->getChildren()) {
        if (child->contains(event.where())) {
            return false;
        }
    }

    return Draggable::onMouseButton(event);
}

/*----------------------------------------------------------------------------*/

WindowCloser::WindowCloser(UIWindow* target, Window* close_target, int signal)
        : Clickable(target)
        , to_close(close_target)
        , to_send(signal)
        { }

void WindowCloser::reactOnRelease(MouseButtonEvent&) {
    WindowManager::destroy(to_close);
    EventSystem::sendEvent<WindowCloseEvent>(to_close, to_close, to_send);
}

/*----------------------------------------------------------------------------*/

UIDialog::UIDialog(UIWindow* window)
        : UIWindow(Frame{
            window->getPos() - Vector2<double>{BORDER_SIZE, HEADER_SIZE},
            window->getSize() + Vector2<double>{2 * BORDER_SIZE, HEADER_SIZE + BORDER_SIZE}
        }),
        contents(window) {

    attach(contents);
    contents->setPos(getPos() + Vector2<double>{BORDER_SIZE, HEADER_SIZE});

    closer = attach<UIButton<WindowCloser>>(
        Frame{
            {getSize().x - BORDER_SIZE - BUTTON_SIZE.x, BORDER_SIZE},
            BUTTON_SIZE
        },
        this, -1
        );

    closer->applyStyle<UIWindow::NORMAL>(
            ColorFill{ Color::RED }
        )
        ->applyStyle<UIWindow::HOVER>(
            ColorFill{ Color::PALE_GREEN }
        )
        ->applyStyle<UIWindow::CLICK>(
            ColorFill{ Color::WHITE }
        );

    applyStyle<UIWindow::NORMAL>(
        ColorFill{ Color::DARK_KHAKI }
        );

    setBehavior<DialogBehavior>();

    SubscriptionManager::subscribe<WindowCloseEvent>(as<DialogBehavior>(), contents);
}

/*============================================================================*/
