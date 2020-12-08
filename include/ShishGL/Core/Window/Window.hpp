/*============================================================================*/
#ifndef SHISHGL_WINDOW_HPP
#define SHISHGL_WINDOW_HPP
/*============================================================================*/
#include <list>

#include "SubscriptionManager.hpp"
#include "PlatformListener.hpp"
#include "MouseEvent.hpp"
#include "EventSystem.hpp"
#include "Frame.hpp"
#include "WindowManager.hpp"
/*============================================================================*/
namespace Sh {

    class Window : public Listener {
    public:

        Window() = delete;

        ~Window() override = default;

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

        template <typename SomeWindow>
        SomeWindow* attach(SomeWindow* child);

        Window* detach(Window* child);
        /*-----------------------------------------------*/

        /*-----------------------------------------------*/
        [[nodiscard]]
        const Frame& getFrame() const;

        [[nodiscard]]
        const Vector2<double>& getSize() const;

        [[nodiscard]]
        const Vector2<double>& getPos() const;

        [[nodiscard]]
        virtual bool contains(const Vector2<double>& point) const;

        virtual void setPos(const Vector2<double>& pos);

        virtual void translate(const Vector2<double>& delta);
        /*-----------------------------------------------*/

        const std::list<Window*>& getChildren() {
            return children;
        }

    protected:

        explicit Window(const Frame& frame);

        virtual void onRender();

        virtual void setParent(Window* new_parent);

    private:

        void render();

        void fitParent();

        friend class WindowManager;

        /* DATA */
        Frame frame;
        Frame viewport;
        Window* parent;
        std::list<Window*> children;

    };

}
/*============================================================================*/
#include "Window.ipp"
/*============================================================================*/
#endif //SHISHGL_WINDOW_HPP
/*============================================================================*/
