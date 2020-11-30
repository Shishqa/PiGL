/*============================================================================*/
#ifndef SHISHGL_VIEWPORT_HPP
#define SHISHGL_VIEWPORT_HPP
/*============================================================================*/
#include "Vector2.hpp"
/*============================================================================*/
namespace Sh {

    struct Viewport {

        Vector2<double> pos;
        Vector2<double> size;

        void set() const;

        void fit_into(const Viewport& other);

        [[nodiscard]]
        Vector2<double> remap(const Vector2<double>& point) const;
    };

}
/*============================================================================*/
#endif //SHISHGL_VIEWPORT_HPP
/*============================================================================*/
