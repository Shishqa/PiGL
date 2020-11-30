/*============================================================================*/
#ifndef SHISHGL_EVENT_HPP
#define SHISHGL_EVENT_HPP
/*============================================================================*/
#include <cstdint>

#include "Listener.hpp"
/*============================================================================*/
namespace Sh {

    typedef uint64_t EventMask;

    static constexpr EventMask
            NONE         = 0ULL,
            TIMER        = 1ULL << 0ULL,
            MOUSE_MOVE   = 1ULL << 1ULL,
            MOUSE_BUTTON = 1ULL << 2ULL,
            MOUSE_SCROLL = 1ULL << 3ULL,
            MOUSE        = MOUSE_SCROLL | MOUSE_BUTTON | MOUSE_MOVE,
            KEYBOARD     = 1ULL << 4ULL,
            SLIDE        = 1ULL << 5ULL,
            ALL          = ~NONE;

    /*------------------------------------------------------------------------*/

    class Event {
    public:

        bool isReceived() const;

    protected:

        Event();

        virtual bool happen(Listener* listener);

        virtual EventMask mask();

        virtual ~Event() = default;

    private:

        bool received;

        friend class EventSystem;
        friend class EventManager;
    };

}
/*============================================================================*/
#endif //SHISHGL_EVENT_HPP
/*============================================================================*/
