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
                          const Frame& slide_frame)
                : Draggable(target)
                , frame(slide_frame)
                , parent_offset({})
                { }

        void onTargetUpdate() override {
            auto parent = target<UIWindow>()->getParent();
            if (parent) {
                frame.pos -= parent_offset;
                parent_offset = parent->getPos();
                frame.pos += parent_offset;
            }
        }

        bool onMouseButton(MouseButtonEvent& event) override {

            if (target<UIWindow>()->contains(event.where()) ||
                event.state() == Mouse::UP) {
                return Draggable::onMouseButton(event);
            }

            if (frame.contains(event.where())) {

                slide(
                    event.where() -
                    0.5 * target<UIWindow>()->getSize() -
                    target<UIWindow>()->getPos()
                    );

                return true;
            }

            return false;
        }

        bool onMouseMove(MouseEvent& event) override {

            Holdable::onMouseMove(event);

            if (isHeld()) {
                slide(event.where() - dragPoint());
            }

            return true;
        }

        void onDrag(const Vector2<double>&) final {

            Vector2<double> pos = target<UIWindow>()->getPos();
            Vector2<double> size = target<UIWindow>()->getSize();

            onSlide(Vector2<double>{
                (pos.x - frame.pos.x) / (frame.size.x - size.x),
                (pos.y - frame.pos.y) / (frame.size.y - size.y)
            });
        }

        virtual void onSlide(const Vector2<double>&) {}

    protected:

        void slide(const Vector2<double>& delta) {

            if (!isHeld()) {
                ++n_held;
            }

            Vector2<double> new_pos = target<UIWindow>()->getPos() + delta;
            Vector2<double> size = target<UIWindow>()->getSize();

            new_pos.x = std::max(
                frame.pos.x,
                std::min(frame.pos.x + frame.size.x - size.x, new_pos.x)
            );
            new_pos.y = std::max(
                frame.pos.y,
                std::min(frame.pos.y + frame.size.y - size.y, new_pos.y)
            );

            Draggable::drag(new_pos - target<UIWindow>()->getPos());
        }

        Frame frame;
        Vector2<double> parent_offset;
    };



    /*
    class Slidable : public Draggable {
    public:

        explicit Slidable(UIWindow* target,
                          const Segment2<double>& slide);

        bool onMouseMove(MouseEvent& event) override;

        void slide(const Vector2<double>& delta, Mouse::Button button);

        void slide(double delta);

        void setSegment(const Segment2<double>& segment) {
            slide_seg = segment;
        }

        virtual void onSlide(double value) { }

    protected:

        Segment2<double> slide_seg;
    };

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
    */
}
/*============================================================================*/
#endif //SHISHGL_UI_SLIDER_HPP
/*============================================================================*/
