# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/TestAbstracts.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/TestAbstracts.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/TestAbstracts.dir/flags.make

tests/CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.o: tests/CMakeFiles/TestAbstracts.dir/flags.make
tests/CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.o: ../tests/TestAbstracts.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.o"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.o -c /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/tests/TestAbstracts.cpp

tests/CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.i"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/tests/TestAbstracts.cpp > CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.i

tests/CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.s"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/tests/TestAbstracts.cpp -o CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.s

# Object files for target TestAbstracts
TestAbstracts_OBJECTS = \
"CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.o"

# External object files for target TestAbstracts
TestAbstracts_EXTERNAL_OBJECTS =

tests/TestAbstracts: tests/CMakeFiles/TestAbstracts.dir/TestAbstracts.cpp.o
tests/TestAbstracts: tests/CMakeFiles/TestAbstracts.dir/build.make
tests/TestAbstracts: src/DebugUtilities/libShishGL-DebugUtilities.a
tests/TestAbstracts: src/GUI/libShishGL-GUI.a
tests/TestAbstracts: src/GUI/UIWindow/Behaviors/libShishGL-Behaviors.a
tests/TestAbstracts: src/GUI/UIWindow/libShishGL-UIWindow.a
tests/TestAbstracts: src/GUI/UIWindow/Shapes/libShishGL-Shapes.a
tests/TestAbstracts: src/Core/libShishGL-Core.a
tests/TestAbstracts: src/Core/Window/libShishGL-Window.a
tests/TestAbstracts: src/Core/RenderSystem/libShishGL-RenderSystem.a
tests/TestAbstracts: src/Core/RenderSystem/SfmlPlatform/libShishGL-SfmlPlatform.a
tests/TestAbstracts: src/Core/RenderSystem/GraphicsPlatform/libShishGL-GraphicsPlatform.a
tests/TestAbstracts: src/Core/ResourceManager/libShishGL-ResourceManager.a
tests/TestAbstracts: src/Core/RenderSystem/GraphicsPlatform/Events/libShishGL-PlatformEvents.a
tests/TestAbstracts: src/Core/EventSystem/libShishGL-EventSystem.a
tests/TestAbstracts: src/Core/LogSystem/libShishGL-LogSystem.a
tests/TestAbstracts: src/Core/Primitives/libShishGL-Primitives.a
tests/TestAbstracts: src/Core/RenderSystem/GraphicsPlatform/Input/libShishGL-PlatformInput.a
tests/TestAbstracts: /usr/lib/libsfml-graphics.so.2.5.1
tests/TestAbstracts: /usr/lib/libsfml-window.so.2.5.1
tests/TestAbstracts: /usr/lib/libsfml-system.so.2.5.1
tests/TestAbstracts: tests/CMakeFiles/TestAbstracts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestAbstracts"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestAbstracts.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/TestAbstracts.dir/build: tests/TestAbstracts

.PHONY : tests/CMakeFiles/TestAbstracts.dir/build

tests/CMakeFiles/TestAbstracts.dir/clean:
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/TestAbstracts.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/TestAbstracts.dir/clean

tests/CMakeFiles/TestAbstracts.dir/depend:
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/tests /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/tests /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/tests/CMakeFiles/TestAbstracts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/TestAbstracts.dir/depend

