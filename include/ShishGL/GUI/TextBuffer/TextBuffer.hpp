/*============================================================================*/
#ifndef SHISHGL_TEXT_BUFFER_HPP
#define SHISHGL_TEXT_BUFFER_HPP
/*============================================================================*/
#include "Text.hpp"
#include "Window.hpp"
/*============================================================================*/
namespace Sh {

    class TextBuffer : public Window {
    protected:

        static constexpr size_t DEFAULT_FONT_HEIGHT = 14;
        size_t curr_line_height;

        Text text;

    public:

        TextBuffer(const Viewport& viewport, const Text& text);

        ~TextBuffer() override = default;

    protected:

        void onRender() override;
    };

}
/*============================================================================*/
#endif //SHISHGL_TEXT_BUFFER_HPP
/*============================================================================*/
