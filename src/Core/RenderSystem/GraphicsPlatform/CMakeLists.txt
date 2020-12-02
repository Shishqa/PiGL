add_library(ShishGL-GraphicsPlatform INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/RenderSystem/GraphicsPlatform)

target_include_directories(ShishGL-GraphicsPlatform
  INTERFACE
    ${INCROOT})

target_sources(ShishGL-GraphicsPlatform
  INTERFACE
    ${INCROOT}/IPlatform.hpp
  )

target_link_libraries(ShishGL-GraphicsPlatform
  INTERFACE
    ShishGL-Primitives
    ShishGL-LogSystem
    ShishGL-ResourceManager
    ShishGL-PlatformEvents
    ShishGL-PlatformInput
  )

target_compile_features(ShishGL-GraphicsPlatform
  INTERFACE
    cxx_std_17
  )

add_subdirectory(Events)
add_subdirectory(Input)


export(TARGETS ShishGL-GraphicsPlatform
  FILE ShishGL-GraphicsPlatform-Targets.cmake)

