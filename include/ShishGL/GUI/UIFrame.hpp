/*============================================================================*/
#ifndef SHISHGL_UI_FRAME_HPP
#define SHISHGL_UI_FRAME_HPP
/*============================================================================*/
#include "Slidable.hpp"
/*============================================================================*/
namespace ShishGL {

    class Frame : public SlideListener {
    public:

        explicit Frame(UIWindow* target)
                : SlideListener(target)
                , v_scrollbar(nullptr)
                , h_scrollbar(nullptr)
                , content_view(target->getFrame()) {

            for (auto& child : target->getChildren()) {

                const Viewport& child_frame = child->getFrame();
                if (child_frame.pos.x > content_view.pos.x)


            }


        }

        bool onMouseScroll(MouseScrollEvent& event) override;

        UIWindow* v_scrollbar;
        UIWindow* h_scrollbar;

        Viewport content_view;

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_FRAME_HPP
/*============================================================================*/
