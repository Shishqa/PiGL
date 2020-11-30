/*============================================================================*/
#include "SubscriptionManager.hpp"
#include "EventSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

SubscriptionManager::SubscriptionPool& SubscriptionManager::Subscriptions() {
    static SubscriptionPool POOL;
    return POOL;
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::subscribe(Listener* sender, Listener* receiver,
                                    EventMask mask) {
    Subscriptions()[sender][receiver] |= mask;
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::unsubscribe(Listener* sender, Listener* receiver,
                                      EventMask mask) {
    Subscriptions()[sender][receiver] &= ~mask;
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::unsubscribeAll(Listener* sender) {
    Subscriptions()[sender].clear();
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::unsubscribeFromAll(Listener* receiver) {
    for (auto& pool : Subscriptions()) {
        pool.second.erase(receiver);
    }
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::dump(const std::string_view& file_name) {

    FILE* file = fopen(file_name.data(), "w");

    fprintf(file, "digraph {\n"
                  "\tnode [shape=record]\n");

    for (auto& child : Subscriptions()[EventSystem::SystemEvents]) {
        dump(file, child);
    }

    fprintf(file, "}\n");

    fclose(file);
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::dump(FILE* file, std::pair<const Listener*, EventMask> root) {

    fprintf(file,
            "\tnode%p [label = \"{"
            "address : %p |"
            "mask : %lX"
            "}\"];\n\n",
            reinterpret_cast<const void*>(root.first),
            reinterpret_cast<const void*>(root.first),
            root.second
    );

    for (auto& child : Subscriptions()[const_cast<Listener*>(root.first)]) {
        fprintf(file, "\t node%p -> node%p [color=black];\n",
                reinterpret_cast<const void*>(root.first),
                reinterpret_cast<const void*>(child.first));
        dump(file, child);
    }

}


/*============================================================================*/