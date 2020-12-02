/*============================================================================*/
#ifndef SHISHGL_UISLIDER_HPP
#define SHISHGL_UISLIDER_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "Slidable.hpp"
/*============================================================================*/
namespace Sh {

    template <typename Selector>
    class Slider : public Slidable {
    public:

        template <typename... Args>
        explicit Slider(UIWindow* target, const Segment2<double>& slide,
                        Args&&... args)
                : Slidable(target, slide, false)
                , selector(std::forward<Args>(args)...)
                { }

        bool onMouseMove(MouseEvent& event) override {

            bool status = Slidable::onMouseMove(event);

            if (status && Slidable::isHeld()) {

                selector.set(
                        (target<UIWindow>()->getPos() - Slidable::slide_seg.begin).length() /
                        Slidable::slide_seg.guide().length());

            }

            return status;
        }

    private:

        Selector selector;

    };

    /*------------------------------------------------------------------------*/

    template <typename Selector>
    class UISlider : public UIWindow {
    public:

        template <typename... Args>
        explicit UISlider(const Frame& frame, const Segment2<double>& slide,
                          Args&&... args)
                : UIWindow(frame) {
            UIWindow::addBehavior<Slider<Selector>>(slide, std::forward<Args>(args)...);
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_UISLIDER_HPP
/*============================================================================*/