/*============================================================================*/
#include "Frame.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

#define FIT_DIMENSION( pt, left, right, dim )       \
    if ((pt).dim < (left).dim) {                        \
        (pt).dim = (left).dim;                          \
    } else if ((pt).dim > (right).dim) {                \
        (pt).dim = (right).dim;                         \
    }

void Frame::fit_into(const Frame& other) {

    Vector2<double> rd_corner = pos + size;

    FIT_DIMENSION(pos,       other.pos, other.pos + other.size, x)
    FIT_DIMENSION(pos,       other.pos, other.pos + other.size, y)
    FIT_DIMENSION(rd_corner, other.pos, other.pos + other.size, x)
    FIT_DIMENSION(rd_corner, other.pos, other.pos + other.size, y)

    size = rd_corner - pos;
}

#undef FIT_DIMENSION

/*----------------------------------------------------------------------------*/

Vector2<double> Frame::remap(const Vector2<double> &point) const {
    return point - pos;
}

/*============================================================================*/