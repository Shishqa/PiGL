/*============================================================================*/
#include <queue>
#include <cassert>

#include "SubscriptionManager.hpp"
#include "EventSystem.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

SubscriptionManager::SubscriptionPool& SubscriptionManager::Subscriptions() {
    static SubscriptionPool POOL;
    return POOL;
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::subscribe(Listener* receiver, Listener* sender,
                                    EventMask mask) {

    assert(receiver);

    Subscriptions()[sender][receiver] |= mask;
}

/*----------------------------------------------------------------------------*/

void SubscriptionManager::unsubscribe(Listener* receiver, Listener* sender,
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

    std::unordered_set<Listener*> visited;

    std::queue<Listener*> to_visit;
    to_visit.push(EventSystem::SystemEvents);

    while (!to_visit.empty()) {

        Listener* target = to_visit.front();
        to_visit.pop();

        visited.insert(target);

        fprintf(file,
                "\t\"node%p\" [label = \"{"
                "address : %p | %s"
                "}\"];\n\n",
                reinterpret_cast<const void*>(target),
                reinterpret_cast<const void*>(target),
                (target ? typeid(*target).name() : "ROOT")
                );

        for (auto& child : Subscriptions()[target]) {
            fprintf(file, "\t\"node%p\" -> \"node%p\" [color=black, label=\"mask=%lu\"];\n",
                    reinterpret_cast<const void*>(child.first),
                    reinterpret_cast<const void*>(target), child.second
                    );
            if (!visited.count(child.first)) {
                to_visit.push(child.first);
            }
        }
    }

    fprintf(file, "}\n");

    fclose(file);
}

/*============================================================================*/