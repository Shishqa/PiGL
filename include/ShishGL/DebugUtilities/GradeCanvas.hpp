/*============================================================================*/
#ifndef SHISHGL_GRADECANVAS_HPP
#define SHISHGL_GRADECANVAS_HPP
/*============================================================================*/
#include "GUI.hpp"
/*============================================================================*/
namespace Sh {

    class GradeCanvas : public UICanvas {
    public:

        explicit GradeCanvas(const Frame& frame)
                : UICanvas(frame, Color::YELLOW) {

            static constexpr size_t OFFSET = 20;

            for (size_t x = OFFSET; x < canvas.size().x - OFFSET; ++x) {
                for (size_t y = OFFSET; y < canvas.size().y - OFFSET; ++y) {
                    canvas.setPixel({x, y}, Color::RED);
                }
            }
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_GRADECANVAS_HPP
/*============================================================================*/