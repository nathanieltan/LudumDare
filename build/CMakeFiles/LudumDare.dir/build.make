# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/nathaniel/Documents/LudumDare/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nathaniel/Documents/LudumDare/build

# Include any dependencies generated for this target.
include CMakeFiles/LudumDare.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LudumDare.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LudumDare.dir/flags.make

CMakeFiles/LudumDare.dir/main.cpp.o: CMakeFiles/LudumDare.dir/flags.make
CMakeFiles/LudumDare.dir/main.cpp.o: /home/nathaniel/Documents/LudumDare/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nathaniel/Documents/LudumDare/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LudumDare.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LudumDare.dir/main.cpp.o -c /home/nathaniel/Documents/LudumDare/src/main.cpp

CMakeFiles/LudumDare.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LudumDare.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nathaniel/Documents/LudumDare/src/main.cpp > CMakeFiles/LudumDare.dir/main.cpp.i

CMakeFiles/LudumDare.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LudumDare.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nathaniel/Documents/LudumDare/src/main.cpp -o CMakeFiles/LudumDare.dir/main.cpp.s

CMakeFiles/LudumDare.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/LudumDare.dir/main.cpp.o.requires

CMakeFiles/LudumDare.dir/main.cpp.o.provides: CMakeFiles/LudumDare.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/LudumDare.dir/build.make CMakeFiles/LudumDare.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/LudumDare.dir/main.cpp.o.provides

CMakeFiles/LudumDare.dir/main.cpp.o.provides.build: CMakeFiles/LudumDare.dir/main.cpp.o


CMakeFiles/LudumDare.dir/Collision.cpp.o: CMakeFiles/LudumDare.dir/flags.make
CMakeFiles/LudumDare.dir/Collision.cpp.o: /home/nathaniel/Documents/LudumDare/src/Collision.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nathaniel/Documents/LudumDare/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LudumDare.dir/Collision.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LudumDare.dir/Collision.cpp.o -c /home/nathaniel/Documents/LudumDare/src/Collision.cpp

CMakeFiles/LudumDare.dir/Collision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LudumDare.dir/Collision.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nathaniel/Documents/LudumDare/src/Collision.cpp > CMakeFiles/LudumDare.dir/Collision.cpp.i

CMakeFiles/LudumDare.dir/Collision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LudumDare.dir/Collision.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nathaniel/Documents/LudumDare/src/Collision.cpp -o CMakeFiles/LudumDare.dir/Collision.cpp.s

CMakeFiles/LudumDare.dir/Collision.cpp.o.requires:

.PHONY : CMakeFiles/LudumDare.dir/Collision.cpp.o.requires

CMakeFiles/LudumDare.dir/Collision.cpp.o.provides: CMakeFiles/LudumDare.dir/Collision.cpp.o.requires
	$(MAKE) -f CMakeFiles/LudumDare.dir/build.make CMakeFiles/LudumDare.dir/Collision.cpp.o.provides.build
.PHONY : CMakeFiles/LudumDare.dir/Collision.cpp.o.provides

CMakeFiles/LudumDare.dir/Collision.cpp.o.provides.build: CMakeFiles/LudumDare.dir/Collision.cpp.o


CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o: CMakeFiles/LudumDare.dir/flags.make
CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o: /home/nathaniel/Documents/LudumDare/src/thingsWithMass.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nathaniel/Documents/LudumDare/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o -c /home/nathaniel/Documents/LudumDare/src/thingsWithMass.cpp

CMakeFiles/LudumDare.dir/thingsWithMass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LudumDare.dir/thingsWithMass.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nathaniel/Documents/LudumDare/src/thingsWithMass.cpp > CMakeFiles/LudumDare.dir/thingsWithMass.cpp.i

CMakeFiles/LudumDare.dir/thingsWithMass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LudumDare.dir/thingsWithMass.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nathaniel/Documents/LudumDare/src/thingsWithMass.cpp -o CMakeFiles/LudumDare.dir/thingsWithMass.cpp.s

CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o.requires:

.PHONY : CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o.requires

CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o.provides: CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o.requires
	$(MAKE) -f CMakeFiles/LudumDare.dir/build.make CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o.provides.build
.PHONY : CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o.provides

CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o.provides.build: CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o


# Object files for target LudumDare
LudumDare_OBJECTS = \
"CMakeFiles/LudumDare.dir/main.cpp.o" \
"CMakeFiles/LudumDare.dir/Collision.cpp.o" \
"CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o"

# External object files for target LudumDare
LudumDare_EXTERNAL_OBJECTS =

LudumDare: CMakeFiles/LudumDare.dir/main.cpp.o
LudumDare: CMakeFiles/LudumDare.dir/Collision.cpp.o
LudumDare: CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o
LudumDare: CMakeFiles/LudumDare.dir/build.make
LudumDare: /usr/lib/x86_64-linux-gnu/libsfml-network.so
LudumDare: /usr/lib/x86_64-linux-gnu/libsfml-audio.so
LudumDare: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
LudumDare: /usr/lib/x86_64-linux-gnu/libsfml-window.so
LudumDare: /usr/lib/x86_64-linux-gnu/libsfml-system.so
LudumDare: CMakeFiles/LudumDare.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nathaniel/Documents/LudumDare/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable LudumDare"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LudumDare.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LudumDare.dir/build: LudumDare

.PHONY : CMakeFiles/LudumDare.dir/build

CMakeFiles/LudumDare.dir/requires: CMakeFiles/LudumDare.dir/main.cpp.o.requires
CMakeFiles/LudumDare.dir/requires: CMakeFiles/LudumDare.dir/Collision.cpp.o.requires
CMakeFiles/LudumDare.dir/requires: CMakeFiles/LudumDare.dir/thingsWithMass.cpp.o.requires

.PHONY : CMakeFiles/LudumDare.dir/requires

CMakeFiles/LudumDare.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LudumDare.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LudumDare.dir/clean

CMakeFiles/LudumDare.dir/depend:
	cd /home/nathaniel/Documents/LudumDare/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nathaniel/Documents/LudumDare/src /home/nathaniel/Documents/LudumDare/src /home/nathaniel/Documents/LudumDare/build /home/nathaniel/Documents/LudumDare/build /home/nathaniel/Documents/LudumDare/build/CMakeFiles/LudumDare.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LudumDare.dir/depend

