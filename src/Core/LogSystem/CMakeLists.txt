add_library(ShishGL-LogSystem)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/LogSystem)

target_include_directories(ShishGL-LogSystem
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-LogSystem
  PUBLIC
    ${INCROOT}/LogSystem.hpp
  PRIVATE
    LogSystem.cpp
  )

target_link_libraries(ShishGL-LogSystem
  PUBLIC
    ShishGL-Primitives
  )

