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

        UIFrame(const Frame& frame, const Frame& contents_frame);

        UIScrollbar* v_scrollbar;
        UIScrollbar* h_scrollbar;

        Frame content_frame;
    };

    /*------------------------------------------------------------------------*/

    class FrameScrollable : public DefaultBehavior {
    public:

        explicit FrameScrollable(UIWindow* target);

        bool onMouseScroll(MouseScrollEvent& event) override;

    };

    /*------------------------------------------------------------------------*/

    class FrameSlidable : public SlideListener {
    public:

        explicit FrameSlidable(UIWindow* target);

        bool onSlide(SlideEvent& event) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_FRAME_HPP
/*============================================================================*/
