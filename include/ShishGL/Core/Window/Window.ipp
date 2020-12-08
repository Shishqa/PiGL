/*============================================================================*/
#ifndef SHISHGL_WINDOW_IPP
#define SHISHGL_WINDOW_IPP
/*============================================================================*/
namespace Sh {

    template <typename SomeWindow, typename... Args>
    SomeWindow* Window::attach(Args&&... args) {
        SomeWindow* win =
                WindowManager::create<SomeWindow>(std::forward<Args>(args)...);
        return attach(win);
    }

    template <typename SomeWindow>
    SomeWindow* Window::attach(SomeWindow* child) {
        children.push_back(child);
        child->setParent(this);
        return child;
    }

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_IPP
/*============================================================================*/
