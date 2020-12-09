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

    typedef uint64_t EventMask;

    class Event {
    public:

        [[nodiscard]]
        bool isReceived() const;

        template <typename EventType>
        static uint8_t getId() {
            static uint8_t ID = getUniqueId();
            return ID;
        }

        template <typename EventType>
        static EventMask getMask() {
            static EventMask MASK = (1ULL << getId<EventType>());
            return MASK;
        }

    protected:

        Event();

        virtual bool happen(Listener* listener) = 0;

        virtual EventMask mask();

        virtual ~Event() = default;

    private:

        bool received;

        static uint8_t getUniqueId() {

            static constexpr uint8_t ID_LIMIT = 60;
            static uint8_t ID = 1;

            if (ID == ID_LIMIT) {
                throw std::runtime_error("reached limit of event types");
            }

            return ID++;
        }

        friend class EventSystem;
        friend class EventManager;
        friend class SubscriptionManager;
    };

}
/*============================================================================*/
#endif //SHISHGL_EVENT_HPP
/*============================================================================*/
