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
            NORMAL   = 1UL << 0,
            HOVER    = 1UL << 1,
            CLICK    = 1UL << 2,
            HOLD     = 1UL << 3,
            SELECTED = 1UL << 4,
            ALL      = (1UL << 5) - 1
        };

        class StylePack {
        public:

            template <typename... Args>
            explicit StylePack(Args&&... args);

            ~StylePack();

            template <typename SomeStyle, typename... Args>
            void add(SomeStyle&& style, uint64_t mask,
                     Args&&... args);

            void add() {};

            struct MaskedStyle {

                MaskedStyle(Style* impl, uint64_t m)
                    : style(impl)
                    , mask(m)
                    { }

                Style* style;
                uint64_t mask;
            };

            std::vector<MaskedStyle> styles;
        };

        template <typename... Args>
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

        template <typename SomeBehavior>
        [[nodiscard]] SomeBehavior* as() const {
            return dynamic_cast<SomeBehavior*>(behavior);
        }

        ~UIWindow() override;

    protected:

        explicit UIWindow(const Frame& viewport);

        void onRender() override;

        StylePack& styles();

        [[nodiscard]]
        const Shape2D& shape() const;

        void notifyBehavior() {
            if (behavior) {
                behavior->onTargetUpdate();
            }
        }

    private:

        int state;

        StylePack style_pack;

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