/*============================================================================*/
#ifndef SHISHGL_LOG_SYSTEM_HPP
#define SHISHGL_LOG_SYSTEM_HPP
/*============================================================================*/
#include <cstdio>
#include <cstdarg>

#include "Time.hpp"
/*============================================================================*/
namespace Sh {

    class LogSystem {
    public:

        typedef enum {
            LOG_OK = 0,
            LOG_OPEN_ERR,
            LOG_ALREADY_OPENED,
            LOG_CLOSE_ERR,
            LOG_FILE_BROKEN,
            LOG_PRINT_ERR
        } LogStatus;

        /*--------------------------------------------------------------------*/

        static LogStatus printLog(const char* format, ...)
        __attribute__((format(printf, 1, 2)));

        static LogStatus printWarning(const char* format, ...)
        __attribute__((format(printf, 1, 2)));

        static LogStatus printError(const char* format, ...)
        __attribute__((format(printf, 1, 2)));

        static void flush();

        /*--------------------------------------------------------------------*/

        virtual ~LogSystem() = default;

    private:

        LogSystem() = default;

        /*--------------------------------------------------------------------*/

        static LogStatus openLog();

        static LogStatus closeLog();

        static LogStatus print(const TimeDelta& elapsed,
                               const char* format, va_list args);

        /*--------------------------------------------------------------------*/
        static FILE* LOG_FILE;

        static constexpr size_t BUFFER_SIZE = 4096;

        struct Message {

            char buffer[BUFFER_SIZE];
            size_t cnt;

            TimeDelta begin;
            TimeDelta end;

        };

        static Message& LastMessage();
        /*--------------------------------------------------------------------*/

        static Timer& RunTimer();

        friend class CoreApplication;
    };

}
/*============================================================================*/
#endif //SHISHGL_LOG_SYSTEM_HPP
/*============================================================================*/
