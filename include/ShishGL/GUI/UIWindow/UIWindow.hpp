/*============================================================================*/
#ifndef SHISHGL_UI_WINDOW_HPP
#define SHISHGL_UI_WINDOW_HPP
/*============================================================================*/
#include <unordered_map>

#include "Window.hpp"
#include "Style.hpp"
#include "Shape2D.hpp"
#include "Behavior.hpp"
/*============================================================================*/
namespace Sh {

    class UIWindow : public Window {
    public:

        enum States {
            NORMAL,
            HOVER,
            CLICK,
            HOLD
        };

        template <int SomeState, typename... Args>
        void applyStyle(Args&&... args);

        template <typename SomeShape, typename... Args>
        void applyShape(Args&&... args);

        template <typename SomeBehavior, typename... Args>
        SomeBehavior* addBehavior(Args&&... args);

        [[nodiscard]]
        int getState() const;

        void setState(int new_state);

        [[nodiscard]]
        bool contains(const Vector2<double>& point) const override;

        ~UIWindow() override;

    protected:

        explicit UIWindow(const Viewport& viewport);


        void onRender() override;

        using StyleMap = std::unordered_map<int, StylePack>;

        StyleMap& styles();

        [[nodiscard]]
        const Shape2D& shape() const;

    private:

        int state;

        StyleMap style_map; // TODO: style set + mask

        std::unordered_set<Behavior*> behaviors;

        Shape2D* shape_impl;

        friend class WindowManager;

    };

}
/*============================================================================*/
#include "UIWindow.ipp"
/*============================================================================*/
#endif //SHISHGL_UI_WINDOW_HPP
/*============================================================================*/