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

        explicit UIFrame(const Frame& frame);

        void setView(const Vector2<double>& pos) {

            Vector2<double> new_rel_pos {
                (!std::isnan(pos.x) ? max_rel_pos.x * pos.x : rel_pos.x),
                (!std::isnan(pos.y) ? max_rel_pos.y * pos.y : rel_pos.y)
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

        void fit() {

            static constexpr double SB_WIDTH = 30;

            Vector2<double> min_pos = getPos() - rel_pos;
            Vector2<double> max_pos = min_pos + max_rel_pos;

            for (auto& child : getChildren()) {
                min_pos.x = std::min(min_pos.x, child->getPos().x);
                min_pos.y = std::min(min_pos.y, child->getPos().y);
                max_pos.x = std::max(max_pos.x, child->getPos().x + child->getSize().x - getSize().x);
                max_pos.y = std::max(max_pos.y, child->getPos().y + child->getSize().y - getSize().y);
            }

            if (min_pos.x < max_pos.x) {

                WindowManager::destroy(detach(h_scrollbar));

                h_scrollbar = attach<UIHorizontalScrollbar<FrameScroller>>(
                    Frame{ {0, getSize().y - SB_WIDTH}, {getSize().x - SB_WIDTH, SB_WIDTH} },
                        getSize().x / (max_pos.x - min_pos.x + getSize().x), this
                        );
                h_scrollbar->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color{40, 40, 40, 100} }
                    );
                h_scrollbar->left_button->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color{40, 40, 40, 140} }
                );
                h_scrollbar->right_button->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color{40, 40, 40, 140} }
                );
                h_scrollbar->slider->slider->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color::BLANCHED_ALMOND }
                    );

                SubscriptionManager::subscribe(h_scrollbar->slider->slider->getBehavior(),
                                               this, MOUSE_SCROLL);
            }
            if (min_pos.y < max_pos.y) {

                WindowManager::destroy(detach(v_scrollbar));

                v_scrollbar = attach<UIVerticalScrollbar<FrameScroller>>(
                    Frame{ {getSize().x - SB_WIDTH, 0}, {SB_WIDTH, getSize().y} },
                    getSize().y / (max_pos.y - min_pos.y + getSize().y), this
                );
                v_scrollbar->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color{40, 40, 40, 100} }
                );
                v_scrollbar->up_button->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color{40, 40, 40, 140} }
                    );
                v_scrollbar->down_button->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color{40, 40, 40, 140} }
                );
                v_scrollbar->slider->slider->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color::BLANCHED_ALMOND }
                );

                SubscriptionManager::subscribe(v_scrollbar->slider->slider->getBehavior(),
                                               this, MOUSE_SCROLL);
            }

            rel_pos = getPos() - min_pos;
            max_rel_pos = max_pos - min_pos;
        }

        UIVerticalScrollbar<FrameScroller>*   v_scrollbar;
        UIHorizontalScrollbar<FrameScroller>* h_scrollbar;

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
            SubscriptionManager::subscribe(this, EventSystem::SystemEvents,
                                           MOUSE_SCROLL);
        }

        bool onMouseScroll(MouseScrollEvent& event) override {
            return EventSystem::sendEvent(target<Window>(), event);
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_FRAME_HPP
/*============================================================================*/
