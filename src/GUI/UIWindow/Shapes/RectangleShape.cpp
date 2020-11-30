/*============================================================================*/
#include "RectangleShape.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

void RectangleShape::draw(const Viewport& viewport) const {
    RENDERER().drawRectangle(viewport.pos, viewport.size);
}

/*----------------------------------------------------------------------------*/

bool RectangleShape::contains(const Viewport&,
                              const Vector2<double>&) const {
    return true;
}

/*============================================================================*/
