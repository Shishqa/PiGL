/*============================================================================*/
#ifndef SHISHGL_WINDOW_HPP
#define SHISHGL_WINDOW_HPP
/*============================================================================*/
#include <list>

#include "SubscriptionManager.hpp"
#include "PlatformListener.hpp"
#include "MouseEvent.hpp"
#include "EventSystem.hpp"
#include "Viewport.hpp"
#include "WindowManager.hpp"
/*============================================================================*/
namespace Sh {

    class Window {
    public:

        Window() = delete;

        virtual ~Window() = default;

        /* No-Copyable */
        /*-----------------------------------------------*/
        Window(const Window& other) = delete;
        Window& operator=(const Window& other) = delete;
        /*-----------------------------------------------*/

        /*-----------------------------------------------*/
        [[nodiscard]]
        const Window* getParent() const;

        template <typename SomeWindow, typename... Args>
        SomeWindow* attach(Args&&... args);

        virtual void attach(Window* child);

        virtual void detach(Window* child);
        /*-----------------------------------------------*/

        /*-----------------------------------------------*/
        [[nodiscard]]
        const Viewport& getFrame() const;

        [[nodiscard]]
        const Vector2<double>& getPos() const;

        [[nodiscard]]
        virtual bool contains(const Vector2<double>& point) const;

        void setPos(const Vector2<double>& pos);

        void translate(const Vector2<double>& delta);
        /*-----------------------------------------------*/

        const std::unordered_set<Window*>& getChildren() {
            return children;
        }

    protected:

        explicit Window(const Viewport& frame);

        virtual void onRender();

    private:

        void render();

        void setParent(Window* new_parent);

        void fitParent();

        friend class WindowManager;

        /* DATA */
        Viewport frame;
        Viewport view;
        Window* parent;
        std::unordered_set<Window*> children;

    };

}
/*============================================================================*/
#include "Window.ipp"
/*============================================================================*/
#endif //SHISHGL_WINDOW_HPP
/*============================================================================*/
