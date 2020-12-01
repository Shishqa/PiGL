/*============================================================================*/
#include "Frame.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

void Frame::fit_into(const Frame& other) {

    size.x = std::min(size.x, other.pos.x + other.size.x - pos.x);
    size.y = std::min(size.y, other.pos.y + other.size.y - pos.y);

    if (pos.x < other.pos.x) {
        size.x -= other.pos.x - pos.x;
        pos.x = other.pos.x;
    }

    if (pos.y < other.pos.y) {
        size.y -= other.pos.y - pos.y;
        pos.y = other.pos.y;
    }
}

/*----------------------------------------------------------------------------*/

Vector2<double> Frame::remap(const Vector2<double> &point) const {
    return point - pos;
}

/*============================================================================*/