/*============================================================================*/
#ifndef SHISHGL_UI_SCROLLBAR_HPP
#define SHISHGL_UI_SCROLLBAR_HPP
/*============================================================================*/
#include "Clickable.hpp"
#include "Slidable.hpp"
/*============================================================================*/
namespace Sh {

    class UIScrollbar : public UIWindow {
    public:

        static constexpr double MIN_SLIDER_SIZE     = 0.15,
                                DEFAULT_SLIDER_SIZE = MIN_SLIDER_SIZE,
                                DEFAULT_SLIDER_POS  = 0;

        enum Type {
            VERTICAL,
            HORIZONTAL
        };

        explicit UIScrollbar(const Frame& frame, UIScrollbar::Type type,
                             double slider_size = DEFAULT_SLIDER_SIZE,
                             double slider_pos  = DEFAULT_SLIDER_POS);

        UIWindow* inc_button;
        UIWindow* dec_button;
        UIWindow* slider;

    };

    void applyDefaultStyle(UIScrollbar* scrollbar);

    /*------------------------------------------------------------------------*/

    class ScrollbarBackground : public Clickable {
    public:

        explicit ScrollbarBackground(UIWindow* target);

        void reactOnPress(MouseButtonEvent& event) override;

        bool onMouseScroll(MouseScrollEvent&) override { return false; }

    };

    /*------------------------------------------------------------------------*/

    class ScrollbarButton : public Holdable {
    protected:

        Mouse::ScrollDelta m_delta;
        Mouse::ScrollType m_type;

    public:

        ScrollbarButton(UIWindow* target, Mouse::ScrollDelta delta,
                        Mouse::ScrollType type)
               : Holdable(target)
               , m_delta(delta)
               , m_type(type)
               { }

    protected:

        void reactOnHold(TimerEvent&) override {
            printf("HOLD!\n");
            EventSystem::sendEvent<MouseScrollEvent>(
                    this, target<UIWindow>()->getPos(), m_delta, m_type
                    );
        }

    };

    /*------------------------------------------------------------------------*/

    class ScrollbarSlider : public Slidable {
    public:

        explicit ScrollbarSlider(UIWindow* targer, const Segment2<double>& slide);

        bool onMouseScroll(MouseScrollEvent& event) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_SCROLLBAR_HPP
/*============================================================================*/
