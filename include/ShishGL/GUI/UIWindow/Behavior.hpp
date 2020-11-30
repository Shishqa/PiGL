/*============================================================================*/
#ifndef SHISHGL_BEHAVIOR_HPP
#define SHISHGL_BEHAVIOR_HPP
/*============================================================================*/
#include "PlatformListener.hpp"
/*============================================================================*/
namespace ShishGL {

    class Behavior : public PlatformListener {
    public:

        explicit Behavior(class UIWindow* target)
                : target_window(target)
        { }

        template <typename SomeWindow>
        [[nodiscard]] SomeWindow* target() const {
            return dynamic_cast<SomeWindow*>(target_window);
        }

    private:

        class UIWindow* target_window;
    };

}
/*============================================================================*/
#endif //SHISHGL_BEHAVIOR_HPP
/*============================================================================*/