/*============================================================================*/
#include "RectangleShape.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

void RectangleShape::draw(const Frame& viewport) const {
    PLATFORM().drawRectangle(viewport.pos, viewport.size);
}

/*----------------------------------------------------------------------------*/

bool RectangleShape::contains(const Frame&,
                              const Vector2<double>&) const {
    return true;
}

/*============================================================================*/
