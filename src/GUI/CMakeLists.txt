add_library(ShishGL-GUI)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI)

target_include_directories(ShishGL-GUI
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-GUI
  PUBLIC
    ${INCROOT}/UICanvas.hpp
    ${INCROOT}/UIScrollbar.hpp
    #${INCROOT}/UIFrame.hpp
  PRIVATE
    UICanvas.cpp
    UIScrollbar.cpp
  )

target_link_libraries(ShishGL-GUI
  PUBLIC
    ShishGL-Core
    ShishGL-UIWindow
    ShishGL-Styles
    ShishGL-Shapes
    ShishGL-Behaviors
    ShishGL-TextBuffer
  )

add_subdirectory(UIWindow)
add_subdirectory(TextBuffer)
