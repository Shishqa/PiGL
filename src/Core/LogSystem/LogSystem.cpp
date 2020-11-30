/*============================================================================*/
#include <cstdio>
#include <cstdarg>
#include <cstring>

#include "Time.hpp"
#include "LogSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

FILE* LogSystem::LOG_FILE = nullptr;

/*----------------------------------------------------------------------------*/

LogSystem::Message& LogSystem::LastMessage() {

    static Message LAST_MESSAGE = {
            "", 0, {}, {}
    };

    return LAST_MESSAGE;
}

/*----------------------------------------------------------------------------*/

Timer& LogSystem::RunTimer() {
    static Timer RUN_TIMER;
    return RUN_TIMER;
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::openLog() {

    if (LOG_FILE) {
        return LOG_ALREADY_OPENED;
    }
    LOG_FILE = fopen("ShishGL_log", "w");

    if (LOG_FILE) {
        fprintf(LOG_FILE, "\n======================[ ShishGL Log Session ]======================\n");
    }

    return (LOG_FILE ? LOG_OK : LOG_OPEN_ERR);
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::closeLog() {

    flush();

    if (LOG_FILE) {
        fprintf(LOG_FILE, "====================================================================\n\n");
    }

    fclose(LOG_FILE);
    LOG_FILE = nullptr;
    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::printLog(const char *format, ...) {

    if (!LOG_FILE) {
        return LOG_PRINT_ERR;
    }

    va_list arg_list = {};
    va_start(arg_list, format);
    print(RunTimer().elapsed(), format, arg_list);
    va_end(arg_list);

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::printWarning(const char *format, ...) {

    if (!LOG_FILE) {
        return LOG_PRINT_ERR;
    }

    va_list arg_list = {};
    va_start(arg_list, format);
    print(RunTimer().elapsed(), format, arg_list);
    va_end(arg_list);

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::printError(const char *format, ...) {

    if (!LOG_FILE) {
        return LOG_PRINT_ERR;
    }

    va_list arg_list = {};
    va_start(arg_list, format);
    print(RunTimer().elapsed(), format, arg_list);
    va_end(arg_list);

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

LogSystem::LogStatus LogSystem::print(const TimeDelta& elapsed,
                                      const char* format, va_list args) {

    static char buffer[BUFFER_SIZE] = "";

    int str_len = vsnprintf(buffer, sizeof(buffer), format, args);

    if (str_len < 0) {
        return LOG_PRINT_ERR;
    }

    if (LastMessage().cnt && !strncmp(buffer, LastMessage().buffer, static_cast<size_t>(str_len))) {

        //flush();

        LastMessage().cnt++;
        LastMessage().end = elapsed;

    } else {

        flush();

        strncpy(LastMessage().buffer, buffer, static_cast<size_t>(str_len) + 1);

        LastMessage().cnt = 1;
        LastMessage().begin = elapsed;
        LastMessage().end = elapsed;

    }

    return LOG_OK;
}

/*----------------------------------------------------------------------------*/

void LogSystem::flush() {

    if (LastMessage().cnt > 1) {

        fprintf(LOG_FILE, "[%15ld]\n"
                          "        |         : %s (x%lu)\n"
                          "[%15ld]\n",
                LastMessage().begin.count(),
                LastMessage().buffer,
                LastMessage().cnt,
                LastMessage().end.count());

    } else if (LastMessage().cnt == 1) {

        fprintf(LOG_FILE, "[%15ld] : %s\n",
                LastMessage().end.count(),
                LastMessage().buffer);

    }

    LastMessage().cnt = 0;

    fflush(LOG_FILE);

}

/*============================================================================*/
