/*============================================================================*/
#ifndef SHISHGL_EVENT_HPP
#define SHISHGL_EVENT_HPP
/*============================================================================*/
#include <cstdint>

#include "Listener.hpp"
#include "LogSystem.hpp"
#include <stdexcept>
/*============================================================================*/
namespace Sh {

    class Event {
    public:

        using Mask = uint64_t;

        [[nodiscard]]
        bool isReceived() const;

        template <typename EventType>
        static uint8_t getId();

        template <typename EventType>
        static Mask getMask();

        virtual Mask mask();

        virtual ~Event() = default;

    protected:

        Event();

        virtual bool happen(Listener* listener) = 0;

    private:

        bool received;

        static uint8_t getUniqueId();

        friend class EventSystem;
        friend class EventManager;
        friend class SubscriptionManager;
    };

    /*------------------------------------------------------------------------*/

    template <typename EventType>
    uint8_t Event::getId() {
        static uint8_t ID = getUniqueId();
        return ID;
    }

    template <typename EventType>
    Event::Mask Event::getMask() {
        static Event::Mask MASK = (1ULL << getId<EventType>());
        return MASK;
    }

}
/*============================================================================*/
#endif //SHISHGL_EVENT_HPP
/*============================================================================*/
