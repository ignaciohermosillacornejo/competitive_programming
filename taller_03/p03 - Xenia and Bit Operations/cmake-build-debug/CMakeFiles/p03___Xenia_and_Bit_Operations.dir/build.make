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
CMAKE_SOURCE_DIR = "/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/p03___Xenia_and_Bit_Operations.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p03___Xenia_and_Bit_Operations.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p03___Xenia_and_Bit_Operations.dir/flags.make

CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o: CMakeFiles/p03___Xenia_and_Bit_Operations.dir/flags.make
CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o -c "/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations/main.cpp"

CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations/main.cpp" > CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.i

CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations/main.cpp" -o CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.s

CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o.requires

CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o.provides: CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/p03___Xenia_and_Bit_Operations.dir/build.make CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o.provides

CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o.provides.build: CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o


# Object files for target p03___Xenia_and_Bit_Operations
p03___Xenia_and_Bit_Operations_OBJECTS = \
"CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o"

# External object files for target p03___Xenia_and_Bit_Operations
p03___Xenia_and_Bit_Operations_EXTERNAL_OBJECTS =

p03___Xenia_and_Bit_Operations: CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o
p03___Xenia_and_Bit_Operations: CMakeFiles/p03___Xenia_and_Bit_Operations.dir/build.make
p03___Xenia_and_Bit_Operations: CMakeFiles/p03___Xenia_and_Bit_Operations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable p03___Xenia_and_Bit_Operations"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p03___Xenia_and_Bit_Operations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p03___Xenia_and_Bit_Operations.dir/build: p03___Xenia_and_Bit_Operations

.PHONY : CMakeFiles/p03___Xenia_and_Bit_Operations.dir/build

CMakeFiles/p03___Xenia_and_Bit_Operations.dir/requires: CMakeFiles/p03___Xenia_and_Bit_Operations.dir/main.cpp.o.requires

.PHONY : CMakeFiles/p03___Xenia_and_Bit_Operations.dir/requires

CMakeFiles/p03___Xenia_and_Bit_Operations.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p03___Xenia_and_Bit_Operations.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p03___Xenia_and_Bit_Operations.dir/clean

CMakeFiles/p03___Xenia_and_Bit_Operations.dir/depend:
	cd "/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations" "/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations" "/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations/cmake-build-debug" "/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations/cmake-build-debug" "/home/ignacio/dev/taller/taller_03/p03 - Xenia and Bit Operations/cmake-build-debug/CMakeFiles/p03___Xenia_and_Bit_Operations.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/p03___Xenia_and_Bit_Operations.dir/depend

