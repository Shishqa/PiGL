/*============================================================================*/
#ifndef SHISHGL_TIMER_HPP
#define SHISHGL_TIMER_HPP
/*============================================================================*/
#include <chrono>
/*============================================================================*/
namespace Sh {

    using Clock     = std::chrono::system_clock;
    using TimePoint = Clock::time_point;
    using TimeDelta = Clock::duration;

    /*------------------------------------------------------------------------*/

    class Timer {
    public:

        Timer();

        virtual ~Timer() = default;

        void reset();

        [[nodiscard]]
        TimeDelta elapsed() const;

    protected:

        TimePoint start_time;

    };

}
/*============================================================================*/
#endif //SHISHGL_TIMER_HPP
/*============================================================================*/
