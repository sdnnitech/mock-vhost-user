# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/takeya/new-b4-assignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/takeya/new-b4-assignment/build

# Include any dependencies generated for this target.
include CMakeFiles/recv.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/recv.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/recv.out.dir/flags.make

CMakeFiles/recv.out.dir/recv.cpp.o: CMakeFiles/recv.out.dir/flags.make
CMakeFiles/recv.out.dir/recv.cpp.o: ../recv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/takeya/new-b4-assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/recv.out.dir/recv.cpp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/recv.out.dir/recv.cpp.o -c /home/takeya/new-b4-assignment/recv.cpp

CMakeFiles/recv.out.dir/recv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recv.out.dir/recv.cpp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/takeya/new-b4-assignment/recv.cpp > CMakeFiles/recv.out.dir/recv.cpp.i

CMakeFiles/recv.out.dir/recv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recv.out.dir/recv.cpp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/takeya/new-b4-assignment/recv.cpp -o CMakeFiles/recv.out.dir/recv.cpp.s

CMakeFiles/recv.out.dir/shm.cpp.o: CMakeFiles/recv.out.dir/flags.make
CMakeFiles/recv.out.dir/shm.cpp.o: ../shm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/takeya/new-b4-assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/recv.out.dir/shm.cpp.o"
	/opt/rh/devtoolset-8/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/recv.out.dir/shm.cpp.o -c /home/takeya/new-b4-assignment/shm.cpp

CMakeFiles/recv.out.dir/shm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recv.out.dir/shm.cpp.i"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/takeya/new-b4-assignment/shm.cpp > CMakeFiles/recv.out.dir/shm.cpp.i

CMakeFiles/recv.out.dir/shm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recv.out.dir/shm.cpp.s"
	/opt/rh/devtoolset-8/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/takeya/new-b4-assignment/shm.cpp -o CMakeFiles/recv.out.dir/shm.cpp.s

# Object files for target recv.out
recv_out_OBJECTS = \
"CMakeFiles/recv.out.dir/recv.cpp.o" \
"CMakeFiles/recv.out.dir/shm.cpp.o"

# External object files for target recv.out
recv_out_EXTERNAL_OBJECTS =

recv.out: CMakeFiles/recv.out.dir/recv.cpp.o
recv.out: CMakeFiles/recv.out.dir/shm.cpp.o
recv.out: CMakeFiles/recv.out.dir/build.make
recv.out: CMakeFiles/recv.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/takeya/new-b4-assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable recv.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/recv.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/recv.out.dir/build: recv.out

.PHONY : CMakeFiles/recv.out.dir/build

CMakeFiles/recv.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/recv.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/recv.out.dir/clean

CMakeFiles/recv.out.dir/depend:
	cd /home/takeya/new-b4-assignment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/takeya/new-b4-assignment /home/takeya/new-b4-assignment /home/takeya/new-b4-assignment/build /home/takeya/new-b4-assignment/build /home/takeya/new-b4-assignment/build/CMakeFiles/recv.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/recv.out.dir/depend
