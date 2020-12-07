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

WindowManager::WindowPool& WindowManager::ToDestroy() {
    static WindowPool TO_DESTROY;
    return TO_DESTROY;
}

Window* WindowManager::ROOT = nullptr;

bool WindowManager::pool_locked = false;

Window* WindowManager::Root() {
    return ROOT;
}

/*============================================================================*/

void WindowManager::init() {
    ROOT = new Window(Frame{ {0, 0}, PLATFORM().getDisplaySize() });
    Pool().insert(ROOT);
}

void WindowManager::destroy(Window* window) {
    if (Root() == window) {
        return;
    }
    ToDestroy().insert(window);
}

void WindowManager::clear() {
    pool_locked = true;
    for (auto& win : Pool()) {
        delete win;
    }
    pool_locked = false;
}

/*----------------------------------------------------------------------------*/

void WindowManager::refresh() {

    for (auto& win : ToDestroy()) {
        win->parent->detach(win);
        Pool().erase(win);

        delete win;
    }
    ToDestroy().clear();

    ROOT->render();
}

/*----------------------------------------------------------------------------*/

void WindowManager::dump(const std::string_view& file_name) {

    FILE* file = fopen(file_name.data(), "w");

    fprintf(file, "digraph {\n"
                  "\tnode [shape=record]\n");

    dump(file, Root());

    fprintf(file, "}\n");

    fclose(file);
}

/*----------------------------------------------------------------------------*/

void WindowManager::dump(FILE* file, Window* root) {

    fprintf(file,
            "\tnode%p [label = \"{"
            "what : %s |"
            "address : %p |"
            "frame : %lgx%lg at (%lg; %lg) |"
            "viewport : %lgx%lg at (%lg; %lg)"
            "}\"];\n\n",
            reinterpret_cast<void*>(root),
            typeid(root).name(),
            reinterpret_cast<void*>(root),
            root->getFrame().size.x, root->getFrame().size.y,
            root->getPos().x, root->getPos().y,
            root->viewport.size.x, root->viewport.size.y,
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