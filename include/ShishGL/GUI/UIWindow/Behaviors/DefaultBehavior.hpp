/*============================================================================*/
#ifndef SHISHGL_DEFAULT_BEHAVIOR_HPP
#define SHISHGL_DEFAULT_BEHAVIOR_HPP
/*============================================================================*/
#include "Behavior.hpp"
#include "UIWindow.hpp"
/*============================================================================*/
namespace Sh {

    class DefaultBehavior : public Behavior {
    public:

        explicit DefaultBehavior(UIWindow* target);

        ~DefaultBehavior() override = default;

    protected:

        virtual bool onMouseEntered(MouseEvent& event);

        virtual bool onMouseLeft(MouseEvent& event);

        bool onMouseMove(MouseEvent& event) override;

    };

}


/*============================================================================*/
#endif //SHISHGL_DEFAULT_HPP
/*============================================================================*/