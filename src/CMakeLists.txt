add_library(ShishGL INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL)

target_include_directories(ShishGL
  INTERFACE
    ${INCROOT})

target_link_libraries(ShishGL
  INTERFACE
    ShishGL-Core
    #ShishGL-DebugUtilities
    ShishGL-GUI
  )

add_subdirectory(Core)
#add_subdirectory(DebugUtilities)
add_subdirectory(GUI)