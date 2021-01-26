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
include src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/depend.make

# Include the progress variables for this target.
include src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/progress.make

# Include the compile flags for this target's objects.
include src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/flags.make

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.o: src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/flags.make
src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.o: ../src/Core/RenderSystem/GraphicsPlatform/Events/PlatformListener.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.o"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.o -c /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/PlatformListener.cpp

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.i"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/PlatformListener.cpp > CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.i

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.s"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/PlatformListener.cpp -o CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.s

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.o: src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/flags.make
src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.o: ../src/Core/RenderSystem/GraphicsPlatform/Events/KeyboardEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.o"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.o -c /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/KeyboardEvent.cpp

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.i"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/KeyboardEvent.cpp > CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.i

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.s"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/KeyboardEvent.cpp -o CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.s

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.o: src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/flags.make
src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.o: ../src/Core/RenderSystem/GraphicsPlatform/Events/MouseEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.o"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.o -c /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/MouseEvent.cpp

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.i"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/MouseEvent.cpp > CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.i

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.s"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/MouseEvent.cpp -o CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.s

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.o: src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/flags.make
src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.o: ../src/Core/RenderSystem/GraphicsPlatform/Events/TimerEvent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.o"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.o -c /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/TimerEvent.cpp

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.i"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/TimerEvent.cpp > CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.i

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.s"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events/TimerEvent.cpp -o CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.s

# Object files for target ShishGL-PlatformEvents
ShishGL__PlatformEvents_OBJECTS = \
"CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.o" \
"CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.o" \
"CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.o" \
"CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.o"

# External object files for target ShishGL-PlatformEvents
ShishGL__PlatformEvents_EXTERNAL_OBJECTS =

src/Core/RenderSystem/GraphicsPlatform/Events/libShishGL-PlatformEvents.a: src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/PlatformListener.cpp.o
src/Core/RenderSystem/GraphicsPlatform/Events/libShishGL-PlatformEvents.a: src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/KeyboardEvent.cpp.o
src/Core/RenderSystem/GraphicsPlatform/Events/libShishGL-PlatformEvents.a: src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/MouseEvent.cpp.o
src/Core/RenderSystem/GraphicsPlatform/Events/libShishGL-PlatformEvents.a: src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/TimerEvent.cpp.o
src/Core/RenderSystem/GraphicsPlatform/Events/libShishGL-PlatformEvents.a: src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/build.make
src/Core/RenderSystem/GraphicsPlatform/Events/libShishGL-PlatformEvents.a: src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libShishGL-PlatformEvents.a"
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && $(CMAKE_COMMAND) -P CMakeFiles/ShishGL-PlatformEvents.dir/cmake_clean_target.cmake
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ShishGL-PlatformEvents.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/build: src/Core/RenderSystem/GraphicsPlatform/Events/libShishGL-PlatformEvents.a

.PHONY : src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/build

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/clean:
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events && $(CMAKE_COMMAND) -P CMakeFiles/ShishGL-PlatformEvents.dir/cmake_clean.cmake
.PHONY : src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/clean

src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/depend:
	cd /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/src/Core/RenderSystem/GraphicsPlatform/Events /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events /mnt/WorkDisk/Dev/MIPT/2020_3/00_ShishGL/Debug/src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Core/RenderSystem/GraphicsPlatform/Events/CMakeFiles/ShishGL-PlatformEvents.dir/depend

