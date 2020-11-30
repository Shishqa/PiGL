/*============================================================================*/
#ifndef SHISHGL_RECTANGLE_HPP
#define SHISHGL_RECTANGLE_HPP
/*============================================================================*/
#include "Shape2D.hpp"
/*============================================================================*/
namespace ShishGL {

    class RectangleShape : public Shape2D {
    public:

        void draw(const Viewport& viewport) const override;

        [[nodiscard]]
        bool contains(const Viewport& viewport,
                      const Vector2<double>& point) const override;

    };

}
/*============================================================================*/
#endif //SHISHGL_RECTANGLE_HPP
/*============================================================================*/
