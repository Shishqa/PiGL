/*============================================================================*/
#ifndef SHISHGL_RENDER_SYSTEM_HPP
#define SHISHGL_RENDER_SYSTEM_HPP
/*============================================================================*/
#include "IPlatform.hpp"
/*============================================================================*/
namespace Sh {

    class RenderSystem {
    public:

        static bool init(int* argc_ptr, char* argv[]);

        static bool terminate();

        static bool isInitialized();

        static IPlatform& Platform();

    private:

        static bool is_initialized;

        static IPlatform* active_platform;

    };

    IPlatform& PLATFORM();

}
/*============================================================================*/
#endif //SHISHGL_RENDER_SYSTEM_HPP
/*============================================================================*/
