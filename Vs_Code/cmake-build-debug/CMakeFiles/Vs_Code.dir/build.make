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
CMAKE_COMMAND = /cygdrive/c/Users/grero/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/grero/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/grero/CLionProjects/Vs_Code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/grero/CLionProjects/Vs_Code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Vs_Code.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Vs_Code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Vs_Code.dir/flags.make

CMakeFiles/Vs_Code.dir/main.cpp.o: CMakeFiles/Vs_Code.dir/flags.make
CMakeFiles/Vs_Code.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/grero/CLionProjects/Vs_Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Vs_Code.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Vs_Code.dir/main.cpp.o -c /cygdrive/c/Users/grero/CLionProjects/Vs_Code/main.cpp

CMakeFiles/Vs_Code.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vs_Code.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/grero/CLionProjects/Vs_Code/main.cpp > CMakeFiles/Vs_Code.dir/main.cpp.i

CMakeFiles/Vs_Code.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vs_Code.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/grero/CLionProjects/Vs_Code/main.cpp -o CMakeFiles/Vs_Code.dir/main.cpp.s

# Object files for target Vs_Code
Vs_Code_OBJECTS = \
"CMakeFiles/Vs_Code.dir/main.cpp.o"

# External object files for target Vs_Code
Vs_Code_EXTERNAL_OBJECTS =

Vs_Code.exe: CMakeFiles/Vs_Code.dir/main.cpp.o
Vs_Code.exe: CMakeFiles/Vs_Code.dir/build.make
Vs_Code.exe: CMakeFiles/Vs_Code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/grero/CLionProjects/Vs_Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Vs_Code.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vs_Code.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Vs_Code.dir/build: Vs_Code.exe

.PHONY : CMakeFiles/Vs_Code.dir/build

CMakeFiles/Vs_Code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Vs_Code.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Vs_Code.dir/clean

CMakeFiles/Vs_Code.dir/depend:
	cd /cygdrive/c/Users/grero/CLionProjects/Vs_Code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/grero/CLionProjects/Vs_Code /cygdrive/c/Users/grero/CLionProjects/Vs_Code /cygdrive/c/Users/grero/CLionProjects/Vs_Code/cmake-build-debug /cygdrive/c/Users/grero/CLionProjects/Vs_Code/cmake-build-debug /cygdrive/c/Users/grero/CLionProjects/Vs_Code/cmake-build-debug/CMakeFiles/Vs_Code.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Vs_Code.dir/depend
