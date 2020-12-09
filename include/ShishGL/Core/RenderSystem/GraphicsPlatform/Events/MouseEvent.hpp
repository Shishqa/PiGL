/*============================================================================*/
#ifndef SHISHGL_MOUSE_EVENT_HPP
#define SHISHGL_MOUSE_EVENT_HPP
/*============================================================================*/
#include "Event.hpp"
#include "Mouse.hpp"
#include "Vector2.hpp"
#include "PlatformListener.hpp"
/*============================================================================*/
namespace Sh {

    class MouseEvent : public Event {
    public:

        explicit MouseEvent(const Vector2<double>& where);

        ~MouseEvent() override = default;

        Event::Mask mask() override {
            return getMask<MouseEvent>();
        }

        [[nodiscard]]
        const Vector2<double>& where() const;

        void setWhere(const Vector2<double>& pos);

        bool happen(Listener* listener) override;

    protected:

        Vector2<double> m_where;

    };

    /*------------------------------------------------------------------------*/

    class MouseButtonEvent : public MouseEvent {
    public:

        MouseButtonEvent(const Vector2<double>& where,
                         Mouse::Button button,
                         Mouse::ButtonState state);

        ~MouseButtonEvent() override = default;

        Event::Mask mask() override {
            return getMask<MouseButtonEvent>();
        }

        [[nodiscard]]
        Mouse::Button button() const;

        [[nodiscard]]
        Mouse::ButtonState state() const;

        bool happen(Listener* listener) override;

    protected:

        Mouse::Button m_button;
        Mouse::ButtonState m_state;

    };

    /*------------------------------------------------------------------------*/

    class MouseScrollEvent : public MouseEvent {
    public:

        MouseScrollEvent(const Vector2<double>& where,
                         Mouse::ScrollDelta delta,
                         Mouse::ScrollType type);

        ~MouseScrollEvent() override = default;

        Event::Mask mask() override {
            return getMask<MouseScrollEvent>();
        }

        [[nodiscard]]
        Mouse::ScrollDelta delta() const;

        [[nodiscard]]
        Mouse::ScrollType type() const;

        bool happen(Listener* listener) override;

    protected:

        Mouse::ScrollDelta m_delta;
        Mouse::ScrollType m_type;

    };

}
/*============================================================================*/
#endif //SHISHGL_MOUSE_EVENT_HPP
/*============================================================================*/
