/*============================================================================*/
#ifndef SHISHGL_WINDOW_HPP
#define SHISHGL_WINDOW_HPP
/*============================================================================*/
#include <list>
#include <optional>

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

        ~Window() override;

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

        template<typename SomeWindow>
        SomeWindow* attach(SomeWindow* child);

        Window* detach(Window* child);

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

        void fitParent();

    protected:

        explicit Window(const Frame& frame);

        virtual void onRender();

        virtual void setParent(Window* new_parent);

    private:

        void render();


        friend class WindowManager;

        /* DATA */
        Frame frame;
        Frame viewport;
        Window* parent;
        std::list<Window*> children;

    };

    /*------------------------------------------------------------------------*/

    class WindowEventListener : public PlatformListener {
    protected:

        friend class WindowCloseEvent;
        virtual bool onWindowClose(class WindowCloseEvent&) { return false; }

    };

    /*------------------------------------------------------------------------*/

    class WindowCloseEvent : public Event {
    public:

        using Value = std::optional<int>;

        explicit WindowCloseEvent(Window* window)
            : Event()
            , who_closed(window)
            { }

        explicit WindowCloseEvent(Window* window, int signal)
            : Event()
            , who_closed(window)
            , value(signal)
            { }

        EventMask mask() override {
            return getMask<WindowCloseEvent>();
        }

        const Window* who() {
            return who_closed;
        }

        const Value& signal() {
            return value;
        }

        bool happen(Listener* listener) override {
            return dynamic_cast<WindowEventListener*>(listener)->onWindowClose(*this);
        }

    private:

        Window* who_closed;
        Value value;
    };
}
/*============================================================================*/
#include "Window.ipp"
/*============================================================================*/
#endif //SHISHGL_WINDOW_HPP
/*============================================================================*/
