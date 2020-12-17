/*============================================================================*/
#ifndef SHISHGL_FPS_LABEL_HPP
#define SHISHGL_FPS_LABEL_HPP
/*============================================================================*/
#include "Time.hpp"
/*============================================================================*/
namespace Sh {

    class FpsLabel : public UIWindow {
    public:

        explicit FpsLabel(const Frame& frame)
            : UIWindow(frame)
            , frames_count(0) {
            timer.reset();
            applyStyle(
                Label(std::string_view(fps_buf, sizeof(fps_buf)), Color::MAGENTA, 15, Text::Align::LEFT), UIWindow::ALL
                );
        }

        void onRender() override {

            TimeDelta elapsed = timer.elapsed();
            if (elapsed.count() > 1000000000LL) {

                snprintf(fps_buf, sizeof(fps_buf),
                         "fps: %lu", frames_count);

                frames_count = 0;
                timer.reset();

            } else {

                ++frames_count;
            }

            UIWindow::onRender();
        }

    private:

        char fps_buf[16] = "";

        Timer timer;
        size_t frames_count;
    };

}
/*============================================================================*/
#endif //SHISHGL_FPS_LABEL_HPP
/*============================================================================*/
