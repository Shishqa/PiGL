/*============================================================================*/
#include "UIWindow.hpp"
#include "ColorFill.hpp"
#include "UIFrame.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

UIFrame::UIFrame(const Frame& frame)
        : UIWindow(frame)
        , v_scrollbar(nullptr)
        , h_scrollbar(nullptr)
        , content_frame({{0, 0}, {100, 100}}) { // random numbers


}

void UIFrame::fit() {

    Vector2<double> lu_corner = PLATFORM().getDisplaySize();
    Vector2<double> rd_corner = {0, 0};

    for (auto& child : getChildren()) {

        lu_corner.x = std::min(lu_corner.x, child->getPos().x);
        lu_corner.y = std::min(lu_corner.y, child->getPos().y);

        rd_corner.x = std::max(rd_corner.x, child->getPos().x + child->getFrame().size.x);
        rd_corner.y = std::max(rd_corner.y, child->getPos().y + child->getFrame().size.y);

    }

    rd_corner -= getFrame().size;

    if (getPos().x < lu_corner.x) { // Copy-paste!!!

        Vector2<double> delta{getPos().x - lu_corner.x, 0};

        translateChildren(delta);
        lu_corner += delta;
        rd_corner += delta;
    }
    if (getPos().y < lu_corner.y) {

        Vector2<double> delta{getPos().y - lu_corner.y, 0};

        translateChildren(delta);
        lu_corner += delta;
        rd_corner += delta;
    }

    if (rd_corner.y > lu_corner.y) {

        v_scrollbar = attach<UIScrollbar>(
                Frame{
                        {getFrame().size.x - SCROLLBAR_WIDTH, 0},
                        {SCROLLBAR_WIDTH, getFrame().size.y}
                },
                UIScrollbar::VERTICAL,
                getFrame().size.y / (rd_corner.y + getFrame().size.y - lu_corner.y),
                (getPos().y - lu_corner.y) / (rd_corner.y - lu_corner.y)
                );

        applyDefaultStyle(v_scrollbar);

        addBehavior<FrameSlidable>(v_scrollbar);
        addBehavior<FrameScrollable>(v_scrollbar);
    } else {
        WindowManager::destroy(v_scrollbar);
    }

    if (rd_corner.x > lu_corner.x) {

        h_scrollbar = attach<UIScrollbar>(
                Frame{
                        {0, getFrame().size.y - SCROLLBAR_WIDTH},
                        {getFrame().size.x - SCROLLBAR_WIDTH, SCROLLBAR_WIDTH}
                },
                UIScrollbar::HORIZONTAL,
                getFrame().size.x / (rd_corner.x + getFrame().size.x- lu_corner.x),
                (getPos().x - lu_corner.x) / (rd_corner.x - lu_corner.x)
        );

        applyDefaultStyle(h_scrollbar);

        addBehavior<FrameSlidable>(h_scrollbar);
        addBehavior<FrameScrollable>(h_scrollbar);
    } else {
        WindowManager::destroy(h_scrollbar);
    }
}

void UIFrame::translateChildren(const Vector2<double>& delta) {

    for (auto& child : getChildren()) {

        if (child == v_scrollbar ||
            child == h_scrollbar) {
            continue;
        }

        child->translate(delta);
    }
}

/*----------------------------------------------------------------------------*/

FrameScrollable::FrameScrollable(UIWindow* target, UIScrollbar* scrollbar)
        : DefaultBehavior(target) {
    SubscriptionManager::subscribe(this, EventSystem::SystemEvents, MOUSE_SCROLL);
//    SubscriptionManager::subscribe(scrollbar->slider->as<ScrollbarSlider>(),
//                                   this, MOUSE_SCROLL);
}

bool FrameScrollable::onMouseScroll(MouseScrollEvent& event) {
    EventSystem::sendEvent(this, event);
    return true;
}

/*----------------------------------------------------------------------------*/

FrameSlidable::FrameSlidable(UIWindow* target, UIScrollbar* scrollbar)
        : SlideListener(target) {
//    SubscriptionManager::subscribe(this, scrollbar->slider->as<ScrollbarSlider>(),
//                                   SLIDE);
}

bool FrameSlidable::onSlide(SlideEvent& event) {

    Vector2<double> delta = {
            event.delta().x * (target<UIFrame>()->h_scrollbar->slider->getFrame().size.x / target<UIWindow>()->getFrame().size.x),
            event.delta().y * (target<UIFrame>()->v_scrollbar->slider->getFrame().size.y / target<UIWindow>()->getFrame().size.y),
    };

    target<UIFrame>()->translateChildren(-delta);

    return true;
}

/*============================================================================*/
