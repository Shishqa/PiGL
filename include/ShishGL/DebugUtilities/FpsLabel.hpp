/*============================================================================*/
#ifndef SHISHGL_FPS_LABEL_HPP
#define SHISHGL_FPS_LABEL_HPP
/*============================================================================*/
#include "UILabel.hpp"
#include "Time.hpp"
/*============================================================================*/
namespace Sh {

    class FpsLabel : public UILabel {
    public:

        explicit FpsLabel(const Frame& frame)
            : UILabel(frame, std::string_view(fps_buf, sizeof(fps_buf) - 1))
            , frames_count(0) {
            timer.reset();
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

            UILabel::onRender();
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
