/*============================================================================*/
#ifndef SHISHGL_WINDOW_IPP
#define SHISHGL_WINDOW_IPP
/*============================================================================*/
namespace ShishGL {

    template <typename SomeWindow, typename... Args>
    SomeWindow* Window::attach(Args&&... args) {
        SomeWindow* win =
                WindowManager::create<SomeWindow>(std::forward<Args>(args)...);
        attach(win);
        return win;
    }

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_IPP
/*============================================================================*/
