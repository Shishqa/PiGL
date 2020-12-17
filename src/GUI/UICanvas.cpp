/*============================================================================*/
#include "UICanvas.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

UICanvas::UICanvas(const Frame& frame, const Color& color)
        : UIWindow(frame)
        , canvas(static_cast<Vector2<size_t>>(frame.size), color)
        , context(nullptr) {
    context = PLATFORM().createContext(canvas.size(), color);
}

/*----------------------------------------------------------------------------*/

UICanvas::~UICanvas() {
    delete context;
}

/*----------------------------------------------------------------------------*/

void UICanvas::onRender() {
    UIWindow::onRender();
    canvas.paste(context);
    PLATFORM().displayContext(context, getPos());
}

/*============================================================================*/
