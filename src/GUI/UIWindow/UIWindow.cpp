/*============================================================================*/
#include "UIWindow.hpp"
#include "RectangleShape.hpp"

#include <iostream>
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

UIWindow::StylePack::~StylePack() {
    for (auto& style : styles) {
        delete style.style;
    }
}

/*============================================================================*/

UIWindow::UIWindow(const Frame& viewport)
        : Window(viewport)
        , state(NORMAL)
        , style_pack()
        , shape_impl(nullptr)
        , behavior(nullptr) {
    applyShape<RectangleShape>();
}

/*----------------------------------------------------------------------------*/

UIWindow::~UIWindow() {
    delete behavior;
    delete shape_impl;
}

/*----------------------------------------------------------------------------*/

const Shape2D& UIWindow::shape() const {
    return *shape_impl;
}

UIWindow::StylePack& UIWindow::styles() {
    return style_pack;
}

/*----------------------------------------------------------------------------*/

int UIWindow::getState() const {
    return state;
}

void UIWindow::setState(int new_state) {
    state = new_state;
}

/*----------------------------------------------------------------------------*/

void UIWindow::onRender() {

    Window::onRender();

    Frame frame = getFrame();
    for (auto& style : style_pack.styles) {
        if (style.mask & getState()) {
            style.style->apply(frame, shape());
        }
    }

}

/*----------------------------------------------------------------------------*/

bool UIWindow::contains(const Vector2<double>& point) const {
    return (Window::contains(point) && shape().contains(getFrame(), point));
}

/*============================================================================*/