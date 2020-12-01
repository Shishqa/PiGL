/*============================================================================*/
#include "Window.hpp"
#include "WindowManager.hpp"
#include "LogSystem.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

Window::Window(const Frame& frame)
        : frame(frame)
        , viewport({})
        , parent(WindowManager::ROOT) {
    fitParent();
}

/*----------------------------------------------------------------------------*/

const Window* Window::getParent() const {
    return parent;
}

const Frame& Window::getFrame() const {
    return frame;
}

/*============================================================================*/

void Window::setParent(Window* new_parent) {
    parent = new_parent;
    if (parent) {
        translate(parent->getPos());
    }
    fitParent();
}

/*============================================================================*/

void Window::render() {
    onRender();
    for (auto& child : children) {
        child->render();
    }
}

/*----------------------------------------------------------------------------*/

void Window::onRender() {
    PLATFORM().setViewport(viewport);
}

/*============================================================================*/

void Window::fitParent() {
    viewport = frame;
    if (parent) {
        viewport.fit_into(parent->viewport);
        for (auto& child : children) {
            child->fitParent();
        }
    }
}

/*----------------------------------------------------------------------------*/

const Vector2<double>& Window::getPos() const {
    return frame.pos;
}

/*----------------------------------------------------------------------------*/

void Window::setPos(const Vector2<double>& pos) {

    Vector2<double> old_pos = pos;

    frame.pos = pos;
    fitParent();

    for (auto& child : children) {
        child->translate(pos - old_pos);
    }
}

/*----------------------------------------------------------------------------*/

void Window::translate(const Vector2<double>& delta) {

    frame.pos += delta;
    fitParent();

    for (auto& child : children) {
        child->translate(delta);
    }
}

/*----------------------------------------------------------------------------*/

bool Window::contains(const Vector2<double>& point) const {
    return (viewport.pos.x <= point.x && point.x <= viewport.pos.x + viewport.size.x &&
            viewport.pos.y <= point.y && point.y <= viewport.pos.y + viewport.size.y);
}

/*============================================================================*/