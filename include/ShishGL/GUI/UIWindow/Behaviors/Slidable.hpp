/*============================================================================*/
#ifndef SHISHGL_UI_SLIDER_HPP
#define SHISHGL_UI_SLIDER_HPP
/*============================================================================*/
#include "Draggable.hpp"
#include "Segment2.hpp"
#include "Event.hpp"
/*============================================================================*/
namespace Sh {

    class Slidable : public Draggable {
    public:

        explicit Slidable(UIWindow *target, const Frame &slide_frame);

        void onTargetUpdate() override;

        bool onMouseButton(MouseButtonEvent &event) override;

        bool onMouseMove(MouseEvent &event) override;

        void onDrag(const Vector2<double> &) final;

        virtual void onSlide(const Vector2<double> &) {}

        void set(Vector2<double> pos);

        [[nodiscard]]
        Vector2<double> get() const;

    protected:

        void slide(const Vector2<double> &delta);

    private:

        Frame frame;
        Vector2<double> parent_offset;

    };

}
/*============================================================================*/
#endif //SHISHGL_UI_SLIDER_HPP
/*============================================================================*/
