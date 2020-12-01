/*============================================================================*/
#ifndef SHISHGL_COLOR_FILL_HPP
#define SHISHGL_COLOR_FILL_HPP
/*============================================================================*/
#include "Style.hpp"
#include "Color.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
namespace Sh {

    class ColorFill : public Style {
    public:

        explicit ColorFill(const Color& color)
            : fill_color(color)
            { }

        void apply(Frame& frame, const Shape2D& shape) override {
            PLATFORM().setColor(fill_color);
            shape.draw(frame);
        }

        ~ColorFill() override = default;

    private:

        Color fill_color;

    };

}
/*============================================================================*/
#endif //SHISHGL_COLOR_FILL_HPP
/*============================================================================*/
