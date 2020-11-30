/*============================================================================*/
#ifndef SHISHGL_LAYOUT_MANAGER_HPP
#define SHISHGL_LAYOUT_MANAGER_HPP
/*============================================================================*/
#include <list>
#include <unordered_set>
#include <string_view>
/*============================================================================*/
namespace Sh {

    class Window;

    class WindowManager {
    public:

        WindowManager() = delete;

        template <typename SomeWindow, typename... Args>
        static SomeWindow* create(Args&&... args);

        /*----------------------------------------------*/
        static constexpr Window* ROOT = nullptr;

        static void putRoot(Window* window);
        /*----------------------------------------------*/

        static void dump(const std::string_view& file_name);

        virtual ~WindowManager() = default;

    private:

        static void refresh();

        static void clear();

        static void dump(FILE* file, Window* root);

        using WindowPool = std::unordered_set<Window*>;
        static WindowPool& Pool();

        using WinLayout = std::list<Window*>;
        static WinLayout& RootChildren();

        friend class Window;
        friend class CoreApplication;

    };

}
/*============================================================================*/
#include "WindowManager.ipp"
/*============================================================================*/
#endif //SHISHGL_LAYOUT_MANAGER_HPP
/*============================================================================*/
