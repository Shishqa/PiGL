/*============================================================================*/
#include "Draggable.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

Draggable::Draggable(UIWindow* target)
    : Holdable(target)
    , drag_point({})
    { }

const Vector2<double>& Draggable::dragPoint() const {
    return drag_point;
}

/*----------------------------------------------------------------------------*/

bool Draggable::onMouseButton(MouseButtonEvent& event) {

    Holdable::onMouseButton(event);

    if (Mouse::DOWN == event.state() &&
        1 == numHeld()) {
        drag_point = event.where();
    }

    return true;
}

/*----------------------------------------------------------------------------*/

bool Draggable::onMouseMove(MouseEvent& event) {

    Holdable::onMouseMove(event);

    if (isHeld()) {
        drag(event.where() - dragPoint(), Mouse::LEFT);
    }

    return true;
}

/*----------------------------------------------------------------------------*/

void Draggable::drag(const Vector2<double>& delta, Mouse::Button button) {

    bool emulation = false;

    if (!isHeld()) {
        MouseButtonEvent click{target<UIWindow>()->getPos(), button, Mouse::DOWN};
        onMouseButton(click);
        emulation = true;
    }

    target<UIWindow>()->translate(delta);
    drag_point += delta;

    if (emulation) {
        MouseButtonEvent click{target<UIWindow>()->getPos(), button, Mouse::UP};
        onMouseButton(click);
    }
}

/*============================================================================*/