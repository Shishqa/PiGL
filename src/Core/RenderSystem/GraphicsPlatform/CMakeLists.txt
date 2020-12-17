add_library(ShishGL-GraphicsPlatform)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/RenderSystem/GraphicsPlatform)

target_include_directories(ShishGL-GraphicsPlatform
  PUBLIC
    ${INCROOT})

target_sources(ShishGL-GraphicsPlatform
  PUBLIC
    ${INCROOT}/IPlatform.hpp
    ${INCROOT}/Image.hpp
  PRIVATE
    Image.cpp
  )

target_link_libraries(ShishGL-GraphicsPlatform
  PUBLIC
    ShishGL-Primitives
    ShishGL-LogSystem
    ShishGL-ResourceManager
    ShishGL-PlatformEvents
    ShishGL-PlatformInput
  )

target_compile_features(ShishGL-GraphicsPlatform
  PUBLIC
    cxx_std_17
  )

add_subdirectory(Events)
add_subdirectory(Input)


export(TARGETS ShishGL-GraphicsPlatform
  FILE ShishGL-GraphicsPlatform-Targets.cmake)

