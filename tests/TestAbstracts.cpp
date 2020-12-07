/*============================================================================*/
#include "CoreApplication.hpp"
#include "WindowManager.hpp"
#include "Styles.hpp"
#include "Shapes.hpp"
#include "Behaviors.hpp"
#include "GUI.hpp"
#include "FpsLabel.hpp"
#include "GradeCanvas.hpp"

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

class DummySelector {
public:

    void operator()(const double& value) const {
        printf("%lg set\n", value);
    }

};

class DummySelector2D {
public:

    void operator()(const Vector2<double>& value) const {
        printf("(%lg; %lg) set\n", value.x, value.y);
    }
};

/*============================================================================*/
int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv,
                          "/home/shishqa/dev/MIPT/2020_3/"
                          "00_ShishGL/tests/assets"
                          );

    PLATFORM().setFont(ResourceManager::get("fonts/FiraCode-Regular.ttf"));

    /*
    auto fps = WindowManager::Root()->attach<FpsLabel>(
            Frame{ {1000, 0}, {164, 40} }
            );
    fps->applyStyle<UIWindow::NORMAL>(
            Font{"fonts/FiraCode-Regular.ttf"},
            FontSize{30},
            ColorFill{Color::WHITE}
            );

    char buffer[5] = "abc";

    auto input = WindowManager::Root()->attach<UITextInput>(
            Frame{ {1300, 0}, {164, 40} },
            buffer, sizeof(buffer)
    );
    input->applyStyle<UIWindow::NORMAL>(
            Font{"fonts/FiraCode-Regular.ttf"},
            FontSize{30},
            ColorFill{Color::WHITE}
    );

    auto frame = WindowManager::Root()->attach<UIFrame>(
            Frame{ {20, 20}, {600, 600} }
                    );
            frame->applyStyle<UIWindow::NORMAL>(
                    ColorFill{Color::WHITE}
                    )
            ->attach<GradeCanvas>(
                    Frame{ {0, 0}, {1000, 1000} }
                    );
    frame->fit();
    */


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

    auto sl = WindowManager::Root()->attach<UISlider<DummySelector>>(
            Frame{ {900, 200}, {600, 20} },
            UISlider<DummySelector>::VERTICAL,
            0.4
            );
    sl->applyStyle<UIWindow::CLICK>(
                    ColorFill{ Color::WHEAT }
            )
            ->applyStyle<UIWindow::HOVER>(
                    ColorFill{ Color::GAINSBORO }
            )
            ->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color::PALE_VIOLET_RED }
            );

    auto frame_sl = WindowManager::Root()->attach<UISlider2D<DummySelector2D>>(
            Frame{ {1000, 200}, {100, 100} }
    );
    frame_sl->applyStyle<UIWindow::CLICK>(
                    ColorFill{ Color::WHEAT }
            )
            ->applyStyle<UIWindow::HOVER>(
                    ColorFill{ Color::GAINSBORO }
            )
            ->applyStyle<UIWindow::NORMAL>(
                    ColorFill{ Color::PALE_VIOLET_RED }
            );

    WindowManager::dump("LayoutDump.dot");
    SubscriptionManager::dump("Sub.dot");

    return CoreApplication::run();

}

/*============================================================================*/
