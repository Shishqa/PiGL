/*============================================================================*/
#ifndef SHISHGL_UISLIDER_IPP
#define SHISHGL_UISLIDER_IPP
/*============================================================================*/
namespace Sh {

template <typename Setter>
template <typename... Args>
Slider<Setter>::Slider(UIWindow* target, const Segment2<double>& slide,
                       Args&&... args)
        : Slidable(target, slide)
        , setter(std::forward<Args>(args)...)
        { }

template <typename Setter>
bool Slider<Setter>::onMouseMove(MouseEvent& event) {

    bool status = Slidable::onMouseMove(event);

    if (status && Slidable::isHeld()) {

        Segment2<double> slide = Slidable::slide_seg;
        const Window* parent = target<Window>()->getParent();

        if (parent) {
            slide.begin += parent->getPos();
            slide.end   += parent->getPos();
        }

        setter((target<UIWindow>()->getPos() - slide.begin).length() /
               slide.guide().length());

    }

    return status;
}

/*========================================================================*/

template <typename Setter>
template <typename... Args>
UISlider<Setter>::UISlider(const Frame& frame, Type type,
                             double slider_size,
                             Args&&... args)
        : UIWindow(frame)
        , slider(nullptr) {

    if (slider_size >= 1.0) {
        slider_size = 0.99;
    } else if (slider_size < 0.15) {
        slider_size = 0.15;
    }

    if (VERTICAL == type) {

        Vector2<double> slider_sz{
                frame.size.x,
                frame.size.y * slider_size
        };

        slider = attach<UIWindow>(
                Frame{ {0, 0}, {slider_sz} }
                );
        slider->addBehavior<Slider<Setter>>(
                    Segment2<double>{
                        {0, 0},
                        {0, frame.size.y - slider_sz.y}
                    }
                );

    } else {

        Vector2<double> slider_sz{
                frame.size.x,
                frame.size.y * slider_size
        };

        slider = attach<UIWindow>(
                Frame{ {0, 0}, {slider_sz} }
                );
        slider->addBehavior<Slider<Setter>>(
                    Segment2<double>{
                        {0, 0},
                        {0, frame.size.y - slider_sz.y}
                    }
                );
    }
}

/*------------------------------------------------------------------------*/

template <typename VectorSetter>
template <typename... Args>
Slider2D<VectorSetter>::Slider2D(UIWindow* target, const Frame& frame,
                                 Args&&... args)
        : FrameDraggable(target, frame)
        , setter(std::forward<Args>(args)...)
        { }

template <typename VectorSetter>
bool Slider2D<VectorSetter>::onMouseMove(MouseEvent& event) {

    if (FrameDraggable::onMouseMove(event) && FrameDraggable::isHeld()) {

        Sh::Frame border = frame;
        const Window *parent = Behavior::target<UIWindow>()->getParent();

        if (parent) {
            border.pos += parent->getPos();
        }

        Frame frame = target<UIWindow>()->getFrame();

        setter(Vector2<double>{
                (frame.pos.x - border.pos.x) / (border.size.x - frame.size.x),
                (frame.pos.y - border.pos.y) / (border.size.y - frame.size.y),
        });

        return true;
    }

    return false;
}

/*----------------------------------------------------------------------------*/

template <typename VectorSetter>
template <typename... Args>
UISlider2D<VectorSetter>::UISlider2D(const Frame& frame, Args&&... args)
        : UIWindow(frame)
        , slider(nullptr) {

    slider = attach<UIWindow>(
            Frame{ {0, 0}, 0.05 * frame.size }
            );
    slider->addBehavior<Slider2D<VectorSetter>>(
                    frame, std::forward<Args>(args)...
                    );

}

/*============================================================================*/
#endif //SHISHGL_UISLIDER_IPP
/*============================================================================*/