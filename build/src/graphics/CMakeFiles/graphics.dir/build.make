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
include src/graphics/CMakeFiles/graphics.dir/depend.make

# Include the progress variables for this target.
include src/graphics/CMakeFiles/graphics.dir/progress.make

# Include the compile flags for this target's objects.
include src/graphics/CMakeFiles/graphics.dir/flags.make

src/graphics/CMakeFiles/graphics.dir/Window.cpp.o: src/graphics/CMakeFiles/graphics.dir/flags.make
src/graphics/CMakeFiles/graphics.dir/Window.cpp.o: ../src/graphics/Window.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/graphics/CMakeFiles/graphics.dir/Window.cpp.o"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/Window.cpp.o -c /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Window.cpp

src/graphics/CMakeFiles/graphics.dir/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/Window.cpp.i"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Window.cpp > CMakeFiles/graphics.dir/Window.cpp.i

src/graphics/CMakeFiles/graphics.dir/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/Window.cpp.s"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Window.cpp -o CMakeFiles/graphics.dir/Window.cpp.s

src/graphics/CMakeFiles/graphics.dir/Window.cpp.o.requires:
.PHONY : src/graphics/CMakeFiles/graphics.dir/Window.cpp.o.requires

src/graphics/CMakeFiles/graphics.dir/Window.cpp.o.provides: src/graphics/CMakeFiles/graphics.dir/Window.cpp.o.requires
	$(MAKE) -f src/graphics/CMakeFiles/graphics.dir/build.make src/graphics/CMakeFiles/graphics.dir/Window.cpp.o.provides.build
.PHONY : src/graphics/CMakeFiles/graphics.dir/Window.cpp.o.provides

src/graphics/CMakeFiles/graphics.dir/Window.cpp.o.provides.build: src/graphics/CMakeFiles/graphics.dir/Window.cpp.o

src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o: src/graphics/CMakeFiles/graphics.dir/flags.make
src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o: ../src/graphics/Shader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/Shader.cpp.o -c /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Shader.cpp

src/graphics/CMakeFiles/graphics.dir/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/Shader.cpp.i"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Shader.cpp > CMakeFiles/graphics.dir/Shader.cpp.i

src/graphics/CMakeFiles/graphics.dir/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/Shader.cpp.s"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Shader.cpp -o CMakeFiles/graphics.dir/Shader.cpp.s

src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o.requires:
.PHONY : src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o.requires

src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o.provides: src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o.requires
	$(MAKE) -f src/graphics/CMakeFiles/graphics.dir/build.make src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o.provides.build
.PHONY : src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o.provides

src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o.provides.build: src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o

src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o: src/graphics/CMakeFiles/graphics.dir/flags.make
src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o: ../src/graphics/ShaderProgram.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/ShaderProgram.cpp.o -c /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/ShaderProgram.cpp

src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/ShaderProgram.cpp.i"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/ShaderProgram.cpp > CMakeFiles/graphics.dir/ShaderProgram.cpp.i

src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/ShaderProgram.cpp.s"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/ShaderProgram.cpp -o CMakeFiles/graphics.dir/ShaderProgram.cpp.s

src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o.requires:
.PHONY : src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o.requires

src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o.provides: src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o.requires
	$(MAKE) -f src/graphics/CMakeFiles/graphics.dir/build.make src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o.provides.build
.PHONY : src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o.provides

src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o.provides.build: src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o

src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o: src/graphics/CMakeFiles/graphics.dir/flags.make
src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o: ../src/graphics/Buffer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/Buffer.cpp.o -c /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Buffer.cpp

src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/Buffer.cpp.i"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Buffer.cpp > CMakeFiles/graphics.dir/Buffer.cpp.i

src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/Buffer.cpp.s"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Buffer.cpp -o CMakeFiles/graphics.dir/Buffer.cpp.s

src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o.requires:
.PHONY : src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o.requires

src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o.provides: src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o.requires
	$(MAKE) -f src/graphics/CMakeFiles/graphics.dir/build.make src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o.provides.build
.PHONY : src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o.provides

src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o.provides.build: src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o

src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o: src/graphics/CMakeFiles/graphics.dir/flags.make
src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o: ../src/graphics/VertexArray.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/VertexArray.cpp.o -c /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/VertexArray.cpp

src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/VertexArray.cpp.i"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/VertexArray.cpp > CMakeFiles/graphics.dir/VertexArray.cpp.i

src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/VertexArray.cpp.s"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/VertexArray.cpp -o CMakeFiles/graphics.dir/VertexArray.cpp.s

src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o.requires:
.PHONY : src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o.requires

src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o.provides: src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o.requires
	$(MAKE) -f src/graphics/CMakeFiles/graphics.dir/build.make src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o.provides.build
.PHONY : src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o.provides

src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o.provides.build: src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o

src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o: src/graphics/CMakeFiles/graphics.dir/flags.make
src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o: ../src/graphics/Renderable2D.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/Renderable2D.cpp.o -c /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Renderable2D.cpp

src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/Renderable2D.cpp.i"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Renderable2D.cpp > CMakeFiles/graphics.dir/Renderable2D.cpp.i

src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/Renderable2D.cpp.s"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/Renderable2D.cpp -o CMakeFiles/graphics.dir/Renderable2D.cpp.s

src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o.requires:
.PHONY : src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o.requires

src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o.provides: src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o.requires
	$(MAKE) -f src/graphics/CMakeFiles/graphics.dir/build.make src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o.provides.build
.PHONY : src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o.provides

src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o.provides.build: src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o

src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o: src/graphics/CMakeFiles/graphics.dir/flags.make
src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o: ../src/graphics/SimpleRenderer2D.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o -c /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/SimpleRenderer2D.cpp

src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.i"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/SimpleRenderer2D.cpp > CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.i

src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.s"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics/SimpleRenderer2D.cpp -o CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.s

src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o.requires:
.PHONY : src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o.requires

src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o.provides: src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o.requires
	$(MAKE) -f src/graphics/CMakeFiles/graphics.dir/build.make src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o.provides.build
.PHONY : src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o.provides

src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o.provides.build: src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o

# Object files for target graphics
graphics_OBJECTS = \
"CMakeFiles/graphics.dir/Window.cpp.o" \
"CMakeFiles/graphics.dir/Shader.cpp.o" \
"CMakeFiles/graphics.dir/ShaderProgram.cpp.o" \
"CMakeFiles/graphics.dir/Buffer.cpp.o" \
"CMakeFiles/graphics.dir/VertexArray.cpp.o" \
"CMakeFiles/graphics.dir/Renderable2D.cpp.o" \
"CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o"

# External object files for target graphics
graphics_EXTERNAL_OBJECTS =

src/graphics/libgraphics.a: src/graphics/CMakeFiles/graphics.dir/Window.cpp.o
src/graphics/libgraphics.a: src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o
src/graphics/libgraphics.a: src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o
src/graphics/libgraphics.a: src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o
src/graphics/libgraphics.a: src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o
src/graphics/libgraphics.a: src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o
src/graphics/libgraphics.a: src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o
src/graphics/libgraphics.a: src/graphics/CMakeFiles/graphics.dir/build.make
src/graphics/libgraphics.a: src/graphics/CMakeFiles/graphics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgraphics.a"
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && $(CMAKE_COMMAND) -P CMakeFiles/graphics.dir/cmake_clean_target.cmake
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/graphics/CMakeFiles/graphics.dir/build: src/graphics/libgraphics.a
.PHONY : src/graphics/CMakeFiles/graphics.dir/build

src/graphics/CMakeFiles/graphics.dir/requires: src/graphics/CMakeFiles/graphics.dir/Window.cpp.o.requires
src/graphics/CMakeFiles/graphics.dir/requires: src/graphics/CMakeFiles/graphics.dir/Shader.cpp.o.requires
src/graphics/CMakeFiles/graphics.dir/requires: src/graphics/CMakeFiles/graphics.dir/ShaderProgram.cpp.o.requires
src/graphics/CMakeFiles/graphics.dir/requires: src/graphics/CMakeFiles/graphics.dir/Buffer.cpp.o.requires
src/graphics/CMakeFiles/graphics.dir/requires: src/graphics/CMakeFiles/graphics.dir/VertexArray.cpp.o.requires
src/graphics/CMakeFiles/graphics.dir/requires: src/graphics/CMakeFiles/graphics.dir/Renderable2D.cpp.o.requires
src/graphics/CMakeFiles/graphics.dir/requires: src/graphics/CMakeFiles/graphics.dir/SimpleRenderer2D.cpp.o.requires
.PHONY : src/graphics/CMakeFiles/graphics.dir/requires

src/graphics/CMakeFiles/graphics.dir/clean:
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics && $(CMAKE_COMMAND) -P CMakeFiles/graphics.dir/cmake_clean.cmake
.PHONY : src/graphics/CMakeFiles/graphics.dir/clean

src/graphics/CMakeFiles/graphics.dir/depend:
	cd /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/src/graphics /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics /home/lejonmcgowan/Dropbox/projects/OGLSimpleEngine/build/src/graphics/CMakeFiles/graphics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/graphics/CMakeFiles/graphics.dir/depend
