add_library(ShishGL-EventSystem)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/EventSystem)

target_include_directories(ShishGL-EventSystem
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-EventSystem
  PUBLIC
    ${INCROOT}/Event.hpp
    ${INCROOT}/EventManager.hpp
    ${INCROOT}/Listener.hpp
    ${INCROOT}/SubscriptionManager.hpp
    ${INCROOT}/EventSystem.hpp
  PRIVATE
    ${INCROOT}/EventSystem.ipp
    ${INCROOT}/EventManager.ipp
    Event.cpp
    EventManager.cpp
    Listener.cpp
    SubscriptionManager.cpp
    EventSystem.cpp
  )

target_link_libraries(ShishGL-EventSystem
  PUBLIC
    ShishGL-LogSystem
    ShishGL-Primitives
  )
