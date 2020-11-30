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
namespace ShishGL {


    class SubscriptionManager {
    public:

        SubscriptionManager() = delete;

        static void subscribe(Listener* sender, Listener* receiver,
                              EventMask mask);

        static void unsubscribe(Listener* sender, Listener* receiver,
                                EventMask mask);

        static void unsubscribeAll(Listener* sender);

        static void unsubscribeFromAll(Listener* receiver);

        static void dump(const std::string_view& filename);

        virtual ~SubscriptionManager() = default;

    private:

        static void dump(FILE* file,  std::pair<const Listener*, EventMask> root);

        using SubscriptionPool =
            std::unordered_map<Listener*, std::unordered_map<Listener*, EventMask>>;

        friend class EventSystem;

        static SubscriptionPool& Subscriptions();

        friend class WindowManager;
    };

}
/*============================================================================*/
#endif //SHISHGL_SUBSCRIPTION_MANAGER_HPP
/*============================================================================*/