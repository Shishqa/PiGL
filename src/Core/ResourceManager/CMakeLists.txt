add_library(ShishGL-ResourceManager)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/ResourceManager/)

target_include_directories(ShishGL-ResourceManager
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-ResourceManager
  PUBLIC
    ${INCROOT}/ResourceManager.hpp
  PRIVATE
    ResourceManager.cpp
  )

target_compile_features(ShishGL-ResourceManager
  PUBLIC
    cxx_std_17
  )