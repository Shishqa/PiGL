/*============================================================================*/
#include "UIWindow.hpp"
#include "ColorFill.hpp"
#include "UIFrame.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

UIFrame::UIFrame(const Frame& frame, const Frame& contents_frame)
        : UIWindow(frame)
        , v_scrollbar(nullptr)
        , h_scrollbar(nullptr)
        , content_frame(contents_frame) {

    if (content_frame.size.y > frame.size.y) {

        v_scrollbar = attach<UIScrollbar>(Frame{ {frame.size.x - 30, 0}, {30, frame.size.y} },
                            UIScrollbar::VERTICAL, frame.size.y / content_frame.size.y);
        applyDefaultStyle(v_scrollbar);

    }

    if (content_frame.size.x > frame.size.x) {

        h_scrollbar = attach<UIScrollbar>(Frame{ {0, frame.size.y - 30}, {frame.size.x - 30, 30} },
                                          UIScrollbar::HORIZONTAL, frame.size.x / content_frame.size.x);
        applyDefaultStyle(h_scrollbar);

    }

    addBehavior<FrameSlidable>();
    addBehavior<FrameScrollable>();

}

/*----------------------------------------------------------------------------*/

FrameScrollable::FrameScrollable(UIWindow* target)
        : DefaultBehavior(target) {
    SubscriptionManager::subscribe(this, EventSystem::SystemEvents, MOUSE_SCROLL);
    SubscriptionManager::subscribe(Behavior::target<UIFrame>()->v_scrollbar->slider->as<ScrollbarSlider>(),
                                   this, MOUSE_SCROLL);
    SubscriptionManager::subscribe(Behavior::target<UIFrame>()->h_scrollbar->slider->as<ScrollbarSlider>(),
                                   this, MOUSE_SCROLL);
}

bool FrameScrollable::onMouseScroll(MouseScrollEvent& event) {
    EventSystem::sendEvent(this, event);
    return true;
}

/*----------------------------------------------------------------------------*/

FrameSlidable::FrameSlidable(UIWindow* target)
        : SlideListener(target) {
    SubscriptionManager::subscribe(this, Behavior::target<UIFrame>()->v_scrollbar->slider->as<ScrollbarSlider>(),
                                   SLIDE);
    SubscriptionManager::subscribe(this, Behavior::target<UIFrame>()->h_scrollbar->slider->as<ScrollbarSlider>(),
                                   SLIDE);
}

bool FrameSlidable::onSlide(SlideEvent& event) {

    for (auto& child : target<UIWindow>()->getChildren()) {

        if (child == target<UIFrame>()->v_scrollbar ||
            child == target<UIFrame>()->h_scrollbar) {
            continue;
        }

        child->translate(-event.delta());

    }

    return true;
}

/*============================================================================*/
