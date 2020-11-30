/*============================================================================*/
#ifndef SHISHGL_UI_SLIDER_HPP
#define SHISHGL_UI_SLIDER_HPP
/*============================================================================*/
#include "Draggable.hpp"
#include "Segment2.hpp"
#include "Event.hpp"
/*============================================================================*/
namespace Sh {

    class Slidable : public Draggable {
    public:

        explicit Slidable(UIWindow* target,
                          const Segment2<double>& slide,
                          bool send_event = false);

        bool onMouseMove(MouseEvent& event) override;

        void slide(const Vector2<double>& delta, Mouse::Button button);

    private:

        bool need_reaction;
        Segment2<double> slide_seg;

    };

    /*------------------------------------------------------------------------*/

    class SlideListener : public Behavior {
    public:

        explicit SlideListener(UIWindow* target)
                : Behavior(target)
                { }

        virtual bool onSlide(class SlideEvent& event) = 0;

    };

    class SlideEvent : public Event {
    public:

        explicit SlideEvent(const Vector2<double>& delta)
                : Event()
                , slide_delta(delta)
                { }

        bool happen(Listener* listener) override {
            return dynamic_cast<SlideListener*>(listener)->onSlide(*this);
        }

        EventMask mask() override {
            return SLIDE;
        }

        [[nodiscard]]
        const Vector2<double>& delta() const {
            return slide_delta;
        }

    private:

        Vector2<double> slide_delta;

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_SLIDER_HPP
/*============================================================================*/
