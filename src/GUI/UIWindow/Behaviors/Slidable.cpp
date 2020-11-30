/*============================================================================*/
#include "Slidable.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Slidable::Slidable(UIWindow* target, const Segment2<double>& slide, bool send_event)
        : Draggable(target)
        , need_reaction(send_event)
        , slide_seg(slide)
        { }

/*----------------------------------------------------------------------------*/

bool Slidable::onMouseMove(ShishGL::MouseEvent &event) {

    if (!Draggable::isHeld()) {
        return Draggable::onMouseMove(event);
    }

    slide(event.where() - Draggable::dragPoint(), Mouse::LEFT);

    return true;
}

/*----------------------------------------------------------------------------*/

void Slidable::slide(const Vector2<double>& delta, Mouse::Button button) {

    bool emulation = false;

    Vector2<double> old_pos = target<UIWindow>()->getPos();

    if (!Draggable::isHeld()) {
        MouseButtonEvent click{old_pos, button, Mouse::DOWN};
        onMouseButton(click);
        emulation = true;
    }

    Segment2<double> seg = slide_seg;

    auto parent = target<UIWindow>()->getParent();

    if (parent) {
        seg.begin += parent->getPos();
        seg.end   += parent->getPos();
    }

    Vector2<double> guide = seg.guide();
    Vector2<double> delta_proj = delta | guide;

    Vector2<double> new_pos = target<UIWindow>()->getPos() + delta_proj;

    if (((new_pos - seg.begin) ^ guide) < 0) {

        new_pos = seg.begin;

    } else if (((new_pos - seg.end) ^ guide) > 0) {

        new_pos = seg.end;

    }

    MouseEvent move{new_pos - old_pos + Draggable::dragPoint()};
    Draggable::onMouseMove(move);

    if (need_reaction) {
        EventSystem::sendEvent<SlideEvent>(this, new_pos - old_pos);
    }

    if (emulation) {
        MouseButtonEvent click{new_pos, button, Mouse::UP};
        onMouseButton(click);
    }
}

/*============================================================================*/