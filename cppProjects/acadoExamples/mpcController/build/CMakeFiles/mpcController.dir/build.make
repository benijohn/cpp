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
CMAKE_SOURCE_DIR = /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController/build

# Include any dependencies generated for this target.
include CMakeFiles/mpcController.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mpcController.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mpcController.dir/flags.make

CMakeFiles/mpcController.dir/mpcController.cpp.o: CMakeFiles/mpcController.dir/flags.make
CMakeFiles/mpcController.dir/mpcController.cpp.o: ../mpcController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mpcController.dir/mpcController.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mpcController.dir/mpcController.cpp.o -c /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController/mpcController.cpp

CMakeFiles/mpcController.dir/mpcController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mpcController.dir/mpcController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController/mpcController.cpp > CMakeFiles/mpcController.dir/mpcController.cpp.i

CMakeFiles/mpcController.dir/mpcController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mpcController.dir/mpcController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController/mpcController.cpp -o CMakeFiles/mpcController.dir/mpcController.cpp.s

CMakeFiles/mpcController.dir/mpcController.cpp.o.requires:

.PHONY : CMakeFiles/mpcController.dir/mpcController.cpp.o.requires

CMakeFiles/mpcController.dir/mpcController.cpp.o.provides: CMakeFiles/mpcController.dir/mpcController.cpp.o.requires
	$(MAKE) -f CMakeFiles/mpcController.dir/build.make CMakeFiles/mpcController.dir/mpcController.cpp.o.provides.build
.PHONY : CMakeFiles/mpcController.dir/mpcController.cpp.o.provides

CMakeFiles/mpcController.dir/mpcController.cpp.o.provides.build: CMakeFiles/mpcController.dir/mpcController.cpp.o


# Object files for target mpcController
mpcController_OBJECTS = \
"CMakeFiles/mpcController.dir/mpcController.cpp.o"

# External object files for target mpcController
mpcController_EXTERNAL_OBJECTS =

../mpcController: CMakeFiles/mpcController.dir/mpcController.cpp.o
../mpcController: CMakeFiles/mpcController.dir/build.make
../mpcController: /home/benjamin/workspace/libraries/ACADOtoolkit/build/lib/libacado_toolkit_s.so
../mpcController: /home/benjamin/workspace/libraries/ACADOtoolkit/build/lib/libacado_casadi.a
../mpcController: /home/benjamin/workspace/libraries/ACADOtoolkit/build/lib/libacado_csparse.a
../mpcController: CMakeFiles/mpcController.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../mpcController"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mpcController.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mpcController.dir/build: ../mpcController

.PHONY : CMakeFiles/mpcController.dir/build

CMakeFiles/mpcController.dir/requires: CMakeFiles/mpcController.dir/mpcController.cpp.o.requires

.PHONY : CMakeFiles/mpcController.dir/requires

CMakeFiles/mpcController.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mpcController.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mpcController.dir/clean

CMakeFiles/mpcController.dir/depend:
	cd /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController/build /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController/build /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/mpcController/build/CMakeFiles/mpcController.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mpcController.dir/depend
