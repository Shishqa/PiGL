/*============================================================================*/
#ifndef SHISHGL_FRAME_HPP
#define SHISHGL_FRAME_HPP
/*============================================================================*/
#include "Vector2.hpp"
/*============================================================================*/
namespace Sh {

    struct Frame {

        Vector2<double> pos;
        Vector2<double> size;

        void fit_into(const Frame& other);

        [[nodiscard]]
        Vector2<double> remap(const Vector2<double>& point) const;
    };

}
/*============================================================================*/
#endif //SHISHGL_FRAME_HPP
/*============================================================================*/
