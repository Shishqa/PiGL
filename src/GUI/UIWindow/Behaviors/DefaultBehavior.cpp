/*============================================================================*/
#include "DefaultBehavior.hpp"
#include "SubscriptionManager.hpp"
#include "EventSystem.hpp"
#include "UIWindow.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

DefaultBehavior::DefaultBehavior(UIWindow* target)
        : Behavior(target) {
    SubscriptionManager::subscribe(EventSystem::SystemEvents, this, MOUSE_MOVE);
}

/*----------------------------------------------------------------------------*/

bool DefaultBehavior::onMouseEntered(MouseEvent&) { return false; }

bool DefaultBehavior::onMouseLeft(MouseEvent&) { return false; }

/*----------------------------------------------------------------------------*/

bool DefaultBehavior::onMouseMove(MouseEvent& event) {

    bool is_event_inside = target<UIWindow>()->contains(event.where());

    if (target<UIWindow>()->getState() == UIWindow::HOVER && !is_event_inside) {

        target<UIWindow>()->setState(UIWindow::NORMAL);

        return onMouseLeft(event);

    } else if (target<UIWindow>()->getState() == UIWindow::NORMAL && is_event_inside) {

        target<UIWindow>()->setState(UIWindow::HOVER);

        return onMouseEntered(event);
    }

    return is_event_inside;
}

/*============================================================================*/