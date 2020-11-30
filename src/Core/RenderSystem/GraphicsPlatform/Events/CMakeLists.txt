add_library(ShishGL-PlatformEvents)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/RenderSystem/GraphicsPlatform/Events)

target_include_directories(ShishGL-PlatformEvents
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-PlatformEvents
  PUBLIC
    ${INCROOT}/PlatformListener.hpp
    ${INCROOT}/KeyboardEvent.hpp
    ${INCROOT}/MouseEvent.hpp
    ${INCROOT}/TimerEvent.hpp
  PRIVATE
    PlatformListener.cpp
    KeyboardEvent.cpp
    MouseEvent.cpp
    TimerEvent.cpp
  )

target_link_libraries(ShishGL-PlatformEvents
  PUBLIC
    ShishGL-EventSystem
    ShishGL-PlatformInput
  )

target_compile_features(ShishGL-PlatformEvents
  PUBLIC
    cxx_std_17
  )