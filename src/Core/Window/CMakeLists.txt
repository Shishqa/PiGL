
add_library(ShishGL-Window)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Window)

target_include_directories(ShishGL-Window
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Window
  PUBLIC
    ${INCROOT}/Viewport.hpp
    ${INCROOT}/Window.hpp
    ${INCROOT}/WindowManager.hpp
  PRIVATE
    ${INCROOT}/Window.ipp
    ${INCROOT}/WindowManager.ipp
    Viewport.cpp
    Window.cpp
    WindowManager.cpp
  )

target_link_libraries(ShishGL-Window
  PUBLIC
    ShishGL-LogSystem
    ShishGL-RenderSystem
  )
