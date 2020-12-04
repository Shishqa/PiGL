/*============================================================================*/
#ifndef SHISHGL_UI_DRAGGABLE_HPP
#define SHISHGL_UI_DRAGGABLE_HPP
/*============================================================================*/
#include "Clickable.hpp"
#include "Vector2.hpp"
/*============================================================================*/
namespace Sh {

    class Draggable : public Holdable {
    public:

        explicit Draggable(UIWindow* target);

        [[nodiscard]]
        const Vector2<double>& dragPoint() const;

        bool onMouseButton(MouseButtonEvent& event) override;

        bool onMouseMove(MouseEvent& event) override;

        void drag(const Vector2<double>& delta, Mouse::Button button);

    protected:

        Vector2<double> drag_point;
    };

    /*------------------------------------------------------------------------*/

    class FrameDraggable : public Draggable {
    public:

        explicit FrameDraggable(UIWindow* target, const Frame& drag_frame)
                : Draggable(target)
                , frame(drag_frame) {

            /*
            const Window* parent = Behavior::target<UIWindow>()->getParent();

            if (parent) {
                frame.pos += parent->getPos();
            }
             */
        }

        bool onMouseMove(MouseEvent& event) override {

            bool status = Draggable::onMouseMove(event);

            if (status && Draggable::isHeld()) {

                Sh::Frame border = frame;
                const Window* parent = Behavior::target<UIWindow>()->getParent();

                if (parent) {
                    border.pos += parent->getPos();
                }

                Frame new_frame = target<UIWindow>()->getFrame();

                if (new_frame.pos.x < border.pos.x) {
                    new_frame.pos.x = border.pos.x;
                } else if (new_frame.pos.x + new_frame.size.x > border.pos.x + border.size.x) {
                    new_frame.pos.x = border.pos.x + border.size.x - new_frame.size.x;
                }

                if (new_frame.pos.y < border.pos.y) {
                    new_frame.pos.y = border.pos.y;
                } else if (new_frame.pos.y + new_frame.size.y > border.pos.y + border.size.y) {
                    new_frame.pos.y = border.pos.y + border.size.y - new_frame.size.y;
                }

                target<UIWindow>()->setPos(new_frame.pos);
            }

            return status;
        }

    protected:

        Frame frame;

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_DRAGGABLE_HPP
/*============================================================================*/
