# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/user/Desktop/UIUC/naive-numbers-danniely

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/user/Desktop/UIUC/naive-numbers-danniely/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/naivebayes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/naivebayes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/naivebayes.dir/flags.make

CMakeFiles/naivebayes.dir/main.cpp.o: CMakeFiles/naivebayes.dir/flags.make
CMakeFiles/naivebayes.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Desktop/UIUC/naive-numbers-danniely/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/naivebayes.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naivebayes.dir/main.cpp.o -c /Users/user/Desktop/UIUC/naive-numbers-danniely/main.cpp

CMakeFiles/naivebayes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naivebayes.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Desktop/UIUC/naive-numbers-danniely/main.cpp > CMakeFiles/naivebayes.dir/main.cpp.i

CMakeFiles/naivebayes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naivebayes.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Desktop/UIUC/naive-numbers-danniely/main.cpp -o CMakeFiles/naivebayes.dir/main.cpp.s

CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.o: CMakeFiles/naivebayes.dir/flags.make
CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.o: ../libbayes/src/model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Desktop/UIUC/naive-numbers-danniely/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.o -c /Users/user/Desktop/UIUC/naive-numbers-danniely/libbayes/src/model.cpp

CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Desktop/UIUC/naive-numbers-danniely/libbayes/src/model.cpp > CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.i

CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Desktop/UIUC/naive-numbers-danniely/libbayes/src/model.cpp -o CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.s

CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.o: CMakeFiles/naivebayes.dir/flags.make
CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.o: ../libbayes/src/validation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/user/Desktop/UIUC/naive-numbers-danniely/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.o -c /Users/user/Desktop/UIUC/naive-numbers-danniely/libbayes/src/validation.cpp

CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/user/Desktop/UIUC/naive-numbers-danniely/libbayes/src/validation.cpp > CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.i

CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/user/Desktop/UIUC/naive-numbers-danniely/libbayes/src/validation.cpp -o CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.s

# Object files for target naivebayes
naivebayes_OBJECTS = \
"CMakeFiles/naivebayes.dir/main.cpp.o" \
"CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.o" \
"CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.o"

# External object files for target naivebayes
naivebayes_EXTERNAL_OBJECTS =

naivebayes: CMakeFiles/naivebayes.dir/main.cpp.o
naivebayes: CMakeFiles/naivebayes.dir/libbayes/src/model.cpp.o
naivebayes: CMakeFiles/naivebayes.dir/libbayes/src/validation.cpp.o
naivebayes: CMakeFiles/naivebayes.dir/build.make
naivebayes: libbayes/src/liblibbayes.a
naivebayes: CMakeFiles/naivebayes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/user/Desktop/UIUC/naive-numbers-danniely/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable naivebayes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/naivebayes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/naivebayes.dir/build: naivebayes

.PHONY : CMakeFiles/naivebayes.dir/build

CMakeFiles/naivebayes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/naivebayes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/naivebayes.dir/clean

CMakeFiles/naivebayes.dir/depend:
	cd /Users/user/Desktop/UIUC/naive-numbers-danniely/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/user/Desktop/UIUC/naive-numbers-danniely /Users/user/Desktop/UIUC/naive-numbers-danniely /Users/user/Desktop/UIUC/naive-numbers-danniely/cmake-build-debug /Users/user/Desktop/UIUC/naive-numbers-danniely/cmake-build-debug /Users/user/Desktop/UIUC/naive-numbers-danniely/cmake-build-debug/CMakeFiles/naivebayes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/naivebayes.dir/depend

