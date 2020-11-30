/*============================================================================*/
#include "TimerEvent.hpp"
#include "PlatformListener.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

TimerEvent::TimerEvent(const TimeDelta &delta)
        : time_delta(delta) { }

/*----------------------------------------------------------------------------*/

const TimeDelta& TimerEvent::delta() const {
    return time_delta;
}

/*----------------------------------------------------------------------------*/

bool TimerEvent::happen(Listener* listener) {
    return dynamic_cast<PlatformListener*>(listener)->onTimer(*this);
}

/*============================================================================*/
