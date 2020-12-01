add_library(ShishGL-Primitives)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/Core/Primitives)

target_include_directories(ShishGL-Primitives
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Primitives
  PUBLIC
    ${INCROOT}/Frame.hpp
    ${INCROOT}/Vector2.hpp
    ${INCROOT}/Segment2.hpp
    ${INCROOT}/Color.hpp
    ${INCROOT}/Time.hpp
    ${INCROOT}/Vector3.hpp
  PRIVATE
    ${INCROOT}/Vector2.ipp
    Color.cpp
    Vector2.cpp
    Vector3.cpp
    Time.cpp
    Frame.cpp
  )

target_compile_features(ShishGL-Primitives
  PUBLIC
    cxx_std_17
  )