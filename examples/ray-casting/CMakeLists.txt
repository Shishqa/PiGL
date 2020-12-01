
add_executable(example-ray-casting)

set(INCROOT ${PROJECT_SOURCE_DIR}/examples/ray-casting/include/ray-casting)

target_include_directories(example-ray-casting
  PUBLIC
    ${INCROOT}
  )

target_sources(example-ray-casting
  PUBLIC
    ${INCROOT}/SphereCast.hpp
  PRIVATE
    src/main.cpp
    src/SphereCast.cpp
  )

target_link_libraries(example-ray-casting
  PUBLIC
    ShishGL
  )

add_subdirectory(src)