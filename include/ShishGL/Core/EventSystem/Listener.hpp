/*============================================================================*/
#ifndef SHISHGL_LISTENER_HPP
#define SHISHGL_LISTENER_HPP
/*============================================================================*/
namespace Sh {

    class Listener {
    public:

        Listener() = default;

        virtual ~Listener();

    protected:

        [[nodiscard]]
        virtual bool onEvent(class Event&);

        friend class Event;
        friend class EventSystem;

    };

}
/*============================================================================*/
#endif //SHISHGL_LISTENER_HPP
/*============================================================================*/
