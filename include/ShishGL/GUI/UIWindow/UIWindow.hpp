/*============================================================================*/
#ifndef SHISHGL_UI_WINDOW_HPP
#define SHISHGL_UI_WINDOW_HPP
/*============================================================================*/
#include <unordered_map>
#include <unordered_set>
#include <memory>

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
            HOLD,
            SELECTED
        };

        template <int SomeState, typename... Args>
        UIWindow* applyStyle(Args&&... args);

        template <typename SomeShape, typename... Args>
        UIWindow* applyShape(Args&&... args);

        template <typename SomeBehavior, typename... Args>
        UIWindow* setBehavior(Args&&... args);

        [[nodiscard]]
        int getState() const;

        void setState(int new_state);

        [[nodiscard]]
        bool contains(const Vector2<double>& point) const override;

        void translate(const Vector2<double>& delta) override {
            Window::translate(delta);
            notifyBehavior();
        }

        void setPos(const Vector2<double>& pos) override {
            Window::setPos(pos);
            notifyBehavior();
        }

        void setParent(Window* new_parent) override {
            Window::setParent(new_parent);
            notifyBehavior();
        }

        [[nodiscard]]
        Behavior* getBehavior() const {
            return behavior;
        }

        ~UIWindow() override;

    protected:

        explicit UIWindow(const Frame& viewport);

        void onRender() override;

        using StyleMap = std::unordered_map<int, StylePack>;

        StyleMap& styles();

        [[nodiscard]]
        const Shape2D& shape() const;

        void notifyBehavior() {
            if (behavior) {
                behavior->onTargetUpdate();
            }
        }

    private:

        int state;

        StyleMap style_map; // TODO: style set + mask

        Shape2D* shape_impl;

        Behavior* behavior;

        friend class WindowManager;

    };

}
/*============================================================================*/
#include "UIWindow.ipp"
/*============================================================================*/
#endif //SHISHGL_UI_WINDOW_HPP
/*============================================================================*/