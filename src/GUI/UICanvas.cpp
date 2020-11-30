/*============================================================================*/
#include "UICanvas.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

UICanvas::UICanvas(const Viewport& frame, const Color& color)
        : UIWindow(frame)
        , canvas(static_cast<Vector2<size_t>>(frame.size), color)
        , context(nullptr) {

    context = RENDERER().createContext(canvas.size(), color);
}

/*----------------------------------------------------------------------------*/

UICanvas::~UICanvas() {
    delete context;
}

/*----------------------------------------------------------------------------*/

void UICanvas::onRender() {
    canvas.paste(context);
    RENDERER().displayContext(context, getPos());
}

/*============================================================================*/
