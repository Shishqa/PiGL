/*============================================================================*/
#ifndef SHISHGL_UISLIDER2D_HPP
#define SHISHGL_UISLIDER2D_HPP
/*============================================================================*/
#include "Draggable.hpp"
#include "UIWindow.hpp"
/*============================================================================*/
namespace Sh {

    template <typename Selector2D>
    class Slider2D : public FrameDraggable {
    public:

        template <typename... Args>
        Slider2D(UIWindow* target, const Frame& frame, Args&&... args)
                : FrameDraggable(target, frame)
                , selector(std::forward<Args>(args)...)
                { }

        bool onMouseMove(MouseEvent& event) override {

            if (FrameDraggable::onMouseMove(event)) {

                Frame frame = target<UIWindow>()->getFrame();

                selector.set(Vector2<double>{
                        (frame.pos.x - FrameDraggable::frame.pos.x) / (FrameDraggable::frame.size.x - frame.size.x),
                        (frame.pos.y - FrameDraggable::frame.pos.y) / (FrameDraggable::frame.size.y - frame.size.y),
                });

                return true;
            }

            return false;
        }

    private:

        Selector2D selector;

    };

    /*------------------------------------------------------------------------*/

    template <typename Selector2D>
    class UISlider2D : public UIWindow {
    public:

        template <typename... Args>
        UISlider2D(const Frame& frame, const Frame& drag_frame, Args&&... args)
                : UIWindow(frame) {

            addBehavior<Slider2D<Selector2D>>(drag_frame, std::forward<Args>(args)...);
        }


    };

}
/*============================================================================*/
#endif //SHISHGL_UISLIDER2D_HPP
/*============================================================================*/
