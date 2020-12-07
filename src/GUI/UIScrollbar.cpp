/*============================================================================*/
#include "LogSystem.hpp"
#include "EventManager.hpp"
#include "UIScrollbar.hpp"
#include "ColorFill.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

UIScrollbar::UIScrollbar(const Frame& frame, UIScrollbar::Type type,
                         double slider_size_ratio, double slider_pos_ratio)
        : UIWindow(frame)
        , inc_button(nullptr)
        , dec_button(nullptr)
        , slider(nullptr) {

    if (slider_size_ratio >= 1.0) {
        slider_size_ratio = 0.99;
    } else if (slider_size_ratio < MIN_SLIDER_SIZE) {
        slider_size_ratio = MIN_SLIDER_SIZE;
    }

    if (slider_pos_ratio >= 1.0) {
        slider_pos_ratio = 0.99;
    } else if (slider_pos_ratio < 0.0) {
        slider_pos_ratio = 0.0;
    }

    ScrollbarButton* inc = nullptr;
    ScrollbarButton* dec = nullptr;
    ScrollbarSlider* sli = nullptr;

    if (VERTICAL == type) {

        Vector2<double> button_size{
            frame.size.x,
            frame.size.x
        };

        inc_button = attach<UIWindow>(Frame{ {0, 0}, button_size });
        dec_button = attach<UIWindow>(Frame{ {0, frame.size.y - button_size.y}, button_size });

        inc = inc_button->addBehavior<ScrollbarButton>(-1.0, Mouse::VERTICAL);
        dec = dec_button->addBehavior<ScrollbarButton>( 1.0, Mouse::VERTICAL);

        Vector2<double> slider_size{
                frame.size.x,
                (frame.size.y - 2 * button_size.y) * slider_size_ratio
        };

        Segment2<double> slider_guide = {};
        slider_guide.begin = {0, button_size.y};
        slider_guide.end   = {0, frame.size.y - button_size.y - slider_size.y};

        slider = attach<UIWindow>(Frame{
            slider_guide.begin + slider_pos_ratio * slider_guide.guide(),
            slider_size
        });
        sli = slider->addBehavior<ScrollbarSlider>(slider_guide);

    } else {

        Vector2<double> button_size{
                frame.size.y,
                frame.size.y
        };

        inc_button = attach<UIWindow>(Frame{ {0, 0}, button_size });
        dec_button = attach<UIWindow>(Frame{ {frame.size.x - button_size.x, 0}, button_size });

        inc = inc_button->addBehavior<ScrollbarButton>(-1.0, Mouse::HORIZONTAL);
        dec = dec_button->addBehavior<ScrollbarButton>( 1.0, Mouse::HORIZONTAL);

        Vector2<double> slider_size{
                (frame.size.x - 2 * button_size.x) * slider_size_ratio,
                frame.size.y,
        };

        Segment2<double> slider_guide = {};
        slider_guide.begin = {button_size.x, 0};
        slider_guide.end   = {frame.size.x - button_size.x - slider_size.x, 0};

        slider = attach<UIWindow>(Frame{
                slider_guide.begin + slider_pos_ratio * slider_guide.guide(),
                slider_size
        });
        sli = slider->addBehavior<ScrollbarSlider>(slider_guide);
    }

//    auto bg = addBehavior<ScrollbarBackground>();

    SubscriptionManager::subscribe(sli, inc, MOUSE_SCROLL);
    SubscriptionManager::subscribe(sli, dec, MOUSE_SCROLL);
//    SubscriptionManager::subscribe(bg, slider);
}

/*----------------------------------------------------------------------------*/

ScrollbarBackground::ScrollbarBackground(UIWindow* target)
    : Clickable(target) {
//    SubscriptionManager::subscribe(Behavior::target<UIScrollbar>()->slider->as<ScrollbarSlider>(),
//                                   this, MOUSE_MOVE | MOUSE_BUTTON);
}

/*----------------------------------------------------------------------------*/

void ScrollbarBackground::reactOnPress(MouseButtonEvent& event) {

    UIWindow* slider = target<UIScrollbar>()->slider;

    if (slider->contains(event.where()) ||
        target<UIScrollbar>()->inc_button->contains(event.where()) ||
        target<UIScrollbar>()->dec_button->contains(event.where())) {
        return;
    }

    if (event.state() == Mouse::DOWN) {
        EventSystem::sendEvent<MouseButtonEvent>(this,
                slider->getPos() + 0.5 * slider->getFrame().size,
                Mouse::LEFT, Mouse::DOWN
                );
        EventSystem::sendEvent<MouseEvent>(this, event.where());
    }
}

/*============================================================================*/

void Sh::applyDefaultStyle(UIScrollbar* scrollbar) {

    /* TODO: smth normal */

    scrollbar->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color::FOREST_GREEN}
    );
    scrollbar->inc_button->applyStyle<UIWindow::NORMAL>(
                    ColorFill{Color::FIRE_BRICK}
            )
            ->applyStyle<UIWindow::HOVER>(
                    ColorFill{Color::SKY_BLUE}
            )
            ->applyStyle<UIWindow::CLICK>(
                    ColorFill{Color::LIGHT_BLUE}
            );
    scrollbar->dec_button->applyStyle<UIWindow::NORMAL>(
                    ColorFill{Color::FIRE_BRICK}
            )
            ->applyStyle<UIWindow::HOVER>(
                    ColorFill{Color::SKY_BLUE}
            )
            ->applyStyle<UIWindow::CLICK>(
                    ColorFill{Color::LIGHT_BLUE}
            );

    scrollbar->slider->applyStyle<UIWindow::NORMAL>(
                    ColorFill{Color::BLUE}
            )
            ->applyStyle<UIWindow::CLICK>(
                    ColorFill{Color::RED}
            );
}

/*============================================================================*/

ScrollbarSlider::ScrollbarSlider(UIWindow* target, const Segment2<double>& segment)
    : Slidable(target, segment, true)
    { }

bool ScrollbarSlider::onMouseScroll(MouseScrollEvent& event) {

    Vector2<double> delta = {};

    if (event.type() == Mouse::VERTICAL) {
        delta = {0, event.delta()};
    } else {
        delta = {event.delta(), 0};
    }

    Slidable::slide(delta, Mouse::LEFT);

    return true;
}

/*============================================================================*/
