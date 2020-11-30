/*============================================================================*/
#ifndef SHISHGL_EVENT_MANAGER_HPP
#define SHISHGL_EVENT_MANAGER_HPP
/*============================================================================*/
#include <type_traits>
#include <queue>

#include "Event.hpp"
/*============================================================================*/
namespace ShishGL {

    class EventManager {
    private:

        template <typename SomeEvent, typename T>
        using Helper =
                std::enable_if_t<std::is_base_of<Event, SomeEvent>::value, T>;

    public:

        template <typename SomeEvent, typename... Args>
        static Helper<SomeEvent, void> postEvent(Args&&... args);

        virtual ~EventManager() = default;

    private:

        EventManager() = default;

        using EventQueue = std::queue<Event*>;

        static EventQueue& Events();

        static void flush();

        friend class EventSystem;
        friend class CoreApplication;
    };

}
/*============================================================================*/
#include "EventManager.ipp"
/*============================================================================*/
#endif //SHISHGL_EVENT_MANAGER_HPP
/*============================================================================*/
