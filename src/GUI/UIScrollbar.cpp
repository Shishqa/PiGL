/*============================================================================*/
#include "LogSystem.hpp"
#include "EventManager.hpp"
#include "UIScrollbar.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

Scrollbar::Scrollbar(UIWindow* target, double slider_size, double slider_pos,
                     Scrollbar::Type type)
        : Clickable(target)
        , inc_button(nullptr)
        , dec_button(nullptr)
        , slider(nullptr)
        , inc_bt_win(nullptr)
        , dec_bt_win(nullptr)
        , slider_win(nullptr)
        , s_type(type) {

    if (slider_size > 1.0) {
        slider_size = 0.99;
    } else if (slider_size < MIN_SLIDER_RATIO) {
        slider_size = MIN_SLIDER_RATIO;
    }

    if (slider_pos > 1.0) {
        slider_pos = 0.99;
    } else if (slider_pos < 0.0) {
        slider_pos = 0.01;
    }

    switch (type) {
        case VERTICAL:
            constructVertical(target, slider_size, slider_pos);
            break;

        case HORIZONTAL:
            constructHorizontal(target, slider_size, slider_pos);
            break;

        default:
            LogSystem::printError("Constructing scrollbar with unknown type");
    }

    SubscriptionManager::subscribe(this, slider, MOUSE_BUTTON | MOUSE_MOVE);
}

/*----------------------------------------------------------------------------*/

void Scrollbar::constructVertical(UIWindow* target, double slider_size_ratio,
                                  double slider_pos) {

    Vector2<double> size = target->getFrame().size;
    Vector2<double> button_size = {size.x, size.x};

    Vector2<double> slider_size =
            {size.x, (size.y - 2 * button_size.y) * slider_size_ratio};

    Segment2<double> slider_guide = {};
    slider_guide.begin = {0, button_size.y};
    slider_guide.end   = {0, size.y - button_size.y - slider_size.y};

    inc_bt_win = target->attach<UIWindow>(
            Viewport{ {0, 0}, button_size }
    );
    inc_button = inc_bt_win->addBehavior<Scrollbar::Button>(
            1.0, Mouse::VERTICAL
    );

    dec_bt_win = target->attach<UIWindow>(
            Viewport{ {0, size.y - button_size.y}, button_size }
    );
    dec_button = dec_bt_win->addBehavior<Scrollbar::Button>(
            -1.0, Mouse::VERTICAL
    );

    slider_win = target->attach<UIWindow>(
            Viewport{ slider_guide.begin + slider_pos * slider_guide.guide(), slider_size }
    );
    slider = slider_win->addBehavior<Slidable>(
            slider_guide
    );
}

/*----------------------------------------------------------------------------*/

void Scrollbar::constructHorizontal(UIWindow* target, double slider_size_ratio,
                                    double slider_pos) {
    Vector2<double> size = target->getFrame().size;
    Vector2<double> button_size = {size.y, size.y};

    Vector2<double> slider_size =
            {(size.x - 2 * button_size.x) * slider_size_ratio, size.y};

    Segment2<double> slider_guide = {};
    slider_guide.begin = {button_size.x, 0};
    slider_guide.end   = {size.x - button_size.x - slider_size.x, 0};

    inc_bt_win = target->attach<UIWindow>(
            Viewport{ {0, 0}, button_size }
    );
    inc_button = inc_bt_win->addBehavior<Scrollbar::Button>(
            1.0, Mouse::HORIZONTAL
            );

    dec_bt_win = target->attach<UIWindow>(
            Viewport{ {size.x - button_size.x, 0}, button_size }
    );
    dec_button = dec_bt_win->addBehavior<Scrollbar::Button>(
            -1.0, Mouse::HORIZONTAL
            );

    slider_win = target->attach<UIWindow>(
            Viewport{ slider_guide.begin + slider_pos * slider_guide.guide(), slider_size }
    );
    slider = slider_win->addBehavior<Slidable>(
            slider_guide
    );
}

/*----------------------------------------------------------------------------*/

void Scrollbar::reactOnPress(MouseButtonEvent& event) {

    if (slider_win->contains(event.where()) ||
        inc_bt_win->contains(event.where()) ||
        dec_bt_win->contains(event.where())) {
        return;
    }

    printf("PRESSED!\n");

    if (event.state() == Mouse::DOWN) {
        EventSystem::sendEvent<MouseButtonEvent>(this,
                slider_win->getPos() + 0.5 * slider_win->getFrame().size,
                Mouse::LEFT, Mouse::DOWN
                );
        EventSystem::sendEvent<MouseEvent>(this, event.where());
    }
}

bool Scrollbar::onMouseScroll(MouseScrollEvent&) {



    return true;

}

/*----------------------------------------------------------------------------*/

/*
ScrollSlider::ScrollSlider(Object::ID id, Object::ID parent, const ButtonColorScheme &colors,
                           const Vector2<double>& guide,
                           const Vector2<double>& size,
                           const Vector2<double>& pos)
        : RectSlider(id, parent, colors, guide, size, pos) {}


bool ScrollSlider::onMouseMove(const MouseEvent* event) {

    auto old_pos = where_dragged;

    if (!RectSlider::onMouseMove(event)) {
        return false;
    }

    auto new_pos = where_dragged;

    EventSystem::sendEvent<SlideEvent>(
            parent,
            Event::SLIDE,
            (new_pos - old_pos) ^ (!guide)
    );

    return true;
}
ScrollButton::ScrollButton(Object::ID id, Object::ID parent,
                           Mouse::ScrollDelta delta,
                           const ButtonColorScheme& colors,
                           const Vector2<double>& size,
                           const Vector2<double>& pos)
        : RectHoldableButton(id, parent, colors, size, pos)
        , delta(delta) {}


void ScrollButton::reactOnHold(TimerEvent&) {
    EventSystem::sendEvent<MouseScrollEvent>(
            id(),
            getAbsPos(),
            delta
    );
}
*/

/*============================================================================*/
