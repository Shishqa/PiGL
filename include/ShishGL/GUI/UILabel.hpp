/*============================================================================*/
#ifndef SHISHGL_TEXT_BUFFER_HPP
#define SHISHGL_TEXT_BUFFER_HPP
/*============================================================================*/
#include "Text.hpp"
#include "UIWindow.hpp"
#include "TextShape.hpp"
/*============================================================================*/
namespace Sh {

    class UILabel : public UIWindow {
    public:

        UILabel(const Frame& frame, const std::string_view& text)
                : UIWindow(frame) {
            applyShape<TextShape>(text);
        }

        ~UILabel() override = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_TEXT_BUFFER_HPP
/*============================================================================*/
