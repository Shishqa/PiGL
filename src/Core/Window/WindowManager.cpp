/*============================================================================*/
#include <cstdio>

#include "WindowManager.hpp"
#include "Window.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

WindowManager::WindowPool& WindowManager::Pool() {
    static WindowPool POOL;
    return POOL;
}

Window* WindowManager::ROOT = nullptr;

Window* WindowManager::Root() {
    return ROOT;
}

/*============================================================================*/

void WindowManager::init() {
    ROOT = new Window(Frame{ {0, 0}, PLATFORM().getDisplaySize() });
    Pool().insert(ROOT);
}

void WindowManager::clear() {
    for (auto& win : Pool()) {
        delete win;
    }
}

/*----------------------------------------------------------------------------*/

void WindowManager::refresh() {
    ROOT->render();
}

/*----------------------------------------------------------------------------*/

void WindowManager::dump(const std::string_view& file_name) {

    FILE* file = fopen(file_name.data(), "w");

    fprintf(file, "digraph {\n"
                  "\tnode [shape=record]\n");

    for (auto& child : ROOT->getChildren()) {
        dump(file, child);
    }

    fprintf(file, "}\n");

    fclose(file);
}

/*----------------------------------------------------------------------------*/

void WindowManager::dump(FILE* file, Window* root) {

    fprintf(file,
            "\tnode%p [label = \"{"
            "address : %p |"
            "frame : %lgx%lg at (%lg; %lg) |"
            "viewport : %lgx%lg at (%lg; %lg)"
            "}\"];\n\n",
            reinterpret_cast<void*>(root), reinterpret_cast<void*>(root),
            root->getFrame().size.x, root->getFrame().size.y,
            root->getPos().x, root->getPos().y,
            root->viewport.size.x, root->viewport.size.x,
            root->viewport.pos.x, root->viewport.pos.y
            );

    for (auto& child : root->children) {
        fprintf(file, "\t node%p -> node%p [color=black];\n",
                reinterpret_cast<void*>(root),
                reinterpret_cast<void*>(child));
        dump(file, child);
    }

}

/*============================================================================*/