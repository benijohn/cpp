# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket/build

# Include any dependencies generated for this target.
include CMakeFiles/simpleRocket.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simpleRocket.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simpleRocket.dir/flags.make

CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o: CMakeFiles/simpleRocket.dir/flags.make
CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o: ../simpleRocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o -c /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket/simpleRocket.cpp

CMakeFiles/simpleRocket.dir/simpleRocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simpleRocket.dir/simpleRocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket/simpleRocket.cpp > CMakeFiles/simpleRocket.dir/simpleRocket.cpp.i

CMakeFiles/simpleRocket.dir/simpleRocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simpleRocket.dir/simpleRocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket/simpleRocket.cpp -o CMakeFiles/simpleRocket.dir/simpleRocket.cpp.s

CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o.requires:

.PHONY : CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o.requires

CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o.provides: CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/simpleRocket.dir/build.make CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o.provides.build
.PHONY : CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o.provides

CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o.provides.build: CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o


# Object files for target simpleRocket
simpleRocket_OBJECTS = \
"CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o"

# External object files for target simpleRocket
simpleRocket_EXTERNAL_OBJECTS =

../simpleRocket: CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o
../simpleRocket: CMakeFiles/simpleRocket.dir/build.make
../simpleRocket: /home/benjamin/workspace/libraries/ACADOtoolkit/build/lib/libacado_toolkit_s.so
../simpleRocket: CMakeFiles/simpleRocket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../simpleRocket"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simpleRocket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simpleRocket.dir/build: ../simpleRocket

.PHONY : CMakeFiles/simpleRocket.dir/build

CMakeFiles/simpleRocket.dir/requires: CMakeFiles/simpleRocket.dir/simpleRocket.cpp.o.requires

.PHONY : CMakeFiles/simpleRocket.dir/requires

CMakeFiles/simpleRocket.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simpleRocket.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simpleRocket.dir/clean

CMakeFiles/simpleRocket.dir/depend:
	cd /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket/build /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket/build /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/simpleRocket/build/CMakeFiles/simpleRocket.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simpleRocket.dir/depend

