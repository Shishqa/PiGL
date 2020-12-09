/*============================================================================*/
#ifndef SHISHGL_LISTENER_HPP
#define SHISHGL_LISTENER_HPP
/*============================================================================*/
namespace Sh {

    class Listener {
    public:

        virtual ~Listener();

        virtual bool onEvent(class Event*);

    protected:

        friend class Event;
        friend class EventSystem;

    };

}
/*============================================================================*/
#endif //SHISHGL_LISTENER_HPP
/*============================================================================*/
