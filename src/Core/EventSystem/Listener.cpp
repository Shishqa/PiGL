/*============================================================================*/
#include "Listener.hpp"
#include "SubscriptionManager.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

Listener::~Listener() {
    SubscriptionManager::unsubscribeAll(this);
    SubscriptionManager::unsubscribeFromAll(this);
}

/*----------------------------------------------------------------------------*/

bool Listener::onEvent(Event&) {
    return false;
}

/*============================================================================*/
