/*============================================================================*/
#ifndef SHISHGL_LAYOUT_MANAGER_HPP
#define SHISHGL_LAYOUT_MANAGER_HPP
/*============================================================================*/
#include <list>
#include <unordered_set>
#include <queue>
#include <string_view>
/*============================================================================*/
namespace Sh {

    class Window;

    class WindowManager {
    public:

        WindowManager() = delete;

        static void init();

        template <typename SomeWindow, typename... Args>
        static SomeWindow* create(Args&&... args);

        static void destroy(Window* window);

        static Window* Root();

        static void dump(const std::string_view& file_name);

        virtual ~WindowManager() = default;

    private:

        static void refresh();

        static void clear();

        static void dump(FILE* file, Window* root);

        using WindowPool = std::unordered_set<Window*>;
        static WindowPool& Pool();

        static WindowPool& ToDestroy();

        /*----------------------------------------------*/
        static Window* ROOT;
        /*----------------------------------------------*/

        friend class Window;
        friend class CoreApplication;

    };

}
/*============================================================================*/
#include "WindowManager.ipp"
/*============================================================================*/
#endif //SHISHGL_LAYOUT_MANAGER_HPP
/*============================================================================*/
