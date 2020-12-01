//
// Created by shishqa on 11/26/20.
//

#ifndef SHISHGL_SHAPE2D_HPP
#define SHISHGL_SHAPE2D_HPP
/*============================================================================*/
#include "Frame.hpp"
/*============================================================================*/
namespace Sh {

    class Shape2D {
    public:

        [[nodiscard]]
        virtual bool contains(const Frame& viewport,
                              const Vector2<double>& point) const = 0;

        virtual void draw(const Frame& viewport) const = 0;

        virtual ~Shape2D() = default;

    };

}
/*============================================================================*/
#endif //SHISHGL_SHAPE2D_HPP
