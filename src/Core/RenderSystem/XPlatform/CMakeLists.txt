add_library(ShishGL-XPlatform)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/RenderSystem/XPlatform)

target_include_directories(ShishGL-XPlatform
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-XPlatform
  PUBLIC
    ${INCROOT}/Platform.hpp
  PRIVATE
    Platform.cpp
  )

target_link_libraries(ShishGL-XPlatform
  PUBLIC
    ShishGL-GraphicsPlatform
  )