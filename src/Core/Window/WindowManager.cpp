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

WindowManager::WinLayout& WindowManager::RootChildren() {
    static WinLayout CHILDREN;
    return CHILDREN;
}

/*============================================================================*/

void WindowManager::putRoot(Window* window) {
    window->setParent(ROOT);
    RootChildren().push_back(window);
}

/*----------------------------------------------------------------------------*/

void WindowManager::clear() {
    for (auto& win : Pool()) {
        delete win;
    }
}

/*----------------------------------------------------------------------------*/

void WindowManager::refresh() {
    for (auto& win : RootChildren()) {
        win->render();
    }
}

/*----------------------------------------------------------------------------*/

void WindowManager::dump(const std::string_view& file_name) {

    FILE* file = fopen(file_name.data(), "w");

    fprintf(file, "digraph {\n"
                  "\tnode [shape=record]\n");

    for (auto& child : RootChildren()) {
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
            "transform : %lgx%lg at (%lg; %lg) |"
            "viewport to set : %lgx%lg at (%lg; %lg)"
            "}\"];\n\n",
            reinterpret_cast<void*>(root), reinterpret_cast<void*>(root),
            root->getFrame().size.x, root->getFrame().size.y,
            root->getPos().x, root->getPos().y,
            root->view.size.x, root->view.size.x,
            root->view.pos.x, root->view.pos.y
            );

    for (auto& child : root->children) {
        fprintf(file, "\t node%p -> node%p [color=black];\n",
                reinterpret_cast<void*>(root),
                reinterpret_cast<void*>(child));
        dump(file, child);
    }

}

/*============================================================================*/