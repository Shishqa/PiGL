/*============================================================================*/
#include "CircleShape.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

void CircleShape::draw(const Viewport& viewport) const {
    double radius = std::min(viewport.size.x, viewport.size.y) / 2.0;
    PLATFORM().drawCircle(viewport.pos, radius);
}

/*----------------------------------------------------------------------------*/

bool CircleShape::contains(const Viewport &viewport,
                           const Vector2<double> &point) const {

    double radius = std::min(viewport.size.x, viewport.size.y) / 2.0;
    Vector2<double> center = viewport.pos + Vector2<double>{radius, radius};

    return ((point - center).length() <= radius);
}

/*============================================================================*/
