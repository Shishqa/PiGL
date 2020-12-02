add_library(ShishGL-Behaviors)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI/UIWindow/Behaviors)

target_include_directories(ShishGL-Behaviors
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-Behaviors
  PUBLIC
    ${INCROOT}/DefaultBehavior.hpp
    ${INCROOT}/Dialog.hpp
    ${INCROOT}/Clickable.hpp
    ${INCROOT}/Draggable.hpp
    ${INCROOT}/Slidable.hpp
  PRIVATE
    DefaultBehavior.cpp
    Clickable.cpp
    Draggable.cpp
    Slidable.cpp
  )

target_link_libraries(ShishGL-Behaviors
  PUBLIC
    ShishGL-Core
    ShishGL-UIWindow
  )


