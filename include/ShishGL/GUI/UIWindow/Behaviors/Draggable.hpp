/*============================================================================*/
#ifndef SHISHGL_UI_DRAGGABLE_HPP
#define SHISHGL_UI_DRAGGABLE_HPP
/*============================================================================*/
#include "Clickable.hpp"
#include "Vector2.hpp"
/*============================================================================*/
namespace Sh {

    class Draggable : public Holdable {
    public:

        explicit Draggable(UIWindow* target);

        [[nodiscard]]
        const Vector2<double>& dragPoint() const;

        bool onMouseButton(MouseButtonEvent& event) override;

        bool onMouseMove(MouseEvent& event) override;

        virtual void onDrag(const Vector2<double>&) {}

    protected:

        void drag(const Vector2<double>& delta);

        Vector2<double> drag_point;
    };

}
/*============================================================================*/
#endif //SHISHGL_UI_DRAGGABLE_HPP
/*============================================================================*/
