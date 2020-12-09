/*============================================================================*/
#ifndef SHISHGL_SUBSCRIPTION_MANAGER_HPP
#define SHISHGL_SUBSCRIPTION_MANAGER_HPP
/*============================================================================*/
#include <cstdio>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

#include "Listener.hpp"
#include "Event.hpp"
/*============================================================================*/
namespace Sh {


    class SubscriptionManager {
    public:

        SubscriptionManager() = delete;

        template <typename SomeEvent>
        static void subscribe(Listener* receiver, Listener* sender);

        template <typename SomeEvent>
        static void unsubscribe(Listener* receiver, Listener* sender);

        static void unsubscribeAll(Listener* sender);

        static void unsubscribeFromAll(Listener* receiver);

        static void dump(const std::string_view& filename);

        virtual ~SubscriptionManager() = default;

    private:

        using SubscriptionPool =
            std::unordered_map<Listener*, std::unordered_map<Listener*, Event::Mask>>;

        friend class EventSystem;

        static SubscriptionPool& Subscriptions();

        friend class WindowManager;
    };

    /*------------------------------------------------------------------------*/

    template <typename SomeEvent>
    void SubscriptionManager::subscribe(Listener* receiver, Listener* sender) {
        Subscriptions()[sender][receiver] |= (1UL << Event::getId<SomeEvent>());
    }

    template <typename SomeEvent>
    void SubscriptionManager::unsubscribe(Listener* receiver, Listener* sender) {
        Subscriptions()[sender][receiver] &= ~(1UL << Event::getId<SomeEvent>());
    }

}
/*============================================================================*/
#endif //SHISHGL_SUBSCRIPTION_MANAGER_HPP
/*============================================================================*/