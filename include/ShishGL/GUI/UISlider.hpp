/*============================================================================*/
#ifndef SHISHGL_UISLIDER_HPP
#define SHISHGL_UISLIDER_HPP
/*============================================================================*/
#include <variant>

#include "UIWindow.hpp"
#include "Slidable.hpp"
/*============================================================================*/
namespace Sh {

    template <typename Behavior>
    class UIVerticalSlider : public UIWindow {
    public:

        template <typename... Args>
        explicit UIVerticalSlider(const Frame& frame,
                                  double slider_len,
                                  Args&&... args)
                : UIWindow(frame) {

            slider = attach<UIWindow>(Frame{
                {0, 0},
                {frame.size.x, std::min(frame.size.y, slider_len)}
            });

            slider->setBehavior<Behavior>(Frame{ {0, 0}, frame.size },
                                          std::forward<Args>(args)...);
        }

        UIWindow* slider;
    };

    template <typename Behavior>
    class UIHorizontalSlider : public UIWindow {
    public:

        template <typename... Args>
        explicit UIHorizontalSlider(const Frame& frame,
                                    double slider_len,
                                    Args&&... args)
            : UIWindow(frame) {

            slider = attach<UIWindow>(Frame{
                {0, 0},
                {std::min(frame.size.x, slider_len), frame.size.y}
            });

            slider->setBehavior<Behavior>(Frame{ {0, 0}, frame.size },
                                          std::forward<Args>(args)...);
        }

        UIWindow* slider;
    };


    template <typename Behavior>
    class UIFreeSlider : public UIWindow {
    public:

        template <typename... Args>
        explicit UIFreeSlider(const Frame& frame,
                              const Vector2<double>& size,
                              Args&&... args)
            : UIWindow(frame) {

            slider = attach<UIWindow>(Frame{
                {0, 0},
                {std::min(frame.size.x, size.x), std::min(frame.size.y, size.y)}
            });

            slider->setBehavior<Behavior>(Frame{ {0, 0}, frame.size },
                                          std::forward<Args>(args)...);
        }

        UIWindow* slider;
    };

}
/*============================================================================*/
#endif //SHISHGL_UISLIDER_HPP
/*============================================================================*/