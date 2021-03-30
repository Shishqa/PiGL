cmake_minimum_required(VERSION 3.8)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(ShishGL
  VERSION 1.0
  DESCRIPTION "A simple modular cross-platform graphics library"
  LANGUAGES CXX)

option(USE_XORG "Use Xlib platform" OFF)
option(USE_SFML "Use SFML platform" ON)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  set(DEFAULT_BUILD_TYPE "Release")

  set(CMAKE_CXX_EXTENSIONS OFF)

  set(RELEASE_FLAGS " \
    -O3 \
    -Wno-unused-parameter \
    -msse4.2 \
  ")

  set(DEBUG_FLAGS " \
    -g \
    -O3 \
    -msse4.2 \
    -Wconversion \
    -Wlogical-op \
    -Wshift-overflow=2 \
		-Wduplicated-cond \
		-Wno-unused-parameter \
		-Wcast-qual -Wcast-align \
		-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC \
		-D_FORTIFY_SOURCE=2 -fsanitize=address \
		-fsanitize=undefined -fno-sanitize-recover \
		-fstack-protector -Wno-format-nonliteral \
    -fno-omit-frame-pointer \
  ")

  set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${DEBUG_FLAGS}")
  set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} ${DEBUG_FLAGS}")

  set (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${RELEASE_FLAGS}")
  set (CMAKE_LINKER_FLAGS_RELEASE "${CMAKE_LINKER_FLAGS_RELEASE} ${RELEASE_FLAGS}")

  if (MSVC)
    add_compile_options(/W3 /WX)
  else()
    add_compile_options(-W -Wall -Wextra -Wpedantic)
  endif()

  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()

endif()

add_library(ShishGL INTERFACE)

set(INCROOT ${ShishGL_SOURCE_DIR}/include/ShishGL)

target_include_directories(ShishGL
  INTERFACE
  ${INCROOT})

target_link_libraries(ShishGL
  INTERFACE
  ShishGL-Core
  ShishGL-DebugUtilities
  ShishGL-GUI
  )

add_subdirectory(src/Core)
add_subdirectory(src/DebugUtilities)
add_subdirectory(src/GUI)

export(TARGETS
  ShishGL

  ShishGL-Core
  ShishGL-LogSystem
  ShishGL-EventSystem
  ShishGL-ResourceManager
  ShishGL-Primitives
  ShishGL-RenderSystem
  ShishGL-GraphicsPlatform
  ShishGL-PlatformInput
  ShishGL-PlatformEvents
  ShishGL-SfmlPlatform
  ShishGL-Window

  ShishGL-GUI
  ShishGL-UIWindow
  ShishGL-Behaviors
  ShishGL-Styles
  ShishGL-Shapes

  ShishGL-DebugUtilities

  FILE ShishGLTargets.cmake)

set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
export(PACKAGE ShishGL)

add_subdirectory(tests)

