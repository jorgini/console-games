# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jorka\CLionProjects\console-games

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jorka\CLionProjects\console-games\cmake-build-debug-mingw

# Include any dependencies generated for this target.
include CMakeFiles/2048.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/2048.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/2048.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2048.dir/flags.make

CMakeFiles/2048.dir/2048_game/field2048.cpp.obj: CMakeFiles/2048.dir/flags.make
CMakeFiles/2048.dir/2048_game/field2048.cpp.obj: C:/Users/jorka/CLionProjects/console-games/2048\ game/field2048.cpp
CMakeFiles/2048.dir/2048_game/field2048.cpp.obj: CMakeFiles/2048.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jorka\CLionProjects\console-games\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2048.dir/2048_game/field2048.cpp.obj"
	C:\Qt6\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/2048.dir/2048_game/field2048.cpp.obj -MF CMakeFiles\2048.dir\2048_game\field2048.cpp.obj.d -o CMakeFiles\2048.dir\2048_game\field2048.cpp.obj -c "C:\Users\jorka\CLionProjects\console-games\2048 game\field2048.cpp"

CMakeFiles/2048.dir/2048_game/field2048.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2048.dir/2048_game/field2048.cpp.i"
	C:\Qt6\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\jorka\CLionProjects\console-games\2048 game\field2048.cpp" > CMakeFiles\2048.dir\2048_game\field2048.cpp.i

CMakeFiles/2048.dir/2048_game/field2048.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2048.dir/2048_game/field2048.cpp.s"
	C:\Qt6\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\jorka\CLionProjects\console-games\2048 game\field2048.cpp" -o CMakeFiles\2048.dir\2048_game\field2048.cpp.s

CMakeFiles/2048.dir/2048_game/main2048.cpp.obj: CMakeFiles/2048.dir/flags.make
CMakeFiles/2048.dir/2048_game/main2048.cpp.obj: C:/Users/jorka/CLionProjects/console-games/2048\ game/main2048.cpp
CMakeFiles/2048.dir/2048_game/main2048.cpp.obj: CMakeFiles/2048.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jorka\CLionProjects\console-games\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/2048.dir/2048_game/main2048.cpp.obj"
	C:\Qt6\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/2048.dir/2048_game/main2048.cpp.obj -MF CMakeFiles\2048.dir\2048_game\main2048.cpp.obj.d -o CMakeFiles\2048.dir\2048_game\main2048.cpp.obj -c "C:\Users\jorka\CLionProjects\console-games\2048 game\main2048.cpp"

CMakeFiles/2048.dir/2048_game/main2048.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2048.dir/2048_game/main2048.cpp.i"
	C:\Qt6\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\jorka\CLionProjects\console-games\2048 game\main2048.cpp" > CMakeFiles\2048.dir\2048_game\main2048.cpp.i

CMakeFiles/2048.dir/2048_game/main2048.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2048.dir/2048_game/main2048.cpp.s"
	C:\Qt6\Tools\mingw1120_64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\jorka\CLionProjects\console-games\2048 game\main2048.cpp" -o CMakeFiles\2048.dir\2048_game\main2048.cpp.s

# Object files for target 2048
2048_OBJECTS = \
"CMakeFiles/2048.dir/2048_game/field2048.cpp.obj" \
"CMakeFiles/2048.dir/2048_game/main2048.cpp.obj"

# External object files for target 2048
2048_EXTERNAL_OBJECTS =

2048.exe: CMakeFiles/2048.dir/2048_game/field2048.cpp.obj
2048.exe: CMakeFiles/2048.dir/2048_game/main2048.cpp.obj
2048.exe: CMakeFiles/2048.dir/build.make
2048.exe: CMakeFiles/2048.dir/linkLibs.rsp
2048.exe: CMakeFiles/2048.dir/objects1
2048.exe: CMakeFiles/2048.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jorka\CLionProjects\console-games\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 2048.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2048.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2048.dir/build: 2048.exe
.PHONY : CMakeFiles/2048.dir/build

CMakeFiles/2048.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2048.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2048.dir/clean

CMakeFiles/2048.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jorka\CLionProjects\console-games C:\Users\jorka\CLionProjects\console-games C:\Users\jorka\CLionProjects\console-games\cmake-build-debug-mingw C:\Users\jorka\CLionProjects\console-games\cmake-build-debug-mingw C:\Users\jorka\CLionProjects\console-games\cmake-build-debug-mingw\CMakeFiles\2048.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2048.dir/depend

