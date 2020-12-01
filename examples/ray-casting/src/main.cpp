/*============================================================================*/
#include "SphereCast.hpp"
#include <CoreApplication.hpp>
#include <RectangleShape.hpp>
/*============================================================================*/

int main(int argc, char* argv[]) {

    Sh::CoreApplication::init(&argc, argv);

    auto canvas = Sh::WindowManager::create<SphereCanvas>(
            Sh::Frame{ {100, 100}, {800, 800} },
            200, Sh::Color::FOREST_GREEN,
            Sh::Color::GREEN_YELLOW,
            Sh::Color::WHITE
            );
    canvas->addBehavior<CanvasBehavior>();
    canvas->applyShape<Sh::RectangleShape>();

    Sh::WindowManager::putRoot(canvas);

    Sh::WindowManager::dump("windows.dot");

    return Sh::CoreApplication::run();
}
