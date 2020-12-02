add_library(ShishGL-Styles INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI/UIWindow/Styles)

target_include_directories(ShishGL-Styles
  INTERFACE
    ${INCROOT}
  )

target_sources(ShishGL-Styles
  INTERFACE
    ${INCROOT}/ColorFill.hpp
    ${INCROOT}/TextureFill.hpp
    ${INCROOT}/Bordered.hpp
    ${INCROOT}/Font.hpp
    ${INCROOT}/FontSize.hpp
  )

target_link_libraries(ShishGL-Styles
  INTERFACE
    ShishGL-Core
    ShishGL-Shapes
  )