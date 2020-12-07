/*============================================================================*/
#ifndef SHISHGL_UI_FRAME_HPP
#define SHISHGL_UI_FRAME_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "UIScrollbar.hpp"
#include "DefaultBehavior.hpp"
/*============================================================================*/
namespace Sh {

    class UIFrame : public UIWindow {
    public:

        static constexpr double SCROLLBAR_WIDTH = 15;

        UIFrame(const Frame& frame);

        void fit();

        void translateChildren(const Vector2<double>& delta);

        UIScrollbar* v_scrollbar;
        UIScrollbar* h_scrollbar;

        Frame content_frame;
    };

    /*------------------------------------------------------------------------*/

    class FrameScrollable : public DefaultBehavior {
    public:

        explicit FrameScrollable(UIWindow* target, UIScrollbar* scrollbar);

        bool onMouseScroll(MouseScrollEvent& event) override;

    };

    /*------------------------------------------------------------------------*/

    class FrameSlidable : public SlideListener {
    public:

        explicit FrameSlidable(UIWindow* target, UIScrollbar* scrollbar);

        bool onSlide(SlideEvent& event) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_FRAME_HPP
/*============================================================================*/
