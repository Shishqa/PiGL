/*============================================================================*/
#ifndef SHISHGL_UI_WINDOW_IPP
#define SHISHGL_UI_WINDOW_IPP
/*============================================================================*/
#include <cstdio>
/*============================================================================*/
namespace Sh {

    template <typename... Args>
    UIWindow* UIWindow::applyStyle(Args&&... args) {
        style_pack.template add(std::forward<Args>(args)...);
        return this;
    }

    /*------------------------------------------------------------------------*/

    template <typename SomeShape, typename... Args>
    UIWindow* UIWindow::applyShape(Args&&... args) {
        delete shape_impl;
        shape_impl = new SomeShape(std::forward<Args>(args)...);
        /* TODO: point to already allocated implementation */
        return this;
    }

    /*------------------------------------------------------------------------*/

    template <typename SomeBehavior, typename... Args>
    UIWindow* UIWindow::setBehavior(Args&&... args) {
        delete behavior;
        behavior = new SomeBehavior(this, std::forward<Args>(args)...);
        return this;
    }

    /*------------------------------------------------------------------------*/

    template <typename... Args>
    UIWindow::StylePack::StylePack(Args&&... args) {
        add(std::forward<Args>(args)...);
    }

    template <typename SomeStyle, typename... Args>
    void UIWindow::StylePack::add(SomeStyle&& style, uint64_t mask,
                                  Args&&... args) {
        auto new_style = new SomeStyle(std::forward<SomeStyle>(style));
        styles.push_back(MaskedStyle{new_style, mask});
        add(std::forward<Args>(args)...);
    }

}
/*============================================================================*/
#endif //SHISHGL_UI_WINDOW_IPP
/*============================================================================*/
