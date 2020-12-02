add_library(ShishGL-PlatformInput)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/RenderSystem/GraphicsPlatform/Input)

target_include_directories(ShishGL-PlatformInput
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-PlatformInput
  PUBLIC
    ${INCROOT}/Mouse.hpp
    ${INCROOT}/Keyboard.hpp
  PRIVATE
    Keyboard.cpp
  )

target_compile_features(ShishGL-PlatformInput
  PUBLIC
    cxx_std_17
  )
