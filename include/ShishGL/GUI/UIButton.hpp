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
        explicit UILabelButton(const Frame& frame, std::string&& text,
                               Text::Align align,
                               Args&&... args)
                : UIWindow(frame)
                , label_text(std::move(text)) {

            label = attach<UILabel>(
                Frame{{0, 0}, frame.size},
                std::string_view{label_text.c_str()},
                align
                );

            setBehavior<Behavior>(std::forward<Args>(args)...);
        }

        UIWindow* label;

    private:

        const std::string label_text;
    };

}
/*============================================================================*/
#endif //SHISHGL_UIBUTTON_HPP
/*============================================================================*/