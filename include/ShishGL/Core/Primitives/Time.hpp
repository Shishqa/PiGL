/*============================================================================*/
#ifndef SHISHGL_TIMER_HPP
#define SHISHGL_TIMER_HPP
/*============================================================================*/
#include <chrono>
/*============================================================================*/
namespace ShishGL {

    using Clock     = std::chrono::system_clock;
    using TimePoint = Clock::time_point;
    using TimeDelta = Clock::duration;

    /*------------------------------------------------------------------------*/

    class Timer {
    public:

        Timer()
            : start_time(Clock::now()) {}

        virtual ~Timer() = default;

        void reset() {
            start_time = Clock::now();
        }

        [[nodiscard]]
        TimeDelta elapsed() const {
            TimePoint now = Clock::now();
            return now - start_time;
        }

    protected:

        TimePoint start_time;

    };

}
/*============================================================================*/
#endif //SHISHGL_TIMER_HPP
/*============================================================================*/
