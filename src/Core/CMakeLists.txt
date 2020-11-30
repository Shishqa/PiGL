add_library(ShishGL-Core)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core)
target_include_directories(ShishGL-Core
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Core
  PUBLIC
    ${INCROOT}/CoreApplication.hpp
  PRIVATE
    CoreApplication.cpp
  )

target_link_libraries(ShishGL-Core
  PUBLIC
    ShishGL-Primitives
    ShishGL-LogSystem
    ShishGL-ResourceManager
    ShishGL-EventSystem
    ShishGL-RenderSystem
    ShishGL-Window
  )

add_subdirectory(Primitives)
add_subdirectory(LogSystem)
add_subdirectory(EventSystem)
add_subdirectory(RenderSystem)
add_subdirectory(Window)
add_subdirectory(ResourceManager)