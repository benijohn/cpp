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
CMAKE_SOURCE_DIR = /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/build

# Include any dependencies generated for this target.
include CMakeFiles/quarterCar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/quarterCar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quarterCar.dir/flags.make

CMakeFiles/quarterCar.dir/quarterCar.cpp.o: CMakeFiles/quarterCar.dir/flags.make
CMakeFiles/quarterCar.dir/quarterCar.cpp.o: ../quarterCar.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/quarterCar.dir/quarterCar.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quarterCar.dir/quarterCar.cpp.o -c /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/quarterCar.cpp

CMakeFiles/quarterCar.dir/quarterCar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quarterCar.dir/quarterCar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/quarterCar.cpp > CMakeFiles/quarterCar.dir/quarterCar.cpp.i

CMakeFiles/quarterCar.dir/quarterCar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quarterCar.dir/quarterCar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/quarterCar.cpp -o CMakeFiles/quarterCar.dir/quarterCar.cpp.s

CMakeFiles/quarterCar.dir/quarterCar.cpp.o.requires:

.PHONY : CMakeFiles/quarterCar.dir/quarterCar.cpp.o.requires

CMakeFiles/quarterCar.dir/quarterCar.cpp.o.provides: CMakeFiles/quarterCar.dir/quarterCar.cpp.o.requires
	$(MAKE) -f CMakeFiles/quarterCar.dir/build.make CMakeFiles/quarterCar.dir/quarterCar.cpp.o.provides.build
.PHONY : CMakeFiles/quarterCar.dir/quarterCar.cpp.o.provides

CMakeFiles/quarterCar.dir/quarterCar.cpp.o.provides.build: CMakeFiles/quarterCar.dir/quarterCar.cpp.o


# Object files for target quarterCar
quarterCar_OBJECTS = \
"CMakeFiles/quarterCar.dir/quarterCar.cpp.o"

# External object files for target quarterCar
quarterCar_EXTERNAL_OBJECTS =

../quarterCar: CMakeFiles/quarterCar.dir/quarterCar.cpp.o
../quarterCar: CMakeFiles/quarterCar.dir/build.make
../quarterCar: /home/benjamin/workspace/libraries/ACADOtoolkit/build/lib/libacado_toolkit_s.so
../quarterCar: CMakeFiles/quarterCar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../quarterCar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quarterCar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quarterCar.dir/build: ../quarterCar

.PHONY : CMakeFiles/quarterCar.dir/build

CMakeFiles/quarterCar.dir/requires: CMakeFiles/quarterCar.dir/quarterCar.cpp.o.requires

.PHONY : CMakeFiles/quarterCar.dir/requires

CMakeFiles/quarterCar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quarterCar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quarterCar.dir/clean

CMakeFiles/quarterCar.dir/depend:
	cd /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/build /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/build /home/benjamin/workspace/projects/cpp/cppProjects/acadoExamples/build/CMakeFiles/quarterCar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/quarterCar.dir/depend

