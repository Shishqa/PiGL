/*============================================================================*/
#include "Clickable.hpp"
#include "SubscriptionManager.hpp"
#include "EventSystem.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

Clickable::Clickable(UIWindow *target)
        : DefaultBehavior(target) {
    SubscriptionManager::subscribe(EventSystem::SystemEvents, this,
                                   MOUSE_BUTTON);
}

/*----------------------------------------------------------------------------*/

void Clickable::reactOnPress(MouseButtonEvent&)   { /* something */ }
void Clickable::reactOnRelease(MouseButtonEvent&) { /* something */ }

/*----------------------------------------------------------------------------*/

bool Clickable::onMouseButton(MouseButtonEvent& event) {

    bool is_event_inside = target<UIWindow>()->contains(event.where());

    if (event.state() == Mouse::DOWN && !is_event_inside) {
        return false;
    }

    if (Mouse::DOWN == event.state()) {
        target<UIWindow>()->setState(UIWindow::CLICK);
        reactOnPress(event);
    } else if (is_event_inside) {
        target<UIWindow>()->setState(UIWindow::HOVER);
        reactOnRelease(event);
    } else {
        target<UIWindow>()->setState(UIWindow::NORMAL);
    }

    return true;
}

/*============================================================================*/

Holdable::Holdable(UIWindow* target)
        : Clickable(target)
        , n_held(0)
        { }

bool Holdable::isHeld() const {
    return n_held;
}

uint8_t Holdable::numHeld() const {
    return n_held;
}
/*----------------------------------------------------------------------------*/

bool Holdable::onMouseButton(MouseButtonEvent& event) {

    bool state = Clickable::onMouseButton(event);

    if (state && event.state() == Mouse::DOWN) {
        ++n_held;
        return true;
    } else if (state && event.state() == Mouse::UP) {
        n_held = (n_held ? n_held - 1 : 0);
        return true;
    }

    return false;
}

/*----------------------------------------------------------------------------*/

void Holdable::reactOnHold(TimerEvent &) { /* something */ }

bool Holdable::onTimer(TimerEvent& event) {

    if (isHeld()) {
        target<UIWindow>()->setState(UIWindow::HOLD);
        reactOnHold(event);
        return true;
    }

    return false;
}

/*============================================================================*/
