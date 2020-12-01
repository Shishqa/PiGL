/*============================================================================*/
#include "CoreApplication.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
#include "WindowManager.hpp"
#include "TextBuffer.hpp"
//#include "WindowTypes.hpp"
#include "Clickable.hpp"
//#include "CursorLocator.hpp"
#include "UIScrollbar.hpp"
#include "UIFrame.hpp"
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

    /*
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
        }
    }
     */

    auto frame = WindowManager::Root()->attach<UIFrame>(
            Frame{ {20, 500}, {300, 300} },
            Frame{ {20, 500}, {1000, 1000} }
                    );
            frame->applyStyle<UIWindow::NORMAL>(
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

    auto sb = WindowManager::Root()->attach<UIScrollbar>(
            Frame{ {500, 50}, {50, 800} }, UIScrollbar::VERTICAL
            );
    sb->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color::FOREST_GREEN}
            );
    sb->inc_button->applyShape<CircleShape>()
            ->applyStyle<UIWindow::NORMAL>(
                    ColorFill{Color::ALICE_BLUE}
                    )
            ->applyStyle<UIWindow::HOVER>(
                    ColorFill{Color::SKY_BLUE}
                    )
            ->applyStyle<UIWindow::CLICK>(
                    ColorFill{Color::LIGHT_BLUE}
                    );
    sb->dec_button->applyShape<CircleShape>()
            ->applyStyle<UIWindow::NORMAL>(
                    ColorFill{Color::ALICE_BLUE}
            )
            ->applyStyle<UIWindow::HOVER>(
                    ColorFill{Color::SKY_BLUE}
            )
            ->applyStyle<UIWindow::CLICK>(
                    ColorFill{Color::LIGHT_BLUE}
            );

    sb->slider->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color::BLUE}
    )
              ->applyStyle<UIWindow::CLICK>(
            ColorFill{Color::RED}
            );

    */
    WindowManager::dump("LayoutDump.dot");
    SubscriptionManager::dump("Sub.dot");

    return CoreApplication::run();

}

/*============================================================================*/
