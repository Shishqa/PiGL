/*============================================================================*/
#ifndef SHISHGL_BEHAVIOR_HPP
#define SHISHGL_BEHAVIOR_HPP
/*============================================================================*/
#include "PlatformListener.hpp"
/*============================================================================*/
namespace Sh {

    class Behavior : public PlatformListener {
    public:

        explicit Behavior(class UIWindow* target)
                : target_window(target)
        { }

        template <typename SomeWindow>
        [[nodiscard]] SomeWindow* target() const {
            return dynamic_cast<SomeWindow*>(target_window);
        }

        virtual void onTargetUpdate() {}

    private:

        class UIWindow* target_window;
    };

}
/*============================================================================*/
#endif //SHISHGL_BEHAVIOR_HPP
/*============================================================================*/