# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/ignacio/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/ignacio/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.3544.40/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ignacio/CLionProjects/fenwik

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ignacio/CLionProjects/fenwik/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fenwik.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fenwik.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fenwik.dir/flags.make

CMakeFiles/fenwik.dir/main.cpp.o: CMakeFiles/fenwik.dir/flags.make
CMakeFiles/fenwik.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ignacio/CLionProjects/fenwik/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fenwik.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fenwik.dir/main.cpp.o -c /home/ignacio/CLionProjects/fenwik/main.cpp

CMakeFiles/fenwik.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fenwik.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ignacio/CLionProjects/fenwik/main.cpp > CMakeFiles/fenwik.dir/main.cpp.i

CMakeFiles/fenwik.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fenwik.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ignacio/CLionProjects/fenwik/main.cpp -o CMakeFiles/fenwik.dir/main.cpp.s

CMakeFiles/fenwik.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/fenwik.dir/main.cpp.o.requires

CMakeFiles/fenwik.dir/main.cpp.o.provides: CMakeFiles/fenwik.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/fenwik.dir/build.make CMakeFiles/fenwik.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/fenwik.dir/main.cpp.o.provides

CMakeFiles/fenwik.dir/main.cpp.o.provides.build: CMakeFiles/fenwik.dir/main.cpp.o


# Object files for target fenwik
fenwik_OBJECTS = \
"CMakeFiles/fenwik.dir/main.cpp.o"

# External object files for target fenwik
fenwik_EXTERNAL_OBJECTS =

fenwik: CMakeFiles/fenwik.dir/main.cpp.o
fenwik: CMakeFiles/fenwik.dir/build.make
fenwik: CMakeFiles/fenwik.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ignacio/CLionProjects/fenwik/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fenwik"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fenwik.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fenwik.dir/build: fenwik

.PHONY : CMakeFiles/fenwik.dir/build

CMakeFiles/fenwik.dir/requires: CMakeFiles/fenwik.dir/main.cpp.o.requires

.PHONY : CMakeFiles/fenwik.dir/requires

CMakeFiles/fenwik.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fenwik.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fenwik.dir/clean

CMakeFiles/fenwik.dir/depend:
	cd /home/ignacio/CLionProjects/fenwik/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ignacio/CLionProjects/fenwik /home/ignacio/CLionProjects/fenwik /home/ignacio/CLionProjects/fenwik/cmake-build-debug /home/ignacio/CLionProjects/fenwik/cmake-build-debug /home/ignacio/CLionProjects/fenwik/cmake-build-debug/CMakeFiles/fenwik.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fenwik.dir/depend
