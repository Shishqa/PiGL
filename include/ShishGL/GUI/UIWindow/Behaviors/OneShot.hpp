/*============================================================================*/
#ifndef SHISHGL_ONESHOT_HPP
#define SHISHGL_ONESHOT_HPP
/*============================================================================*/
#include "DefaultBehavior.hpp"
#include "WindowManager.hpp"
/*============================================================================*/
namespace Sh {

    class OneShot : public DefaultBehavior {
    public:

        explicit OneShot(UIWindow* target)
                : DefaultBehavior(target)
                { }

        bool onMouseLeft(MouseEvent&) override {

            WindowManager::destroy(target<Window>());

            return true;

        }

    };


}
/*============================================================================*/
#endif //SISHGL_ONESHOT_HPP
/*============================================================================*/