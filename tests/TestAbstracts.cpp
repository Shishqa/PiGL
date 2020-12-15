/*============================================================================*/
#include "CoreApplication.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
#include "SubscriptionManager.hpp"
#include "WindowManager.hpp"
//#include "WindowTypes.hpp"
#include "Clickable.hpp"
//#include "CursorLocator.hpp"

#include "Behaviors.hpp"
#include "Styles.hpp"
#include "Shapes.hpp"
#include "GUI.hpp"
#include "GradeCanvas.hpp"
#include "FpsLabel.hpp"

#include <climits>

using namespace Sh;
/*============================================================================*/

class ClickTester : public Clickable {
public:

    explicit ClickTester(UIWindow* target)
        : Clickable(target)
        { }

    void reactOnRelease(MouseButtonEvent&) override {
        printf("ClickTester: clicked\n");
    }

};

class SwitchTester : public ClickSwitchable {
public:

    explicit SwitchTester(UIWindow* target)
        : ClickSwitchable(target)
        { }

    void onSelect() override {
        printf("SwitchTester: selected\n");
    }

    void onDeselect() override {
        printf("SwitchTester: deselected\n");
    }
};

class SlideTester : public ScrollSlidable {
public:

    explicit SlideTester(UIWindow* target, const Frame& frame)
        : ScrollSlidable(target, frame)
        { }

    void onSlide(const Vector2<double>& pos) override {
        printf("Slide: (%lg; %lg)\n", pos.x, pos.y);
    }
};

class FrameExpander : public Clickable {
public:

    explicit FrameExpander(UIWindow* target, UIFrame* frame)
            : Clickable(target)
            , fr(frame)
            { }

    void reactOnRelease(MouseButtonEvent& event) override {

        static double cnt = 0;

        fr->attach<GradeCanvas>(
            Frame{ {cnt * 100, cnt * 100}, {100, 100} }
            );
        fr->fit();

        cnt += 1;
    }

private:

    UIFrame* fr;

};

class TestFileSave : public Listener {
public:

    bool onEvent(Event& event) override {

        if (event.mask() == Event::getMask<FileSelectEvent>()) {

            auto file_select = dynamic_cast<FileSelectEvent&>(event);

            std::cout << "selected " << file_select.file() << "\n";

            return true;
        }

        return false;
    }

};

/*============================================================================*/
int main(int argc, char* argv[]) {

    CoreApplication::init(&argc, argv,
                          "/home/shishqa/dev/MIPT/2020_3/"
                          "00_ShishGL/tests/assets"
                          );

    PLATFORM().setFont(ResourceManager::get("fonts/FiraCode-Regular.ttf"));

    const Vector2<double> tester_size = { 150, 100 };

    WindowManager::Root()->attach<UIButton<ClickTester>>(
            Frame{ {20, 20}, tester_size }
            )
        ->applyStyle<UIWindow::NORMAL>(
            Bordered( 10, Color::YELLOW ),
            ColorFill( Color(10, 10, 10) )
            )
        ->applyStyle<UIWindow::HOVER>(
            Bordered( 10, Color::BLANCHED_ALMOND ),
            ColorFill( Color(10, 10, 10) )
            )
        ->applyStyle<UIWindow::CLICK>(
            Bordered( 10, Color::GREEN ),
            ColorFill( Color(10, 10, 10) )
            );

    WindowManager::Root()->attach<UIButton<SwitchTester>>(
            Frame{ {220, 20}, tester_size }
        )
        ->applyStyle<UIWindow::NORMAL>(
            Bordered( 10, Color::YELLOW ),
            ColorFill( Color(10, 10, 10) )
        )
        ->applyStyle<UIWindow::HOVER>(
            Bordered( 10, Color::BLANCHED_ALMOND ),
            ColorFill( Color(10, 10, 10) )
        )
        ->applyStyle<UIWindow::CLICK>(
            Bordered( 10, Color::GREEN ),
            ColorFill( Color(10, 10, 10) )
        )
        ->applyStyle<UIWindow::SELECTED>(
            Bordered( 10, Color::BLUE ),
            ColorFill( Color(10, 10, 10) )
        );

    auto h_slider = WindowManager::Root()->attach<UIHorizontalSlider<SlideTester>>(
        Frame{ {420, 20}, tester_size }, 30
        );
    h_slider->applyStyle<UIWindow::NORMAL>(
                ColorFill( Color::WHITE )
            );
    h_slider->slider->applyStyle<UIWindow::NORMAL>(
            ColorFill{ Color::DARK_OLIVE_GREEN }
        );

    auto v_slider = WindowManager::Root()->attach<UIVerticalSlider<SlideTester>>(
        Frame{ {20, 220}, {tester_size.y / 2, tester_size.x} }, 30
    );
    v_slider->applyStyle<UIWindow::NORMAL>(
        ColorFill( Color::WHITE )
    );
    v_slider->slider->applyStyle<UIWindow::NORMAL>(
        ColorFill{ Color::DARK_OLIVE_GREEN }
    );

    auto f_slider = WindowManager::Root()->attach<UIFreeSlider<SlideTester>>(
        Frame{ {220, 220}, {tester_size.x, tester_size.x} },
        Vector2<double>{30, 30}
    );
    f_slider->applyStyle<UIWindow::NORMAL>(
        ColorFill( Color::WHITE )
    );
    f_slider->slider->applyStyle<UIWindow::NORMAL>(
        ColorFill{ Color::DARK_OLIVE_GREEN }
    );

    auto v_sb = WindowManager::Root()->attach<UIVerticalScrollbar<SlideTester>>(
        Frame{ {120, 220}, {tester_size.y / 5, tester_size.x} }, 30
    );
    v_sb->up_button->applyStyle<UIWindow::NORMAL>(
            ColorFill( Color::WHITE )
            )
        ->applyStyle<UIWindow::HOVER>(
            ColorFill{ Color::GREEN }
            );
    v_sb->down_button->applyStyle<UIWindow::NORMAL>(
            ColorFill( Color::WHITE )
        )
        ->applyStyle<UIWindow::HOVER>(
            ColorFill{ Color::GREEN }
        );
    v_sb->slider->applyStyle<UIWindow::NORMAL>(
        ColorFill{ Color::DARK_OLIVE_GREEN }
        );
    v_sb->slider->slider->applyStyle<UIWindow::NORMAL>(
        ColorFill{ Color::WHEAT }
        );

    auto h_sb = WindowManager::Root()->attach<UIHorizontalScrollbar<SlideTester>>(
        Frame{ {20, 400}, {600, 30} }, 30
    );
    h_sb->left_button->applyStyle<UIWindow::NORMAL>(
            ColorFill( Color::WHITE )
        )
        ->applyStyle<UIWindow::HOVER>(
            ColorFill{ Color::GREEN }
        );
    h_sb->right_button->applyStyle<UIWindow::NORMAL>(
            ColorFill( Color::WHITE )
        )
        ->applyStyle<UIWindow::HOVER>(
            ColorFill{ Color::GREEN }
        );
    h_sb->slider->applyStyle<UIWindow::NORMAL>(
        ColorFill{ Color::DARK_OLIVE_GREEN }
    );
    h_sb->slider->slider->applyStyle<UIWindow::NORMAL>(
        ColorFill{ Color::WHEAT }
    );

    auto frame = WindowManager::create<UIFrame>(
        Frame{ {700, 20}, {600, 600} }
        );
    frame->applyStyle<UIWindow::NORMAL>(
            ColorFill{ Color::BLUE }
            );

    auto dialog = WindowManager::Root()->attach<UIDialog>(frame);
    dialog->setPos({10, 10});


    WindowManager::Root()->attach<FpsLabel>(
        Frame{ {1500, 20}, {300, 50} }
        )
        ->applyStyle<UIWindow::NORMAL>(
            FontSize{ 20 },
            ColorFill{ Color::MAGENTA }
            );

    WindowManager::Root()->attach<UIButton<FrameExpander>>(
            Frame{ {700, 700}, tester_size },
            frame
        )
        ->applyStyle<UIWindow::NORMAL>(
            Bordered( 10, Color::YELLOW ),
            ColorFill( Color(10, 10, 10) )
        )
        ->applyStyle<UIWindow::HOVER>(
            Bordered( 10, Color::BLANCHED_ALMOND ),
            ColorFill( Color(10, 10, 10) )
        )
        ->applyStyle<UIWindow::CLICK>(
            Bordered( 10, Color::GREEN ),
            ColorFill( Color(10, 10, 10) )
        );

    TestFileSave tester;

    auto selector = WindowManager::create<UIFileSelector>(
        Frame{ {800, 200}, {800, 700} }
        );

    SubscriptionManager::subscribe<FileSelectEvent>(&tester, selector);

    WindowManager::Root()->attach<UIDialog>(selector);

    WindowManager::dump("LayoutDump.dot");
    SubscriptionManager::dump("Sub.dot");

    CoreApplication::run();

    return 0;
}

/*============================================================================*/
