/*============================================================================*/
#include "LogSystem.hpp"
#include "EventManager.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

EventManager::EventQueue& EventManager::Events() {
    static EventQueue EVENTS;
    return EVENTS;
}

/*----------------------------------------------------------------------------*/

void EventManager::flush() {

    LogSystem::printLog("Flushing unused events...");

    const Event* event = nullptr;
    while (!Events().empty()) {

        event = Events().front();
                Events().pop();

        LogSystem::printWarning("Event %s flushed", typeid(*event).name());

        delete event;
    }

    LogSystem::printLog("Events flushed");

}

/*============================================================================*/
