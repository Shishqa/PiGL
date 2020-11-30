/*============================================================================*/
#include <unistd.h>

#include "LogSystem.hpp"
#include "EventSystem.hpp"
#include "RenderSystem.hpp"
#include "CoreApplication.hpp"
#include "WindowManager.hpp"
#include "TimerEvent.hpp"
/*============================================================================*/
using namespace Sh;
/*============================================================================*/

bool CoreApplication::is_initialized = false;

/*----------------------------------------------------------------------------*/

bool CoreApplication::init(int *argc_ptr, char **argv) {

    if (is_initialized) {
        return false;
    }

    if (-1 == chdir(RUNTIME_DIR)) {
        return false;
    }

    LogSystem::openLog();
    LogSystem::printLog("Initializing RenderSystem...");

    RenderSystem::init(argc_ptr, argv);

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

    while (RENDERER().isRunning()) {

        TimeDelta event_delta = event_timer.elapsed();
        if (event_delta.count() > 55000000) {
            EventManager::postEvent<TimerEvent>(event_delta);
            event_timer.reset();
        }

        profiling_timer.reset();

        RENDERER().pollEvent();
        EventSystem::dispatchAll();
        if (!RENDERER().isRunning()) {
            break;
        }

        TimeDelta polling = profiling_timer.elapsed();
        if (polling > for_poll) {
            for_poll = polling;
        }

        ++frame_counter;

        RENDERER().clear(COLOR::WHITE);
        WindowManager::refresh();
        RENDERER().display();

        TimeDelta render = profiling_timer.elapsed();
        if (render - polling > for_render) {
            for_render = render - polling;
        }

        TimeDelta delta = frame_timer.elapsed();
        if (delta.count() > 1000000000LL) {
            printf("fps: %lu\n", frame_counter);
            frame_counter = 0;
            frame_timer.reset();
        }

        /*
        printf("POLL MAX: %lu\n"
           "RENDER MAX: %lu\n",
           polling.count(),
           render.count());
        fflush(stdout);
         */
    }

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
