/*============================================================================*/
#ifndef SHISHGL_UIBUTTON_HPP
#define SHISHGL_UIBUTTON_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "Clickable.hpp"
#include "UILabel.hpp"

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

    template <typename Behavior>
    class UILabelButton : public UIWindow {
    public:

        template <typename... Args>
        explicit UILabelButton(const Frame& frame, const std::string_view& text,
                               IPlatform::Align align,
                               Args&&... args)
                : UIWindow(frame) {

            label = attach<UILabel>(Frame{{0, 0}, frame.size}, text, align);
            setBehavior<Behavior>(std::forward<Args>(args)...);
        }

        UIWindow* label;

    };

}
/*============================================================================*/
#endif //SHISHGL_UIBUTTON_HPP
/*============================================================================*/