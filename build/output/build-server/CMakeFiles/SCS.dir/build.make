# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/oliver/my_proj/SCS/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oliver/my_proj/SCS/build/output/build-server

# Include any dependencies generated for this target.
include CMakeFiles/SCS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SCS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SCS.dir/flags.make

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.o: CMakeFiles/SCS.dir/flags.make
CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.o: /home/oliver/my_proj/SCS/main/server/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/my_proj/SCS/build/output/build-server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.o -c /home/oliver/my_proj/SCS/main/server/src/main.cpp

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/my_proj/SCS/main/server/src/main.cpp > CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.i

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/my_proj/SCS/main/server/src/main.cpp -o CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.s

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.o: CMakeFiles/SCS.dir/flags.make
CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.o: /home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/my_proj/SCS/build/output/build-server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.o -c /home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp > CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.i

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp -o CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.s

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.o: CMakeFiles/SCS.dir/flags.make
CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.o: /home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/my_proj/SCS/build/output/build-server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.o -c /home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp > CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.i

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp -o CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.s

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.o: CMakeFiles/SCS.dir/flags.make
CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.o: /home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oliver/my_proj/SCS/build/output/build-server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.o -c /home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp > CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.i

CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp -o CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.s

# Object files for target SCS
SCS_OBJECTS = \
"CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.o" \
"CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.o" \
"CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.o" \
"CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.o"

# External object files for target SCS
SCS_EXTERNAL_OBJECTS =

SCS: CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/server/src/main.cpp.o
SCS: CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportError.cpp.o
SCS: CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/support/src/MSupportTerminal.cpp.o
SCS: CMakeFiles/SCS.dir/home/oliver/my_proj/SCS/main/thread/src/ThreadSupport.cpp.o
SCS: CMakeFiles/SCS.dir/build.make
SCS: CMakeFiles/SCS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oliver/my_proj/SCS/build/output/build-server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable SCS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SCS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SCS.dir/build: SCS

.PHONY : CMakeFiles/SCS.dir/build

CMakeFiles/SCS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SCS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SCS.dir/clean

CMakeFiles/SCS.dir/depend:
	cd /home/oliver/my_proj/SCS/build/output/build-server && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oliver/my_proj/SCS/build /home/oliver/my_proj/SCS/build /home/oliver/my_proj/SCS/build/output/build-server /home/oliver/my_proj/SCS/build/output/build-server /home/oliver/my_proj/SCS/build/output/build-server/CMakeFiles/SCS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SCS.dir/depend
