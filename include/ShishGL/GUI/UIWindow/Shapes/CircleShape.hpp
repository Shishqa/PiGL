/*============================================================================*/
#ifndef SHISHGL_CIRCLE_HPP
#define SHISHGL_CIRCLE_HPP
/*============================================================================*/
#include "Shape2D.hpp"
/*============================================================================*/
namespace Sh {

    class CircleShape : public Shape2D {
    public:

        void draw(const Frame& viewport) const override;

        [[nodiscard]]
        bool contains(const Frame& viewport,
                      const Vector2<double>& point) const override;

    };

}
/*============================================================================*/
#endif //SHISHGL_CIRCLE_HPP
/*============================================================================*/
