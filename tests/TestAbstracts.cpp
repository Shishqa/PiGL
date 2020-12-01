/*============================================================================*/
#include "CoreApplication.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
#include "WindowManager.hpp"
#include "TextBuffer.hpp"
//#include "WindowTypes.hpp"
#include "Clickable.hpp"
//#include "CursorLocator.hpp"
//#include "UIScrollbar.hpp"
#include "ColorFill.hpp"
#include "TextureFill.hpp"
#include "Bordered.hpp"
#include "UIWindow.hpp"
#include "Draggable.hpp"
#include "Slidable.hpp"

using namespace Sh;
/*============================================================================*/
int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv,
                          "/home/shishqa/dev/MIPT/2020_3/"
                          "00_ShishGL/tests/assets"
                          );

    PLATFORM().setFont(ResourceManager::get("fonts/FiraCode-Regular.ttf"));

    for (int h = 0; h < 3; ++h) {
        for (int l = 0; l < 15; ++l) {
            auto win_1 = WindowManager::Root()->attach<UIWindow>(
                    Frame{ {static_cast<double>(l * 100),
                            static_cast<double>(h * 100)},
                            {100,   100}
                            })
                    ->addBehavior<Draggable>()
                    ->applyStyle<UIWindow::NORMAL>(
                            ColorFill{Color::WHITE}
                            )
                    ->applyStyle<UIWindow::HOVER>(
                            Bordered{10, Color::GREEN},
                            ColorFill{Color::WHITE}
                            )
                    ->applyStyle<UIWindow::CLICK>(
                            Bordered{10, Color::BLUE},
                            ColorFill{Color::WHITE}
                            )
                    ->applyStyle<UIWindow::HOLD>(
                            Bordered{10, Color::RED},
                            ColorFill{Color::WHITE}
                            );

            win_1->attach<UIWindow>( Frame{ {10, 10}, {50, 50} } )
                    ->applyShape<CircleShape>()
                    ->addBehavior<Slidable>(
                            Segment2<double>{ {10, 10}, {50, 50} }
                            )
                    ->applyStyle<UIWindow::NORMAL>(
                            ColorFill{Color::BLUE_VIOLET}
                            );

            SubscriptionManager::unsubscribe(EventSystem::SystemEvents, win_1->as<Draggable>(),
                                             MOUSE_BUTTON);
        }
    }

    WindowManager::Root()->attach<UIWindow>(
            Frame{ {20, 500}, {300, 300} }
                    )
            ->applyStyle<UIWindow::NORMAL>(
                    ColorFill{Color::WHITE}
                    )
            ->attach<UIWindow>(
                    Frame{ {0, 0}, {50, 50} }
                            )
                    ->addBehavior<Draggable>()
                    ->applyStyle<UIWindow::NORMAL>(
                            ColorFill{ Color::GREEN_YELLOW }
                            );

    WindowManager::Root()->attach<UIWindow>(
                    Frame{ {800, 500}, {300, 300} }
            )
            ->applyStyle<UIWindow::NORMAL>(
                    ColorFill{Color::WHITE}
            )
            ->attach<UIWindow>(
                    Frame{ {0, 0}, {50, 50} }
            )
            ->addBehavior<Draggable>()
            ->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color::GREEN_YELLOW }
            );

    /*
    auto sb = WindowManager::create<UIWindow>(
            Frame{ {500, 50}, {50, 800}}
            );
    auto scrollbar = sb->addBehavior<Scrollbar>(
            0.3, 0.3, Scrollbar::VERTICAL
            );
    scrollbar->inc_bt_win->applyShape<RectangleShape>();
    scrollbar->inc_bt_win->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color::BEIGE}
            );
    scrollbar->inc_bt_win->applyStyle<UIWindow::HOVER>(
            ColorFill{Color::ROSY_BROWN}
            );
    scrollbar->inc_bt_win->applyStyle<UIWindow::CLICK>(
            ColorFill{Color::GREY}
    );

    scrollbar->dec_bt_win->applyShape<RectangleShape>();
    scrollbar->dec_bt_win->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color::BEIGE}
    );
    scrollbar->dec_bt_win->applyStyle<UIWindow::HOVER>(
            ColorFill{Color::ROSY_BROWN}
            );
    scrollbar->dec_bt_win->applyStyle<UIWindow::CLICK>(
            ColorFill{Color::GREY}
            );

    scrollbar->slider_win->applyShape<RectangleShape>();
    scrollbar->slider_win->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color::BLUE}
    );
    scrollbar->slider_win->applyStyle<UIWindow::CLICK>(
            ColorFill{Color::RED}
            );


    sb->applyShape<RectangleShape>();
    sb->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color::BLACK}
            );

    WindowManager::putRoot(sb);
    */

    WindowManager::dump("LayoutDump.dot");
    SubscriptionManager::dump("Sub.dot");

    return CoreApplication::run();

}

/*============================================================================*/
