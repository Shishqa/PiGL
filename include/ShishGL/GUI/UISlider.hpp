/*============================================================================*/
#ifndef SHISHGL_UISLIDER_HPP
#define SHISHGL_UISLIDER_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "Slidable.hpp"
/*============================================================================*/
namespace Sh {

    template <typename Setter>
    class Slider : public Slidable {
    public:

        template <typename... Args>
        explicit Slider(UIWindow* target, const Segment2<double>& slide,
                        Args&&... args);

        bool onMouseMove(MouseEvent& event) override;

    private:

        Setter setter;
    };

    /*------------------------------------------------------------------------*/

    template <typename Setter>
    class UISlider : public UIWindow {
    public:

        enum Type {
            VERTICAL,
            HORIZONTAL
        };

        template <typename... Args>
        explicit UISlider(const Frame& frame, Type type,
                          double slider_size,
                          Args&&... args);

        UIWindow* slider;
    };

    /*------------------------------------------------------------------------*/

    template <typename VectorSetter>
    class Slider2D : public FrameDraggable {
    public:

        template <typename... Args>
        Slider2D(UIWindow* target, const Frame& frame, Args&&... args);

        bool onMouseMove(MouseEvent& event) override;

    private:

        VectorSetter setter;
    };

    /*------------------------------------------------------------------------*/

    template <typename Selector2D>
    class UISlider2D : public UIWindow {
    public:

        template <typename... Args>
        explicit UISlider2D(const Frame& frame, Args&&... args);

        UIWindow* slider;
    };

}
/*============================================================================*/
#include "UISlider.ipp"
/*============================================================================*/
#endif //SHISHGL_UISLIDER_HPP
/*============================================================================*/