/*============================================================================*/
#ifndef SHISHGL_UIFILEDIALOG_HPP
#define SHISHGL_UIFILEDIALOG_HPP
/*============================================================================*/
#include "UIWindow.hpp"
#include "Styles.hpp"
#include "Behaviors.hpp"
#include "UIDialog.hpp"
/*============================================================================*/
namespace Sh {

    class UIFileSelector : public UIWindow {
    public:

        enum Signals {
            CANCEL   = 10,
            SELECTED
        };

        explicit UIFileSelector(const Frame& frame, char* buffer,
                                size_t buf_size)
                : UIWindow(frame) {

            applyStyle<UIWindow::NORMAL>(
                ColorFill{ Color(140, 140, 140) }
                );

            auto save_btn = attach<UILabelButton<WindowCloser>>(
                Frame{ {frame.size.x - 210, frame.size.y - 35}, {100, 30} },
                "Save", IPlatform::Align::CENTER,
                this, SELECTED
                );

            save_btn->applyStyle<UIWindow::NORMAL>(
                ColorFill{Color::GRAY}
                )
                ->applyStyle<UIWindow::HOVER>(
                    ColorFill{Color::WHITE}
                    );

            save_btn->label->applyStyle<UIWindow::NORMAL>(
                    Font{"./fonts/FiraCode-Regular.ttf"},
                    ColorFill{Color::BLACK}
                )
                ->applyStyle<UIWindow::HOVER>(
                    ColorFill{ Color::GREY }
                    );

            auto cancel_btn = attach<UILabelButton<WindowCloser>>(
                Frame{ {frame.size.x - 105, frame.size.y - 35}, {100, 30} },
                "Cancel", IPlatform::Align::CENTER,
                this, CANCEL
            );

            cancel_btn->applyStyle<UIWindow::NORMAL>(
                    ColorFill{Color::GRAY}
                )
                ->applyStyle<UIWindow::HOVER>(
                    ColorFill{Color::WHITE}
                );

            cancel_btn->label->applyStyle<UIWindow::NORMAL>(
                    Font{"./fonts/FiraCode-Regular.ttf"},
                    ColorFill{Color::BLACK}
                )
                ->applyStyle<UIWindow::HOVER>(
                    ColorFill{ Color::GREY }
                );

            auto input = attach<UITextInput>(
                Frame{ {5, frame.size.y - 70}, {frame.size.x - 10, 30} },
                buffer, buf_size
                );

            input->applyStyle<UIWindow::NORMAL>(
                ColorFill{Color::MAGENTA}
                );
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_UIFILEDIALOG_HPP
/*============================================================================*/