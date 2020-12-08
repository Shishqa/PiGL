/*============================================================================*/
#include "UIWindow.hpp"
#include "RectangleShape.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

UIWindow::UIWindow(const Frame& viewport)
        : Window(viewport)
        , state(NORMAL)
        , style_map({})
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

UIWindow::StyleMap& UIWindow::styles() {
    return style_map;
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

    for (int st = getState(); st >= NORMAL; --st) {
        if (styles().count(st)) {
            styles()[st].apply(frame, shape());
            break;
        }
    }
}

/*----------------------------------------------------------------------------*/

bool UIWindow::contains(const Vector2<double>& point) const {
    return (Window::contains(point) && shape().contains(getFrame(), point));
}

/*============================================================================*/