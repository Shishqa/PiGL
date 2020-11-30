/*============================================================================*/
#ifndef SHISHGL_CURSOR_LOCATOR_HPP
#define SHISHGL_CURSOR_LOCATOR_HPP
/*============================================================================*/
#include "UIWindow.hpp"
/*============================================================================*/
namespace ShishGL {

    class CursorLocator : public UIWindow {
    public:

        explicit CursorLocator(const Viewport& viewport)
            : UIWindow(viewport) {
            SubscriptionManager::subscribe(EventSystem::SystemEvents, this);
        }

    protected:

        bool onMouseMove(MouseEvent& event) override {
            UIWindow::setPos(event.where());
            return true;
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_CURSOR_LOCATOR_HPP
/*============================================================================*/