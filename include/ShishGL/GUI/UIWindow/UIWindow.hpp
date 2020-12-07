/*============================================================================*/
#ifndef SHISHGL_UI_WINDOW_HPP
#define SHISHGL_UI_WINDOW_HPP
/*============================================================================*/
#include <unordered_map>
#include <memory>

#include "Window.hpp"
#include "Style.hpp"
#include "Shape2D.hpp"
#include "BehaviorManager.hpp"
/*============================================================================*/
namespace Sh {

    class UIWindow : public Window {
    public:

        enum States {
            NORMAL,
            HOVER,
            CLICK,
            HOLD,
            SELECTED
        };

        template <int SomeState, typename... Args>
        UIWindow* applyStyle(Args&&... args);

        template <typename SomeShape, typename... Args>
        UIWindow* applyShape(Args&&... args);

        template <typename SomeBehavior, typename... Args>
        SomeBehavior* addBehavior(Args&&... args);

        [[nodiscard]]
        int getState() const;

        void setState(int new_state);

        [[nodiscard]]
        bool contains(const Vector2<double>& point) const override;

        ~UIWindow() override;

    protected:

        explicit UIWindow(const Frame& viewport);

        void onRender() override;

        using StyleMap = std::unordered_map<int, StylePack>;

        StyleMap& styles();

        [[nodiscard]]
        const Shape2D& shape() const;

    private:

        int state;

        StyleMap style_map; // TODO: style set + mask

        Shape2D* shape_impl;

        std::unordered_set<Behavior*> behaviors;

        friend class WindowManager;

    };

}
/*============================================================================*/
#include "UIWindow.ipp"
/*============================================================================*/
#endif //SHISHGL_UI_WINDOW_HPP
/*============================================================================*/