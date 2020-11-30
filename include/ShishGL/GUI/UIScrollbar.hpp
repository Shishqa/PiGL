/*============================================================================*/
#ifndef SHISHGL_UI_SCROLLBAR_HPP
#define SHISHGL_UI_SCROLLBAR_HPP
/*============================================================================*/
#include "Clickable.hpp"
#include "Slidable.hpp"
/*============================================================================*/
namespace Sh {

    class Scrollbar : public Clickable {
    protected:

        class Button;

        static constexpr double DEFAULT_PROPORTION = 0.2;
        static constexpr double DEFAULT_STEP_SIZE = 1.0;
        static constexpr double MIN_SLIDER_RATIO = 0.1;

    public:

        enum Type {
            VERTICAL,
            HORIZONTAL
        };

        explicit Scrollbar(UIWindow* target, double slider_size, double slider_pos,
                           Scrollbar::Type type);

        void reactOnPress(MouseButtonEvent& event) override;

        bool onMouseScroll(MouseScrollEvent& event) override;

        // TODO: destructor

        Button* inc_button;
        Button* dec_button;
        Slidable* slider;

        UIWindow* inc_bt_win;
        UIWindow* dec_bt_win;
        UIWindow* slider_win;

    private:

        void constructVertical(UIWindow* target, double slider_size, double slider_pos);

        void constructHorizontal(UIWindow* target, double slider_size, double slider_pos);

        Type s_type;

    };

    /*------------------------------------------------------------------------*/

    class Scrollbar::Button : public Holdable {
    protected:

        Mouse::ScrollDelta m_delta;
        Mouse::ScrollType m_type;

    public:

        Button(UIWindow* target,
               Mouse::ScrollDelta delta,
               Mouse::ScrollType type)
               : Holdable(target)
               , m_delta(delta)
               , m_type(type)
               { }

        ~Button() override = default;

    protected:

        void reactOnHold(TimerEvent&) override {
            EventSystem::sendEvent<MouseScrollEvent>(
                    this, target<UIWindow>()->getPos(), m_delta, m_type
                    );
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_SCROLLBAR_HPP
/*============================================================================*/
