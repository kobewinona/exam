# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dmitriklimkin/dev/42Network/exam/rip

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dmitriklimkin/dev/42Network/exam/rip/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rip.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rip.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rip.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rip.dir/flags.make

CMakeFiles/rip.dir/rip.c.o: CMakeFiles/rip.dir/flags.make
CMakeFiles/rip.dir/rip.c.o: /Users/dmitriklimkin/dev/42Network/exam/rip/rip.c
CMakeFiles/rip.dir/rip.c.o: CMakeFiles/rip.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/dmitriklimkin/dev/42Network/exam/rip/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rip.dir/rip.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/rip.dir/rip.c.o -MF CMakeFiles/rip.dir/rip.c.o.d -o CMakeFiles/rip.dir/rip.c.o -c /Users/dmitriklimkin/dev/42Network/exam/rip/rip.c

CMakeFiles/rip.dir/rip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/rip.dir/rip.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dmitriklimkin/dev/42Network/exam/rip/rip.c > CMakeFiles/rip.dir/rip.c.i

CMakeFiles/rip.dir/rip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/rip.dir/rip.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dmitriklimkin/dev/42Network/exam/rip/rip.c -o CMakeFiles/rip.dir/rip.c.s

# Object files for target rip
rip_OBJECTS = \
"CMakeFiles/rip.dir/rip.c.o"

# External object files for target rip
rip_EXTERNAL_OBJECTS =

rip: CMakeFiles/rip.dir/rip.c.o
rip: CMakeFiles/rip.dir/build.make
rip: CMakeFiles/rip.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/dmitriklimkin/dev/42Network/exam/rip/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rip"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rip.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rip.dir/build: rip
.PHONY : CMakeFiles/rip.dir/build

CMakeFiles/rip.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rip.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rip.dir/clean

CMakeFiles/rip.dir/depend:
	cd /Users/dmitriklimkin/dev/42Network/exam/rip/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dmitriklimkin/dev/42Network/exam/rip /Users/dmitriklimkin/dev/42Network/exam/rip /Users/dmitriklimkin/dev/42Network/exam/rip/cmake-build-debug /Users/dmitriklimkin/dev/42Network/exam/rip/cmake-build-debug /Users/dmitriklimkin/dev/42Network/exam/rip/cmake-build-debug/CMakeFiles/rip.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/rip.dir/depend

