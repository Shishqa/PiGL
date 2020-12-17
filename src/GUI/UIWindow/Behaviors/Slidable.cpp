/*============================================================================*/
#include "Slidable.hpp"
/*============================================================================*/
using namespace Sh;

/*============================================================================*/

Slidable::Slidable(UIWindow *target, const Frame &slide_frame)
    : Draggable(target), frame(slide_frame), parent_offset({}) {

    if (target->getParent()) {
        parent_offset = target->getParent()->getPos();
        frame.pos += parent_offset;
    }
}

void Slidable::onTargetUpdate() {
    auto parent = target<UIWindow>()->getParent();
    if (parent) {
        frame.pos -= parent_offset;
        parent_offset = parent->getPos();
        frame.pos += parent_offset;
    }
}

bool Slidable::onMouseButton(MouseButtonEvent &event) {

    if (target<UIWindow>()->contains(event.where()) ||
        event.state() == Mouse::UP) {
        return
            Draggable::onMouseButton(event);
    }

    if (frame.
        contains(event
                     .

                         where()

    )) {
                                    // MESS!
        slide(
            event
                .

                    where()

            -
            0.5 * target<UIWindow>()->getSize() -
            target<UIWindow>()->getPos()
        );

        return true;
    }

    return false;
}

bool Slidable::onMouseMove(MouseEvent &event) {

    Holdable::onMouseMove(event);

    if (

        isHeld()

        ) {
        slide(event
                  .

                      where()

              -

              dragPoint()

        );
    }

    return true;
}

void Slidable::onDrag(const Vector2<double> &) {
    onSlide(get());
}

Vector2<double> Slidable::get() const {

    Vector2<double> pos = target<UIWindow>()->getPos();
    Vector2<double> size = target<UIWindow>()->getSize();

    return Vector2<double>{
        (pos.x - frame.pos.x) / (frame.size.x - size.x),
        (pos.y - frame.pos.y) / (frame.size.y - size.y)
    };
}

void Slidable::set(Vector2<double> pos) {

    if (pos.x < 0) {
        pos.x = 0;
    } else if (pos.x > 1) {
        pos.x = 1;
    }

    if (pos.y < 0) {
        pos.y = 0;
    } else if (pos.y > 1) {
        pos.y = 1;
    }

    Vector2<double> size = target<UIWindow>()->getSize();

    slide(
        frame.pos + Vector2<double>{(frame.size.x - size.x) * pos.x,
                                    (frame.size.y - size.y) * pos.y} -
        target<UIWindow>()->getPos()
    );

    n_held = 0;
}

void Slidable::slide(const Vector2<double> &delta) {

    if (!isHeld()) {
        ++n_held;
        drag_point = target<UIWindow>()->getPos() + 0.5 * target<UIWindow>()->getSize();
    }

    Vector2<double> new_pos = target<UIWindow>()->getPos() + delta;
    Vector2<double> size = target<UIWindow>()->getSize();

    new_pos.x = std::max(
        frame.pos.x,
        std::min(frame.pos.x + frame.size.x - size.x, new_pos.x)
    );
    new_pos.y = std::max(
        frame.pos.y,
        std::min(frame.pos.y + frame.size.y - size.y, new_pos.y)
    );

    Draggable::drag(new_pos - target<UIWindow>()->getPos());
}

/*============================================================================*/