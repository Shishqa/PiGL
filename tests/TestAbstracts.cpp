/*============================================================================*/
#include "CoreApplication.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
#include "WindowManager.hpp"
#include "UILabel.hpp"
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
#include "UIButton.hpp"
#include "UICheckbox.hpp"
#include "UILabel.hpp"
#include "Font.hpp"

using namespace Sh;
/*============================================================================*/

class Dummy {
public:

    explicit Dummy(int value)
        : val(value)
        { }

    void operator()() const {
        printf("VALUE %d\n", val);
    }

private:

    int val;

};

class TogglerDummy {
public:

    explicit TogglerDummy() = default;

    void on() const {
        printf("ON\n");
    }

    void off() const {
        printf("OFF\n");
    }

};

/*============================================================================*/
int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv,
                          "/home/shishqa/dev/MIPT/2020_3/"
                          "00_ShishGL/tests/assets"
                          );

    PLATFORM().setFont(ResourceManager::get("fonts/FiraCode-Regular.ttf"));

    auto frame = WindowManager::Root()->attach<UIFrame>(
            Frame{ {20, 20}, {600, 600} },
            Frame{ {20, 20}, {1000, 1000} }
                    );
            frame->applyStyle<UIWindow::NORMAL>(
                    ColorFill{Color::WHITE}
                    )
            ->attach<UILabel>(
                    Frame{ {0, 0}, {100, 100} }, "HELLO, WORLD!\n:)0:0)0234"
                            )
                    ->addBehavior<Draggable>()
                    ->applyStyle<UIWindow::NORMAL>(
                            Font{"fonts/FiraCode-Regular.ttf"},
                            FontSize{30},
                            ColorFill{Color::BLACK}
                            );

    auto dummy = WindowManager::Root()->attach<UIButton<Dummy>>(Frame{ {800, 200}, {60, 20} }, 12);
    dummy->applyStyle<UIWindow::CLICK>(
            ColorFill{ Color::WHEAT }
            )
         ->applyStyle<UIWindow::HOVER>(
            ColorFill{ Color::GAINSBORO }
            )
         ->applyStyle<UIWindow::NORMAL>(
            ColorFill{ Color::PALE_VIOLET_RED }
            );

    auto ch = WindowManager::Root()->attach<UICheckbox<TogglerDummy>>(Frame{ {700, 200}, {60, 20} });
    ch->applyStyle<UIWindow::CLICK>(
                    ColorFill{ Color::WHEAT }
            )
            ->applyStyle<UIWindow::HOVER>(
                    ColorFill{ Color::GAINSBORO }
            )
            ->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color::PALE_VIOLET_RED }
            )
            ->applyStyle<UICheckbox<TogglerDummy>::CHECKED>(
                    ColorFill{ Color::GREEN }
                    );

    WindowManager::dump("LayoutDump.dot");
    SubscriptionManager::dump("Sub.dot");

    return CoreApplication::run();

}

/*============================================================================*/
