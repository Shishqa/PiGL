/*============================================================================*/
#ifndef SHISHGL_BEHAVIOR_MANAGER_HPP
#define SHISHGL_BEHAVIOR_MANAGER_HPP
/*============================================================================*/
#include <unordered_map>
#include <memory>

#include "Behavior.hpp"
/*============================================================================*/
namespace Sh {

    class UIWindow;

    class BehaviorManager {
    public:

        template<typename SomeBehavior, typename... Args>
        static SomeBehavior* add(UIWindow *window, Args &&... args) {

            Pool<SomeBehavior>()[window] = std::move(
                    std::make_unique<SomeBehavior>(window, std::forward<Args>(args)...)
            );

            return get<SomeBehavior>(window);

        }

        template<typename SomeBehavior>
        static SomeBehavior* get(UIWindow *window) {

            return Pool<SomeBehavior>()[window].get();

        }

    private:

        template<typename SomeBehavior>
        using BehaviorPool = std::unordered_map<
                UIWindow *,
                std::unique_ptr<SomeBehavior>
                >;

        template <typename SomeBehavior>
        static BehaviorPool<SomeBehavior>& Pool() {
            static BehaviorPool<SomeBehavior> POOL;
            return POOL;
        }

    };

}
/*============================================================================*/
#endif //SHISHGL_BEHAVIOR_MANAGER_HPP
/*============================================================================*/
