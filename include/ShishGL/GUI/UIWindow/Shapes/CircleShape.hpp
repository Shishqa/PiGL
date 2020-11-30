/*============================================================================*/
#ifndef SHISHGL_CIRCLE_HPP
#define SHISHGL_CIRCLE_HPP
/*============================================================================*/
#include "Shape2D.hpp"
/*============================================================================*/
namespace Sh {

    class CircleShape : public Shape2D {
    public:

        void draw(const Viewport& viewport) const override;

        [[nodiscard]]
        bool contains(const Viewport& viewport,
                      const Vector2<double>& point) const override;

    };

}
/*============================================================================*/
#endif //SHISHGL_CIRCLE_HPP
/*============================================================================*/
