# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build

# Include any dependencies generated for this target.
include src/CMakeFiles/OGLSimpleEngine.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/OGLSimpleEngine.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/OGLSimpleEngine.dir/flags.make

src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o: src/CMakeFiles/OGLSimpleEngine.dir/flags.make
src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/OGLSimpleEngine.dir/main.cpp.o -c /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/main.cpp

src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OGLSimpleEngine.dir/main.cpp.i"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/main.cpp > CMakeFiles/OGLSimpleEngine.dir/main.cpp.i

src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OGLSimpleEngine.dir/main.cpp.s"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/main.cpp -o CMakeFiles/OGLSimpleEngine.dir/main.cpp.s

src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o.requires:
.PHONY : src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o.requires

src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o.provides: src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/OGLSimpleEngine.dir/build.make src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o.provides

src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o.provides.build: src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o

# Object files for target OGLSimpleEngine
OGLSimpleEngine_OBJECTS = \
"CMakeFiles/OGLSimpleEngine.dir/main.cpp.o"

# External object files for target OGLSimpleEngine
OGLSimpleEngine_EXTERNAL_OBJECTS =

src/OGLSimpleEngine: src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o
src/OGLSimpleEngine: src/CMakeFiles/OGLSimpleEngine.dir/build.make
src/OGLSimpleEngine: /usr/lib/x86_64-linux-gnu/libGLU.so
src/OGLSimpleEngine: /usr/lib/x86_64-linux-gnu/libGL.so
src/OGLSimpleEngine: /usr/lib/x86_64-linux-gnu/libGLEW.so
src/OGLSimpleEngine: src/util/libutil.a
src/OGLSimpleEngine: src/graphics/libgraphics.a
src/OGLSimpleEngine: /usr/lib/x86_64-linux-gnu/libGLU.so
src/OGLSimpleEngine: /usr/lib/x86_64-linux-gnu/libGL.so
src/OGLSimpleEngine: /usr/lib/x86_64-linux-gnu/libGLEW.so
src/OGLSimpleEngine: src/CMakeFiles/OGLSimpleEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable OGLSimpleEngine"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OGLSimpleEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/OGLSimpleEngine.dir/build: src/OGLSimpleEngine
.PHONY : src/CMakeFiles/OGLSimpleEngine.dir/build

src/CMakeFiles/OGLSimpleEngine.dir/requires: src/CMakeFiles/OGLSimpleEngine.dir/main.cpp.o.requires
.PHONY : src/CMakeFiles/OGLSimpleEngine.dir/requires

src/CMakeFiles/OGLSimpleEngine.dir/clean:
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src && $(CMAKE_COMMAND) -P CMakeFiles/OGLSimpleEngine.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/OGLSimpleEngine.dir/clean

src/CMakeFiles/OGLSimpleEngine.dir/depend:
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/CMakeFiles/OGLSimpleEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/OGLSimpleEngine.dir/depend
