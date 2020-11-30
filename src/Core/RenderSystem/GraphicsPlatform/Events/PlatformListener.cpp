/*============================================================================*/
#include "PlatformListener.hpp"
#include "EventSystem.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool PlatformListener::onMouseMove(class MouseEvent&) { return false; }
bool PlatformListener::onMouseButton(class MouseButtonEvent&) { return false; }
bool PlatformListener::onMouseScroll(class MouseScrollEvent&) { return false; }
bool PlatformListener::onKeyboard(class KeyboardEvent&) { return false; }
bool PlatformListener::onTimer(class TimerEvent&) { return false; }

/*============================================================================*/
