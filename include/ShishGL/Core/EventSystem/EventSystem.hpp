/*============================================================================*/
#ifndef SHISHGL_EVENT_SYSTEM_HPP
#define SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
#include "EventManager.hpp"
/*============================================================================*/
namespace Sh {

    class EventSystem {
    public:

        static constexpr Listener* SystemEvents = nullptr;

        template <typename SomeEvent, typename... Args>
        static bool sendEvent(Listener* sender, Args&&... args);

        static bool sendEvent(Listener* sender, Event& event);

        static bool dispatchAll();

        static bool dispatchOne();

        virtual ~EventSystem() = default;

    protected:

        EventSystem() = default;
    };

}
/*============================================================================*/
#include "EventSystem.ipp"
/*============================================================================*/
#endif //SHISHGL_EVENT_SYSTEM_HPP
/*============================================================================*/
