/*============================================================================*/
#include "UIWindow.hpp"
#include "ColorFill.hpp"
#include "UIFrame.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

UIFrame::UIFrame(const Frame& frame, double scrollbar_width)
        : UIWindow(frame)
        , v_scrollbar(nullptr)
        , h_scrollbar(nullptr)
        , sb_width(scrollbar_width)
        , rel_pos({})
        , max_rel_pos({}) {
    setBehavior<FrameBehavior>();
}


void UIFrame::fit() {


    Vector2<double> max_pos = getPos() - rel_pos;
    Vector2<double> min_pos = max_pos + max_rel_pos;

    for (auto &child : getChildren()) {
        min_pos.x = std::min(min_pos.x, child->getPos().x);
        min_pos.y = std::min(min_pos.y, child->getPos().y);
        max_pos.x = std::max(max_pos.x, child->getPos().x + child->getSize().x - getSize().x);
        max_pos.y = std::max(max_pos.y, child->getPos().y + child->getSize().y - getSize().y);
    }

    rel_pos = getPos() - min_pos;
    max_rel_pos = max_pos - min_pos;

    if (min_pos.x < max_pos.x) {

        WindowManager::destroy(detach(h_scrollbar));

        h_scrollbar = attach<UIHorizontalScrollbar<FrameScroller>>(
            Frame{{0,                      getSize().y - sb_width},
                  {getSize().x - sb_width, sb_width}},
            getSize().x / (max_rel_pos.x + getSize().x), this
        );
        h_scrollbar->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color{40, 40, 40, 100}}
        );
        h_scrollbar->left_button->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color{40, 40, 40, 140}}
        );
        h_scrollbar->right_button->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color{40, 40, 40, 140}}
        );
        h_scrollbar->slider->slider->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color::BLANCHED_ALMOND}
        );

        SubscriptionManager::subscribe<MouseScrollEvent>(
            h_scrollbar->slider->slider->as<FrameScroller>(), this
        );

        h_scrollbar->slider->slider->as<FrameScroller>()->set(
            {rel_pos.x / max_rel_pos.x, 0}
            );

    } else {
        WindowManager::destroy(detach(h_scrollbar));
        h_scrollbar = nullptr;
    }

    if (min_pos.y < max_pos.y) {

        WindowManager::destroy(detach(v_scrollbar));

        v_scrollbar = attach < UIVerticalScrollbar < FrameScroller >> (
            Frame{{getSize().x - sb_width, 0},
                  {sb_width,               getSize().y}},
            (getSize().y) / (max_rel_pos.y + getSize().y), this
        );
        v_scrollbar->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color{40, 40, 40, 100}}
        );
        v_scrollbar->up_button->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color{40, 40, 40, 140}}
        );
        v_scrollbar->down_button->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color{40, 40, 40, 140}}
        );
        v_scrollbar->slider->slider->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color::BLANCHED_ALMOND}
        );

        SubscriptionManager::subscribe<MouseScrollEvent>(
            v_scrollbar->slider->slider->as<FrameScroller>(), this
        );

        v_scrollbar->slider->slider->as<FrameScroller>()->set(
            {0, rel_pos.y / max_rel_pos.y}
        );
    } else {
        WindowManager::destroy(detach(v_scrollbar));
        v_scrollbar = nullptr;
    }
}


/*============================================================================*/
