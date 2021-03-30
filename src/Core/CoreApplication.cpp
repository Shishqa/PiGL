/*============================================================================*/
#include <unistd.h>
#include <filesystem>

#include "LogSystem.hpp"
#include "EventSystem.hpp"
#include "RenderSystem.hpp"
#include "CoreApplication.hpp"
#include "WindowManager.hpp"
#include "TimerEvent.hpp"
#include "SubscriptionManager.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

bool CoreApplication::is_initialized = false;

/*----------------------------------------------------------------------------*/

bool CoreApplication::init(int *argc_ptr, char **argv,
                           const char* runtime_dir) {

    if (is_initialized) {
        return false;
    }

    std::filesystem::current_path(runtime_dir);

    LogSystem::openLog();
    LogSystem::printLog("Initializing RenderSystem...");

    SubscriptionManager::init();

    RenderSystem::init(argc_ptr, argv);
    WindowManager::init();

    LogSystem::printLog("RenderSystem initialized");

    is_initialized = true;

    return true;
}

/*----------------------------------------------------------------------------*/

uint8_t CoreApplication::run() {

    if (!is_initialized) {
        LogSystem::printError("Running CoreApplication before initialization");
        return 10;
    }

    Timer event_timer = {};
    event_timer.reset();

    Timer frame_timer = {};
    frame_timer.reset();
    size_t frame_counter = 0;

    Timer profiling_timer = {};

    TimeDelta for_poll = {};
    TimeDelta for_render = {};

    LogSystem::printLog("Started run session");

    while (PLATFORM().isRunning()) {

        TimeDelta event_delta = event_timer.elapsed();
        if (event_delta.count() > 55000000) {
            EventManager::postEvent<TimerEvent>(event_delta);
            event_timer.reset();
        }

        profiling_timer.reset();

        PLATFORM().pollEvent();
        EventSystem::dispatchAll();
        if (!PLATFORM().isRunning()) {
            break;
        }

        TimeDelta polling = profiling_timer.elapsed();
        if (polling > for_poll) {
            for_poll = polling;
        }

        ++frame_counter;

        PLATFORM().clear(Color::NONE);
        WindowManager::refresh();
        PLATFORM().display();

        TimeDelta render = profiling_timer.elapsed();
        if (render - polling > for_render) {
            for_render = render - polling;
        }

        /*
        printf("POLL MAX: %lu\n"
           "RENDER MAX: %lu\n",
           polling.count(),
           render.count());
        fflush(stdout);
         */
    }

    WindowManager::dump("LayoutDumpAfter.dot");

    terminate();

    return 0;
}

/*----------------------------------------------------------------------------*/

bool CoreApplication::terminate() {

    LogSystem::printLog("Terminating Core...");
    EventManager::flush();
    RenderSystem::terminate();
    WindowManager::clear();
    ResourceManager::clear();
    LogSystem::printLog("Core terminated");

    LogSystem::closeLog();
    is_initialized = false;

    return true;
}

/*============================================================================*/
