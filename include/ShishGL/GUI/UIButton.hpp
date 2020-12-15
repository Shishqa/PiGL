/*============================================================================*/
#ifndef SHISHGL_UIBUTTON_HPP
#define SHISHGL_UIBUTTON_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "Clickable.hpp"

#include <string_view>
/*============================================================================*/
namespace Sh {

    template <typename Behavior>
    class UIButton : public UIWindow {
    public:

        template <typename... Args>
        explicit UIButton(const Frame& frame,
                          Args&&... args)
                : UIWindow(frame) {
            setBehavior<Behavior>(std::forward<Args>(args)...);
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_UIBUTTON_HPP
/*============================================================================*/