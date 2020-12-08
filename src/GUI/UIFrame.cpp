/*============================================================================*/
#include "UIWindow.hpp"
#include "ColorFill.hpp"
#include "UIFrame.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

UIFrame::UIFrame(const Frame& frame)
        : UIWindow(frame)
        , v_scrollbar(nullptr)
        , h_scrollbar(nullptr)
        , rel_pos({})
        , max_rel_pos({}) {
    setBehavior<FrameBehavior>();
}


/*============================================================================*/
