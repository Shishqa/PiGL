add_library(ShishGL-TextBuffer)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI/TextBuffer)

target_include_directories(ShishGL-TextBuffer
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-TextBuffer
  PUBLIC
    ${INCROOT}/Text.hpp
    ${INCROOT}/TextBuffer.hpp
  PRIVATE
    Text.cpp
    TextBuffer.cpp
  )

target_link_libraries(ShishGL-TextBuffer
  PUBLIC
    ShishGL-Core
  )