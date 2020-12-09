/*============================================================================*/
#ifndef SHISHGL_UI_SCROLLBAR_HPP
#define SHISHGL_UI_SCROLLBAR_HPP
/*============================================================================*/
#include "Clickable.hpp"
#include "Slidable.hpp"
#include "UISlider.hpp"
#include "UIButton.hpp"
/*============================================================================*/
namespace Sh {

    class ScrollSlidable : public Slidable {
    public:

        explicit ScrollSlidable(UIWindow* target, const Frame& frame)
                : Slidable(target, frame)
                { }

        bool onMouseScroll(MouseScrollEvent& event) override {

            static constexpr double SCROLL_BOOST = 10;

            if (event.type() == Mouse::VERTICAL) {
                slide(Vector2<double>{0, SCROLL_BOOST * event.delta()});
                Holdable::n_held = 0;
            } else {
                slide(Vector2<double>{SCROLL_BOOST * event.delta(), 0});
                Holdable::n_held = 0;
            }

            return true;
        }
    };

    class ClickToScroll : public Holdable {
    public:

        explicit ClickToScroll(UIWindow* target,
                               Mouse::ScrollType scroll_type,
                               double scroll_delta)
                : Holdable(target)
                , type(scroll_type)
                , delta(scroll_delta)
                { }

        void reactOnHold(TimerEvent&) override {
            EventSystem::sendEvent<MouseScrollEvent>(target<Window>(),
                target<Window>()->getPos(), delta, type);
        }

    private:

        Mouse::ScrollType type;
        double delta;
    };


    template <typename Behavior>
    class UIVerticalScrollbar : public UIWindow {
    public:

        template <typename... Args>
        explicit UIVerticalScrollbar(const Frame& frame,
                                     double slider_size_ratio,
                                     Args&&... args)
                : UIWindow(frame) {

            if (slider_size_ratio < 0.2) {
                slider_size_ratio = 0.2;
            } else if (slider_size_ratio > 1.0) {
                slider_size_ratio = 1.0;
            }

            Vector2<double> button_size = {frame.size.x, frame.size.x};

            up_button = attach<UIButton<ClickToScroll>>(
                Frame{ {0, 0}, button_size },
                Mouse::VERTICAL, -1.0
                );

            down_button = attach<UIButton<ClickToScroll>>(
                Frame{ {0, frame.size.y - button_size.y}, button_size },
                Mouse::VERTICAL, 1.0
                );

            double slide_len = frame.size.y - 2 * button_size.y;

            slider = attach<UIVerticalSlider<Behavior>>(
                Frame{ {0, button_size.y}, {frame.size.x, slide_len} },
                slide_len * slider_size_ratio, std::forward<Args>(args)...
                );

            SubscriptionManager::subscribe<MouseScrollEvent>(
                slider->slider->template as<Behavior>(), up_button);
            SubscriptionManager::subscribe<MouseScrollEvent>(
                slider->slider->template as<Behavior>(), down_button);
        }

        UIWindow* up_button;
        UIWindow* down_button;
        UIVerticalSlider<Behavior>* slider;
    };

    template <typename Behavior>
    class UIHorizontalScrollbar : public UIWindow {
    public:

        template <typename... Args>
        explicit UIHorizontalScrollbar(const Frame& frame,
                                       double slider_size_ratio,
                                       Args&&... args)
                : UIWindow(frame) {

            Vector2<double> button_size = {frame.size.y, frame.size.y};

            left_button = attach<UIButton<ClickToScroll>>(
                Frame{ {0, 0}, button_size },
                Mouse::HORIZONTAL, -1.0
            );

            right_button = attach<UIButton<ClickToScroll>>(
                Frame{ {frame.size.x - button_size.x, 0}, button_size },
                Mouse::HORIZONTAL, 1.0
            );

            double slide_len = frame.size.x - 2 * button_size.x;

            slider = attach<UIHorizontalSlider<Behavior>>(
                Frame{ {button_size.x, 0}, {slide_len, frame.size.y} },
                slide_len * slider_size_ratio, std::forward<Args>(args)...
            );

            SubscriptionManager::subscribe<MouseScrollEvent>(
                slider->slider->template as<Behavior>(), left_button);
            SubscriptionManager::subscribe<MouseScrollEvent>(
                slider->slider->template as<Behavior>(), right_button);
        }

        UIWindow* left_button;
        UIWindow* right_button;
        UIHorizontalSlider<Behavior>* slider;
    };

}
/*============================================================================*/
#endif //SHISHGL_UI_SCROLLBAR_HPP
/*============================================================================*/
