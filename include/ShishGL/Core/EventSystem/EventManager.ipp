/*============================================================================*/
#ifndef SHISHGL_EVENT_MANAGER_IPP
#define SHISHGL_EVENT_MANAGER_IPP
/*============================================================================*/
namespace Sh {

    template <typename SomeEvent, typename... Args>
    EventManager::Helper<SomeEvent, void>
    EventManager::postEvent(Args&&... args) {
        auto event = new SomeEvent(std::forward<Args>(args)...);
        Events().push(event);
    }

}
/*============================================================================*/
#endif //SHISHGL_EVENT_MANAGER_IPP
/*============================================================================*/
