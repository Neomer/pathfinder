# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/kir/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7479.33/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kir/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7479.33/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kir/projects/pathfinder/game_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kir/projects/pathfinder/game_server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/game_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game_server.dir/flags.make

CMakeFiles/game_server.dir/main.cpp.o: CMakeFiles/game_server.dir/flags.make
CMakeFiles/game_server.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kir/projects/pathfinder/game_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game_server.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game_server.dir/main.cpp.o -c /home/kir/projects/pathfinder/game_server/main.cpp

CMakeFiles/game_server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_server.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kir/projects/pathfinder/game_server/main.cpp > CMakeFiles/game_server.dir/main.cpp.i

CMakeFiles/game_server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_server.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kir/projects/pathfinder/game_server/main.cpp -o CMakeFiles/game_server.dir/main.cpp.s

# Object files for target game_server
game_server_OBJECTS = \
"CMakeFiles/game_server.dir/main.cpp.o"

# External object files for target game_server
game_server_EXTERNAL_OBJECTS =

game_server: CMakeFiles/game_server.dir/main.cpp.o
game_server: CMakeFiles/game_server.dir/build.make
game_server: CMakeFiles/game_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kir/projects/pathfinder/game_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable game_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game_server.dir/build: game_server

.PHONY : CMakeFiles/game_server.dir/build

CMakeFiles/game_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game_server.dir/clean

CMakeFiles/game_server.dir/depend:
	cd /home/kir/projects/pathfinder/game_server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kir/projects/pathfinder/game_server /home/kir/projects/pathfinder/game_server /home/kir/projects/pathfinder/game_server/cmake-build-debug /home/kir/projects/pathfinder/game_server/cmake-build-debug /home/kir/projects/pathfinder/game_server/cmake-build-debug/CMakeFiles/game_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game_server.dir/depend

