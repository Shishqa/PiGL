/*============================================================================*/
#ifndef SHISHGL_RESOURCE_MANAGER_HPP
#define SHISHGL_RESOURCE_MANAGER_HPP
/*============================================================================*/
#include <cstdint>
#include <string_view>
#include <unordered_map>
/*============================================================================*/
namespace Sh {

    class ResourceManager {
    public:

        struct Resource {
            std::string_view filename;
            size_t size;
            uint8_t* data;
        };

        ResourceManager() = delete;

        static void load(const std::string_view& filename);

        static const Resource& get(const std::string_view& filename);

        static void forget(const std::string_view& filename);

        static void clear();

    private:

        using ResourceMap = std::unordered_map<std::string_view, Resource>;

        static ResourceMap& Resources();
    };

}
/*============================================================================*/
#endif //SHISHGL_RESOURCE_MANAGER_HPP
/*============================================================================*/
