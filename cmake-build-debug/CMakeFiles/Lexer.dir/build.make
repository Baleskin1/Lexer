# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\User\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.6183.77\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\User\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.6183.77\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProjects\Lexer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\Lexer\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lexer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lexer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lexer.dir/flags.make

CMakeFiles/Lexer.dir/main.cpp.obj: CMakeFiles/Lexer.dir/flags.make
CMakeFiles/Lexer.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\Lexer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lexer.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lexer.dir\main.cpp.obj -c D:\CLionProjects\Lexer\main.cpp

CMakeFiles/Lexer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lexer.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\Lexer\main.cpp > CMakeFiles\Lexer.dir\main.cpp.i

CMakeFiles/Lexer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lexer.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\Lexer\main.cpp -o CMakeFiles\Lexer.dir\main.cpp.s

CMakeFiles/Lexer.dir/lexer.cpp.obj: CMakeFiles/Lexer.dir/flags.make
CMakeFiles/Lexer.dir/lexer.cpp.obj: ../lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\Lexer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lexer.dir/lexer.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lexer.dir\lexer.cpp.obj -c D:\CLionProjects\Lexer\lexer.cpp

CMakeFiles/Lexer.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lexer.dir/lexer.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\Lexer\lexer.cpp > CMakeFiles\Lexer.dir\lexer.cpp.i

CMakeFiles/Lexer.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lexer.dir/lexer.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\Lexer\lexer.cpp -o CMakeFiles\Lexer.dir\lexer.cpp.s

# Object files for target Lexer
Lexer_OBJECTS = \
"CMakeFiles/Lexer.dir/main.cpp.obj" \
"CMakeFiles/Lexer.dir/lexer.cpp.obj"

# External object files for target Lexer
Lexer_EXTERNAL_OBJECTS =

Lexer.exe: CMakeFiles/Lexer.dir/main.cpp.obj
Lexer.exe: CMakeFiles/Lexer.dir/lexer.cpp.obj
Lexer.exe: CMakeFiles/Lexer.dir/build.make
Lexer.exe: CMakeFiles/Lexer.dir/linklibs.rsp
Lexer.exe: CMakeFiles/Lexer.dir/objects1.rsp
Lexer.exe: CMakeFiles/Lexer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\Lexer\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lexer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lexer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lexer.dir/build: Lexer.exe

.PHONY : CMakeFiles/Lexer.dir/build

CMakeFiles/Lexer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lexer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lexer.dir/clean

CMakeFiles/Lexer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\Lexer D:\CLionProjects\Lexer D:\CLionProjects\Lexer\cmake-build-debug D:\CLionProjects\Lexer\cmake-build-debug D:\CLionProjects\Lexer\cmake-build-debug\CMakeFiles\Lexer.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lexer.dir/depend

