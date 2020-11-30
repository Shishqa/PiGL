/*============================================================================*/
#include "Viewport.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

void Viewport::set() const {
    RENDERER().setViewport(pos, size);
}

/*----------------------------------------------------------------------------*/

void Viewport::fit_into(const Viewport& other) {

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

Vector2<double> Viewport::remap(const Vector2<double> &point) const {
    return point - pos;
}

/*============================================================================*/