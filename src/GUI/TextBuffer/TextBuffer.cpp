/*============================================================================*/
#include <cassert>

#include "TextBuffer.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

TextBuffer::TextBuffer(const Viewport& viewport,
                       const Text& text)
    : Window(viewport)
    , curr_line_height(DEFAULT_FONT_HEIGHT)
    , text(text)
    { }

/*----------------------------------------------------------------------------*/

void TextBuffer::onRender() {

    Window::onRender();

    assert(curr_line_height != 0);

    size_t curr_start = 0;
    size_t curr_end = 10;

    Vector2<double> curr_pos = getPos();
    const Vector2<double> delta{0, static_cast<double>(curr_line_height)};

    PLATFORM().setColor(Color::BLACK);
    for (size_t i = curr_start; i < curr_end; ++i) {

        PLATFORM().displayText(text.lines()[i], curr_line_height, curr_pos);
        curr_pos += delta;

    }
}

/*============================================================================*/
