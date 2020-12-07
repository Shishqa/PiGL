/*============================================================================*/
#ifndef SHISHGL_GRADECANVAS_HPP
#define SHISHGL_GRADECANVAS_HPP
/*============================================================================*/
#include "UICanvas.hpp"
/*============================================================================*/
namespace Sh {

    class GradeCanvas : public UICanvas {
    public:

        explicit GradeCanvas(const Frame& frame)
                : UICanvas(frame, Color::WHITE) {

            for (size_t x = 0; x < canvas.size().x; ++x) {
                for (size_t y = 0; y < canvas.size().y; ++y) {

                    double intensity = (static_cast<double>(x) / static_cast<double>(canvas.size().x)) *
                                       (static_cast<double>(y) / static_cast<double>(canvas.size().y));

                    canvas.setPixel(
                            {x, y},
                            Color(static_cast<uint8_t>(255.0 * intensity),
                                  static_cast<uint8_t>(255.0 * intensity),
                                  static_cast<uint8_t>(255.0 * intensity),
                                  255
                            )
                    );

                }
            }

        }




    };




}
/*============================================================================*/
#endif //SHISHGL_GRADECANVAS_HPP
/*============================================================================*/