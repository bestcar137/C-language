# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2025.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2025.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\bestc\CLionProjects\C-language

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\bestc\CLionProjects\C-language\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW_5_2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HW_5_2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HW_5_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW_5_2.dir/flags.make

CMakeFiles/HW_5_2.dir/codegen:
.PHONY : CMakeFiles/HW_5_2.dir/codegen

CMakeFiles/HW_5_2.dir/CH_code/ch5/HW_5_2.c.obj: CMakeFiles/HW_5_2.dir/flags.make
CMakeFiles/HW_5_2.dir/CH_code/ch5/HW_5_2.c.obj: C:/Users/bestc/CLionProjects/C-language/CH_code/ch5/HW_5_2.c
CMakeFiles/HW_5_2.dir/CH_code/ch5/HW_5_2.c.obj: CMakeFiles/HW_5_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\bestc\CLionProjects\C-language\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HW_5_2.dir/CH_code/ch5/HW_5_2.c.obj"
	"C:\PROGRA~1\JetBrains\CLion 2025.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/HW_5_2.dir/CH_code/ch5/HW_5_2.c.obj -MF CMakeFiles\HW_5_2.dir\CH_code\ch5\HW_5_2.c.obj.d -o CMakeFiles\HW_5_2.dir\CH_code\ch5\HW_5_2.c.obj -c C:\Users\bestc\CLionProjects\C-language\CH_code\ch5\HW_5_2.c

CMakeFiles/HW_5_2.dir/CH_code/ch5/HW_5_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/HW_5_2.dir/CH_code/ch5/HW_5_2.c.i"
	"C:\PROGRA~1\JetBrains\CLion 2025.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\bestc\CLionProjects\C-language\CH_code\ch5\HW_5_2.c > CMakeFiles\HW_5_2.dir\CH_code\ch5\HW_5_2.c.i

CMakeFiles/HW_5_2.dir/CH_code/ch5/HW_5_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/HW_5_2.dir/CH_code/ch5/HW_5_2.c.s"
	"C:\PROGRA~1\JetBrains\CLion 2025.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\bestc\CLionProjects\C-language\CH_code\ch5\HW_5_2.c -o CMakeFiles\HW_5_2.dir\CH_code\ch5\HW_5_2.c.s

# Object files for target HW_5_2
HW_5_2_OBJECTS = \
"CMakeFiles/HW_5_2.dir/CH_code/ch5/HW_5_2.c.obj"

# External object files for target HW_5_2
HW_5_2_EXTERNAL_OBJECTS =

HW_5_2.exe: CMakeFiles/HW_5_2.dir/CH_code/ch5/HW_5_2.c.obj
HW_5_2.exe: CMakeFiles/HW_5_2.dir/build.make
HW_5_2.exe: CMakeFiles/HW_5_2.dir/linkLibs.rsp
HW_5_2.exe: CMakeFiles/HW_5_2.dir/objects1.rsp
HW_5_2.exe: CMakeFiles/HW_5_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\bestc\CLionProjects\C-language\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable HW_5_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HW_5_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW_5_2.dir/build: HW_5_2.exe
.PHONY : CMakeFiles/HW_5_2.dir/build

CMakeFiles/HW_5_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HW_5_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HW_5_2.dir/clean

CMakeFiles/HW_5_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\bestc\CLionProjects\C-language C:\Users\bestc\CLionProjects\C-language C:\Users\bestc\CLionProjects\C-language\cmake-build-debug C:\Users\bestc\CLionProjects\C-language\cmake-build-debug C:\Users\bestc\CLionProjects\C-language\cmake-build-debug\CMakeFiles\HW_5_2.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/HW_5_2.dir/depend

