add_library(ShishGL-GUI)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL/GUI)

target_include_directories(ShishGL-GUI
  PUBLIC
    ${INCROOT}
  )

target_sources(ShishGL-GUI
  PUBLIC
    ${INCROOT}/GUI.hpp
    ${INCROOT}/UITriggers.hpp
    ${INCROOT}/UISlider.hpp

    #${INCROOT}/UILabel.hpp
    #${INCROOT}/UIButton.hpp
    #${INCROOT}/UICheckbox.hpp
    #${INCROOT}/UICanvas.hpp
    #${INCROOT}/UIScrollbar.hpp
    #${INCROOT}/UIFrame.hpp
    #${INCROOT}/UISlider2D.hpp
    #${INCROOT}/UITextInput.hpp
    #${INCROOT}/UIDialog.hpp
    #${INCROOT}/UIFileDialog.hpp
  PRIVATE
    ${INCROOT}/UISlider.ipp
    UICanvas.cpp
    UIScrollbar.cpp
    UIFrame.cpp
    UITextInput.cpp
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
