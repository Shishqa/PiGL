/*============================================================================*/
#ifndef SHISHGL_WINDOW_IPP
#define SHISHGL_WINDOW_IPP
/*============================================================================*/
namespace Sh {

    template <typename SomeWindow, typename... Args>
    SomeWindow* Window::attach(Args&&... args) {
        SomeWindow* win =
                WindowManager::create<SomeWindow>(std::forward<Args>(args)...);
        attach<SomeWindow>(win);
        return win;
    }

    template <typename SomeWindow>
    SomeWindow* Window::attach(SomeWindow* child) {
        children.insert(child);
        child->setParent(this);
        return child;
    }

    template <typename SomeWindow>
    SomeWindow* Window::detach(SomeWindow* child) {
        children.erase(child);
        child->setParent(nullptr);
    }

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_IPP
/*============================================================================*/
