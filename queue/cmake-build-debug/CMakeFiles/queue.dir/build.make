# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Users\12268\AppData\Local\JetBrains\Toolbox\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = D:\Users\12268\AppData\Local\JetBrains\Toolbox\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\clion_cppcode\queue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\clion_cppcode\queue\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/queue.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/queue.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/queue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/queue.dir/flags.make

CMakeFiles/queue.dir/queue.cpp.obj: CMakeFiles/queue.dir/flags.make
CMakeFiles/queue.dir/queue.cpp.obj: CMakeFiles/queue.dir/includes_CXX.rsp
CMakeFiles/queue.dir/queue.cpp.obj: D:/clion_cppcode/queue/queue.cpp
CMakeFiles/queue.dir/queue.cpp.obj: CMakeFiles/queue.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\clion_cppcode\queue\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/queue.dir/queue.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/queue.dir/queue.cpp.obj -MF CMakeFiles\queue.dir\queue.cpp.obj.d -o CMakeFiles\queue.dir\queue.cpp.obj -c D:\clion_cppcode\queue\queue.cpp

CMakeFiles/queue.dir/queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/queue.dir/queue.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\clion_cppcode\queue\queue.cpp > CMakeFiles\queue.dir\queue.cpp.i

CMakeFiles/queue.dir/queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/queue.dir/queue.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\clion_cppcode\queue\queue.cpp -o CMakeFiles\queue.dir\queue.cpp.s

# Object files for target queue
queue_OBJECTS = \
"CMakeFiles/queue.dir/queue.cpp.obj"

# External object files for target queue
queue_EXTERNAL_OBJECTS =

queue.exe: CMakeFiles/queue.dir/queue.cpp.obj
queue.exe: CMakeFiles/queue.dir/build.make
queue.exe: CMakeFiles/queue.dir/linkLibs.rsp
queue.exe: CMakeFiles/queue.dir/objects1.rsp
queue.exe: CMakeFiles/queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\clion_cppcode\queue\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable queue.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\queue.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/queue.dir/build: queue.exe
.PHONY : CMakeFiles/queue.dir/build

CMakeFiles/queue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\queue.dir\cmake_clean.cmake
.PHONY : CMakeFiles/queue.dir/clean

CMakeFiles/queue.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\clion_cppcode\queue D:\clion_cppcode\queue D:\clion_cppcode\queue\cmake-build-debug D:\clion_cppcode\queue\cmake-build-debug D:\clion_cppcode\queue\cmake-build-debug\CMakeFiles\queue.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/queue.dir/depend

