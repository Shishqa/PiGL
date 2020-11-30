#include "Sphere/sphere_canvas.hpp"
#include "Sphere/gamification_button.hpp"

using namespace ShishGL;

int main(int argc, char* argv[]) {

    ShishGL::init(&argc, argv);

    Window* canvas = new SphereCanvas(200, FOREST_GREEN, BLACK, WHITE);

    canvas->display();
    ShishGL::enterMainLoop();

    delete canvas;

    ShishGL::terminate();

    return 0;
}
