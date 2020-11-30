/*============================================================================*/
#ifndef SHISHGL_WINDOW_MANAGER_IPP
#define SHISHGL_WINDOW_MANAGER_IPP
/*============================================================================*/
namespace Sh {

    template <typename SomeWindow, typename... Args>
    SomeWindow* WindowManager::create(Args&&... args) {

        auto* win = new SomeWindow(std::forward<Args>(args)...);
        Pool().insert(win);

        return win;
    }

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_MANAGER_IPP
/*============================================================================*/