/*============================================================================*/
#include <stdexcept>

#include "LogSystem.hpp"
#include "RenderSystem.hpp"

#ifdef USE_SFML
#include "SfmlPlatform/Platform.hpp"
#endif

/*============================================================================*/
using namespace Sh;
/*============================================================================*/

bool RenderSystem::is_initialized = false;

IPlatform* RenderSystem::active_platform = nullptr;

/*----------------------------------------------------------------------------*/

IPlatform& RenderSystem::Platform() {
    if (!active_platform) {
        LogSystem::printError("Using PLATFORM() before initialization!");
        throw std::runtime_error("Error: using class PLATFORM()"
                                 "which is not initialized");
    }
    return *active_platform;
}

/*----------------------------------------------------------------------------*/

IPlatform& Sh::PLATFORM() {
    return RenderSystem::Platform();
}

/*----------------------------------------------------------------------------*/

bool RenderSystem::isInitialized() {
    return is_initialized;
}

/*----------------------------------------------------------------------------*/

bool RenderSystem::init(int *argc_ptr, char **argv) {

    if (is_initialized) {
        return false;
    }

    LogSystem::printLog("Initializing platform");

#ifdef USE_SFML
    active_platform = new SfmlPlatform();
    LogSystem::printLog("SFML platform is now active");
#endif

    active_platform->initDisplay(argc_ptr, argv);
    LogSystem::printLog("Platform initialized");

    is_initialized = true;

    return true;
}

/*----------------------------------------------------------------------------*/

bool RenderSystem::terminate() {

    LogSystem::printLog("Terminating platform...");

    PLATFORM().closeDisplay();

    delete active_platform;
    active_platform = nullptr;

    LogSystem::printLog("Platform terminated");

    is_initialized = false;

    return true;
}

/*============================================================================*/
