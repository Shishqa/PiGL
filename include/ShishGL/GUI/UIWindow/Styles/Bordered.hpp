/*============================================================================*/
#ifndef SHISHGL_BORDERED_HPP
#define SHISHGL_BORDERED_HPP
/*============================================================================*/
#include "Style.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
namespace ShishGL {

    class Bordered : public Style {
    public:

        explicit Bordered(const double& border_width,
                          const Color& border_color)
            : width(border_width)
            , color(border_color)
            { }

        void apply(Viewport& viewport, const Shape2D& shape) override {

            RENDERER().setColor(color);
            shape.draw(viewport);

            Vector2<double> offset{width, width};

            viewport.pos += offset;
            viewport.size -= 2.0 * offset;
        }

        ~Bordered() override = default;

    private:

        double width;
        Color color;
    };


}
/*============================================================================*/
#endif //SHISHGL_BORDERED_HPP
/*============================================================================*/
