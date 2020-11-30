/*============================================================================*/
#ifndef SHISHGL_DIALOG_HPP
#define SHISHGL_DIALOG_HPP
/*============================================================================*/
#include "Draggable.hpp"
/*============================================================================*/
namespace ShishGL {

    class Dialog : public Draggable {
    public:

        explicit Dialog(UIWindow* target)
                : Draggable(target)
                { }

        bool onMouseButton(MouseButtonEvent& event) override {

            if (event.state() == Mouse::UP) {
                return Draggable::onMouseButton(event);
            }

            for (auto& child : target<UIWindow>()->getChildren()) {
                if (child->contains(event.where())) {
                    return false;
                }
            }

            return Draggable::onMouseButton(event);
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_DIALOG_HPP
/*============================================================================*/
