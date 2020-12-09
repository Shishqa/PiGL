/*============================================================================*/
#ifndef SHISHGL_UI_FRAME_HPP
#define SHISHGL_UI_FRAME_HPP
/*============================================================================*/
#include <cmath>

#include "UIWindow.hpp"
#include "UIScrollbar.hpp"
#include "DefaultBehavior.hpp"
/*============================================================================*/
namespace Sh {

    class FrameScroller;

    class UIFrame : public UIWindow {
    public:

        static constexpr double DEFAULT_SCROLLBAR_WIDTH = 20;

        explicit UIFrame(const Frame& frame, double scrollbar_width =
                         DEFAULT_SCROLLBAR_WIDTH);

        void fit();

        void setView(const Vector2<double>& pos) {

            Vector2<double> new_rel_pos {
                (!std::isnan(pos.x) ? max_rel_pos.x * std::min(pos.x, 1.0) : rel_pos.x),
                (!std::isnan(pos.y) ? max_rel_pos.y * std::min(pos.y, 1.0) : rel_pos.y)
            };

            for (auto& child : getChildren()) {
                if (child == v_scrollbar ||
                    child == h_scrollbar) {
                    continue;
                }
                child->translate(rel_pos - new_rel_pos);
            }

            rel_pos = new_rel_pos;
        }

        UIVerticalScrollbar<FrameScroller>*   v_scrollbar;
        UIHorizontalScrollbar<FrameScroller>* h_scrollbar;

    private:

        double sb_width;

        Vector2<double> rel_pos;
        Vector2<double> max_rel_pos;

    };

    /*------------------------------------------------------------------------*/

    class FrameScroller : public ScrollSlidable {
    public:

        FrameScroller(UIWindow* target, const Frame& frame, UIFrame* target_fr)
                : ScrollSlidable(target, frame)
                , target_frame(target_fr)
                { }

        void onSlide(const Vector2<double>& pos) override {
            target_frame->setView(pos);
        }

    private:

        UIFrame* target_frame;
    };

    class FrameBehavior : public DefaultBehavior {
    public:

        explicit FrameBehavior(UIWindow* target)
                : DefaultBehavior(target) {
            SubscriptionManager::subscribe<MouseScrollEvent>(this, EventSystem::SystemEvents);
        }

        bool onMouseScroll(MouseScrollEvent& event) override {
            return EventSystem::sendEvent(target<Window>(), event);
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_FRAME_HPP
/*============================================================================*/
