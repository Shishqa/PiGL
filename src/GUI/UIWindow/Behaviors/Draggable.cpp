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
        drag(event.where() - dragPoint());
    }

    return true;
}

void Draggable::drag(const Vector2<double>& delta) {

    if (!Holdable::isHeld()) {
        Holdable::n_held++;
    }

    target<UIWindow>()->translate(delta);
    drag_point += delta;

    onDrag(delta);
}

/*============================================================================*/