# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alejandro/CLionProjects/MPointers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alejandro/CLionProjects/MPointers/build

# Include any dependencies generated for this target.
include CMakeFiles/MPointers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MPointers.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MPointers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MPointers.dir/flags.make

CMakeFiles/MPointers.dir/main.cpp.o: CMakeFiles/MPointers.dir/flags.make
CMakeFiles/MPointers.dir/main.cpp.o: /home/alejandro/CLionProjects/MPointers/main.cpp
CMakeFiles/MPointers.dir/main.cpp.o: CMakeFiles/MPointers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alejandro/CLionProjects/MPointers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MPointers.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MPointers.dir/main.cpp.o -MF CMakeFiles/MPointers.dir/main.cpp.o.d -o CMakeFiles/MPointers.dir/main.cpp.o -c /home/alejandro/CLionProjects/MPointers/main.cpp

CMakeFiles/MPointers.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MPointers.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alejandro/CLionProjects/MPointers/main.cpp > CMakeFiles/MPointers.dir/main.cpp.i

CMakeFiles/MPointers.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MPointers.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alejandro/CLionProjects/MPointers/main.cpp -o CMakeFiles/MPointers.dir/main.cpp.s

CMakeFiles/MPointers.dir/MPointerGC.cpp.o: CMakeFiles/MPointers.dir/flags.make
CMakeFiles/MPointers.dir/MPointerGC.cpp.o: /home/alejandro/CLionProjects/MPointers/MPointerGC.cpp
CMakeFiles/MPointers.dir/MPointerGC.cpp.o: CMakeFiles/MPointers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alejandro/CLionProjects/MPointers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MPointers.dir/MPointerGC.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MPointers.dir/MPointerGC.cpp.o -MF CMakeFiles/MPointers.dir/MPointerGC.cpp.o.d -o CMakeFiles/MPointers.dir/MPointerGC.cpp.o -c /home/alejandro/CLionProjects/MPointers/MPointerGC.cpp

CMakeFiles/MPointers.dir/MPointerGC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MPointers.dir/MPointerGC.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alejandro/CLionProjects/MPointers/MPointerGC.cpp > CMakeFiles/MPointers.dir/MPointerGC.cpp.i

CMakeFiles/MPointers.dir/MPointerGC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MPointers.dir/MPointerGC.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alejandro/CLionProjects/MPointers/MPointerGC.cpp -o CMakeFiles/MPointers.dir/MPointerGC.cpp.s

CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.o: CMakeFiles/MPointers.dir/flags.make
CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.o: /home/alejandro/CLionProjects/MPointers/tests/MPointerTest.cpp
CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.o: CMakeFiles/MPointers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alejandro/CLionProjects/MPointers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.o -MF CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.o.d -o CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.o -c /home/alejandro/CLionProjects/MPointers/tests/MPointerTest.cpp

CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alejandro/CLionProjects/MPointers/tests/MPointerTest.cpp > CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.i

CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alejandro/CLionProjects/MPointers/tests/MPointerTest.cpp -o CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.s

CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.o: CMakeFiles/MPointers.dir/flags.make
CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.o: /home/alejandro/CLionProjects/MPointers/tests/MPointerGCTests.cpp
CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.o: CMakeFiles/MPointers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alejandro/CLionProjects/MPointers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.o -MF CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.o.d -o CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.o -c /home/alejandro/CLionProjects/MPointers/tests/MPointerGCTests.cpp

CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alejandro/CLionProjects/MPointers/tests/MPointerGCTests.cpp > CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.i

CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alejandro/CLionProjects/MPointers/tests/MPointerGCTests.cpp -o CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.s

CMakeFiles/MPointers.dir/tests/DLLTests.cpp.o: CMakeFiles/MPointers.dir/flags.make
CMakeFiles/MPointers.dir/tests/DLLTests.cpp.o: /home/alejandro/CLionProjects/MPointers/tests/DLLTests.cpp
CMakeFiles/MPointers.dir/tests/DLLTests.cpp.o: CMakeFiles/MPointers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alejandro/CLionProjects/MPointers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MPointers.dir/tests/DLLTests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MPointers.dir/tests/DLLTests.cpp.o -MF CMakeFiles/MPointers.dir/tests/DLLTests.cpp.o.d -o CMakeFiles/MPointers.dir/tests/DLLTests.cpp.o -c /home/alejandro/CLionProjects/MPointers/tests/DLLTests.cpp

CMakeFiles/MPointers.dir/tests/DLLTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MPointers.dir/tests/DLLTests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alejandro/CLionProjects/MPointers/tests/DLLTests.cpp > CMakeFiles/MPointers.dir/tests/DLLTests.cpp.i

CMakeFiles/MPointers.dir/tests/DLLTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MPointers.dir/tests/DLLTests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alejandro/CLionProjects/MPointers/tests/DLLTests.cpp -o CMakeFiles/MPointers.dir/tests/DLLTests.cpp.s

CMakeFiles/MPointers.dir/tests/SortersTests.cpp.o: CMakeFiles/MPointers.dir/flags.make
CMakeFiles/MPointers.dir/tests/SortersTests.cpp.o: /home/alejandro/CLionProjects/MPointers/tests/SortersTests.cpp
CMakeFiles/MPointers.dir/tests/SortersTests.cpp.o: CMakeFiles/MPointers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/alejandro/CLionProjects/MPointers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MPointers.dir/tests/SortersTests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MPointers.dir/tests/SortersTests.cpp.o -MF CMakeFiles/MPointers.dir/tests/SortersTests.cpp.o.d -o CMakeFiles/MPointers.dir/tests/SortersTests.cpp.o -c /home/alejandro/CLionProjects/MPointers/tests/SortersTests.cpp

CMakeFiles/MPointers.dir/tests/SortersTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MPointers.dir/tests/SortersTests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alejandro/CLionProjects/MPointers/tests/SortersTests.cpp > CMakeFiles/MPointers.dir/tests/SortersTests.cpp.i

CMakeFiles/MPointers.dir/tests/SortersTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MPointers.dir/tests/SortersTests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alejandro/CLionProjects/MPointers/tests/SortersTests.cpp -o CMakeFiles/MPointers.dir/tests/SortersTests.cpp.s

# Object files for target MPointers
MPointers_OBJECTS = \
"CMakeFiles/MPointers.dir/main.cpp.o" \
"CMakeFiles/MPointers.dir/MPointerGC.cpp.o" \
"CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.o" \
"CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.o" \
"CMakeFiles/MPointers.dir/tests/DLLTests.cpp.o" \
"CMakeFiles/MPointers.dir/tests/SortersTests.cpp.o"

# External object files for target MPointers
MPointers_EXTERNAL_OBJECTS =

MPointers: CMakeFiles/MPointers.dir/main.cpp.o
MPointers: CMakeFiles/MPointers.dir/MPointerGC.cpp.o
MPointers: CMakeFiles/MPointers.dir/tests/MPointerTest.cpp.o
MPointers: CMakeFiles/MPointers.dir/tests/MPointerGCTests.cpp.o
MPointers: CMakeFiles/MPointers.dir/tests/DLLTests.cpp.o
MPointers: CMakeFiles/MPointers.dir/tests/SortersTests.cpp.o
MPointers: CMakeFiles/MPointers.dir/build.make
MPointers: CMakeFiles/MPointers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/alejandro/CLionProjects/MPointers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable MPointers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MPointers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MPointers.dir/build: MPointers
.PHONY : CMakeFiles/MPointers.dir/build

CMakeFiles/MPointers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MPointers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MPointers.dir/clean

CMakeFiles/MPointers.dir/depend:
	cd /home/alejandro/CLionProjects/MPointers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alejandro/CLionProjects/MPointers /home/alejandro/CLionProjects/MPointers /home/alejandro/CLionProjects/MPointers/build /home/alejandro/CLionProjects/MPointers/build /home/alejandro/CLionProjects/MPointers/build/CMakeFiles/MPointers.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MPointers.dir/depend

