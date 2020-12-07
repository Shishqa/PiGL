add_library(ShishGL-DebugUtilities)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/DebugUtilities)

target_include_directories(ShishGL-DebugUtilities
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-DebugUtilities
  PUBLIC
    ${INCROOT}/FpsLabel.hpp
    ${INCROOT}/GradeCanvas.hpp
  PRIVATE
    FpsLabel.cpp
  )

target_link_libraries(ShishGL-DebugUtilities
  PUBLIC
    ShishGL-GUI
  )
