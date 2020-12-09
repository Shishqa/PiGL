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
    static WindowPool POOL;
    return POOL;
}

Window* WindowManager::ROOT = nullptr;

Window* WindowManager::Root() {
    return ROOT;
}

/*============================================================================*/

void WindowManager::destroy(Window* window) {

    if (!window || Root() == window) {
        return;
    }

    std::queue<Window*> to_traverse;
    to_traverse.push(window);

    if (window->parent) {
        window->parent->detach(window);
    }

    while (!to_traverse.empty()) {

        Window* target = to_traverse.front();
        to_traverse.pop();

        printf("to destroy: %s\n", typeid(*target).name());

        ToDestroy().insert(target);

        for (auto& child : target->children) {
            to_traverse.push(child);
        }

        target->children.clear();
    }
}


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

    for (auto& window : ToDestroy()) {

        printf("destroying: %s\n", typeid(*window).name());

        Pool().erase(window);
        delete window;
    }
    ToDestroy().clear();

    ROOT->render();
}

/*----------------------------------------------------------------------------*/

void WindowManager::dump(const std::string_view& file_name) {

    FILE* file = fopen(file_name.data(), "w");

    fprintf(file, "digraph {\n"
                  "\tnode [shape=record]\n");

    for (auto& win : Pool()) {
        dump(file, win);
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