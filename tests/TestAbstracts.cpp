/*============================================================================*/
#include "CoreApplication.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
#include "WindowManager.hpp"
#include "ColorCollection.hpp"
#include "TextBuffer.hpp"
//#include "WindowTypes.hpp"
#include "Clickable.hpp"
//#include "CursorLocator.hpp"
#include "UIScrollbar.hpp"
#include "ColorFill.hpp"
#include "TextureFill.hpp"
#include "Bordered.hpp"
#include "UIWindow.hpp"
#include "Draggable.hpp"
#include "Slidable.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/
int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv);

    RENDERER().setFont(ResourceManager::get("fonts/FiraCode-Regular.ttf"));

    for (int h = 0; h < 3; ++h) {
        for (int l = 0; l < 15; ++l) {
            auto win_1 = WindowManager::create<UIWindow>(
                    Viewport{
                            {static_cast<double>(l * 100),
                             static_cast<double>(h * 100)},
                            {100,   100}
                    }
            );
            win_1->addBehavior<Draggable>();
            win_1->applyShape<RectangleShape>();
            win_1->applyStyle<UIWindow::NORMAL>(
                    ColorFill{COLOR::WHITE}
            );
            win_1->applyStyle<UIWindow::HOVER>(
                    Bordered{10, COLOR::GREEN},
                    ColorFill{COLOR::WHITE}
            );
            win_1->applyStyle<UIWindow::CLICK>(
                    Bordered{10, COLOR::BLUE},
                    ColorFill{COLOR::WHITE}
            );
            win_1->applyStyle<UIWindow::HOLD>(
                    Bordered{10, COLOR::RED},
                    ColorFill{COLOR::WHITE}
            );

            auto win_2 = win_1->attach<UIWindow>(
                    Viewport{
                            {10, 10},
                            {50, 50}
                    }
            );
            win_2->applyShape<CircleShape>();
            win_2->addBehavior<Slidable>(
                    Segment2<double>{
                            {10, 10},
                            {50, 50}
                    }
                    );
            win_2->applyStyle<UIWindow::NORMAL>(
                    ColorFill{COLOR::BLUE_VIOLET}
            );

            WindowManager::putRoot(win_1);
        }
    }

    auto sb = WindowManager::create<UIWindow>(
            Viewport{ {500, 50}, {50, 800}}
            );
    auto scrollbar = sb->addBehavior<Scrollbar>(
            0.3, 0.3, Scrollbar::VERTICAL
            );
    scrollbar->inc_bt_win->applyShape<RectangleShape>();
    scrollbar->inc_bt_win->applyStyle<UIWindow::NORMAL>(
            ColorFill{COLOR::BEIGE}
            );
    scrollbar->inc_bt_win->applyStyle<UIWindow::HOVER>(
            ColorFill{COLOR::ROSY_BROWN}
            );
    scrollbar->inc_bt_win->applyStyle<UIWindow::CLICK>(
            ColorFill{COLOR::GREY}
    );

    scrollbar->dec_bt_win->applyShape<RectangleShape>();
    scrollbar->dec_bt_win->applyStyle<UIWindow::NORMAL>(
            ColorFill{COLOR::BEIGE}
    );
    scrollbar->dec_bt_win->applyStyle<UIWindow::HOVER>(
            ColorFill{COLOR::ROSY_BROWN}
            );
    scrollbar->dec_bt_win->applyStyle<UIWindow::CLICK>(
            ColorFill{COLOR::GREY}
            );

    scrollbar->slider_win->applyShape<RectangleShape>();
    scrollbar->slider_win->applyStyle<UIWindow::NORMAL>(
            ColorFill{COLOR::BLUE}
    );
    scrollbar->slider_win->applyStyle<UIWindow::CLICK>(
            ColorFill{COLOR::RED}
            );


    sb->applyShape<RectangleShape>();
    sb->applyStyle<UIWindow::NORMAL>(
            ColorFill{COLOR::BLACK}
            );

    WindowManager::putRoot(sb);


    WindowManager::dump("LayoutDump.dot");
    SubscriptionManager::dump("Subscriptions.dot");

    return CoreApplication::run();

}

/*============================================================================*/
