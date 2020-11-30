/*============================================================================*/
#ifndef SHISHGL_UICANVAS_HPP
#define SHISHGL_UICANVAS_HPP
/*============================================================================*/
#include "Image.hpp"
#include "UIWindow.hpp"
/*============================================================================*/
namespace ShishGL {

    class UICanvas : public UIWindow {
    public:

        explicit UICanvas(const Viewport& frame, const Color& color = COLOR::NONE);

        void onRender() override;

        ~UICanvas() override;

    protected:

        Image canvas;

    private:

        IPlatform::IContext* context;

    };

}
/*============================================================================*/
#endif //SHISHGL_UICANVAS_HPP
/*============================================================================*/
