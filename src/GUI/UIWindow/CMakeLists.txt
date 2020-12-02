add_library(ShishGL-UIWindow)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI/UIWindow)

target_include_directories(ShishGL-UIWindow
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-UIWindow
  PUBLIC
    ${INCROOT}/Style.hpp
    ${INCROOT}/Behavior.hpp
    ${INCROOT}/BehaviorManager.hpp
    ${INCROOT}/UIWindow.hpp
    ${INCROOT}/UIWindow.ipp
  PRIVATE
    UIWindow.cpp
  )

target_link_libraries(ShishGL-UIWindow
  PUBLIC
    ShishGL-Window
    ShishGL-Shapes
  )

add_subdirectory(Shapes)
add_subdirectory(Styles)
add_subdirectory(Behaviors)
