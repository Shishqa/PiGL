add_library(ShishGL-GUI)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI)

target_include_directories(ShishGL-GUI
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-GUI
  PUBLIC
    ${INCROOT}/GUI.hpp
    ${INCROOT}/UIDialog.hpp
    ${INCROOT}/UILabel.hpp
    ${INCROOT}/UICanvas.hpp
    ${INCROOT}/UIButton.hpp
    ${INCROOT}/UISwitch.hpp
    ${INCROOT}/UISlider.hpp
    ${INCROOT}/UIScrollbar.hpp
    ${INCROOT}/UIFrame.hpp
    ${INCROOT}/UISelectList.hpp
    ${INCROOT}/UITextInput.hpp
    ${INCROOT}/UIFileSelector.hpp
  PRIVATE
    UICanvas.cpp
    UIFrame.cpp
    UITextInput.cpp
    UIDialog.cpp
  )

target_link_libraries(ShishGL-GUI
  PUBLIC
    ShishGL-Core
    ShishGL-UIWindow
    ShishGL-Styles
    ShishGL-Shapes
    ShishGL-Behaviors
  )

add_subdirectory(UIWindow)
