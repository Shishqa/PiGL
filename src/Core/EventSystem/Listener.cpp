/*============================================================================*/
#include "Listener.hpp"
#include "SubscriptionManager.hpp"
/*============================================================================*/
using namespace ShishGL;
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
