# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /cygdrive/c/Users/constantin.andreescu/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/constantin.andreescu/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/y/SO/Tema1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/y/SO/Tema1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tema1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tema1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tema1.dir/flags.make

CMakeFiles/Tema1.dir/struct.c.o: CMakeFiles/Tema1.dir/flags.make
CMakeFiles/Tema1.dir/struct.c.o: ../struct.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/y/SO/Tema1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Tema1.dir/struct.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tema1.dir/struct.c.o   -c /cygdrive/y/SO/Tema1/struct.c

CMakeFiles/Tema1.dir/struct.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tema1.dir/struct.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/y/SO/Tema1/struct.c > CMakeFiles/Tema1.dir/struct.c.i

CMakeFiles/Tema1.dir/struct.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tema1.dir/struct.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/y/SO/Tema1/struct.c -o CMakeFiles/Tema1.dir/struct.c.s

CMakeFiles/Tema1.dir/struct.c.o.requires:

.PHONY : CMakeFiles/Tema1.dir/struct.c.o.requires

CMakeFiles/Tema1.dir/struct.c.o.provides: CMakeFiles/Tema1.dir/struct.c.o.requires
	$(MAKE) -f CMakeFiles/Tema1.dir/build.make CMakeFiles/Tema1.dir/struct.c.o.provides.build
.PHONY : CMakeFiles/Tema1.dir/struct.c.o.provides

CMakeFiles/Tema1.dir/struct.c.o.provides.build: CMakeFiles/Tema1.dir/struct.c.o


CMakeFiles/Tema1.dir/main.c.o: CMakeFiles/Tema1.dir/flags.make
CMakeFiles/Tema1.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/y/SO/Tema1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Tema1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tema1.dir/main.c.o   -c /cygdrive/y/SO/Tema1/main.c

CMakeFiles/Tema1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tema1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/y/SO/Tema1/main.c > CMakeFiles/Tema1.dir/main.c.i

CMakeFiles/Tema1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tema1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/y/SO/Tema1/main.c -o CMakeFiles/Tema1.dir/main.c.s

CMakeFiles/Tema1.dir/main.c.o.requires:

.PHONY : CMakeFiles/Tema1.dir/main.c.o.requires

CMakeFiles/Tema1.dir/main.c.o.provides: CMakeFiles/Tema1.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Tema1.dir/build.make CMakeFiles/Tema1.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Tema1.dir/main.c.o.provides

CMakeFiles/Tema1.dir/main.c.o.provides.build: CMakeFiles/Tema1.dir/main.c.o


CMakeFiles/Tema1.dir/debugging_aux.c.o: CMakeFiles/Tema1.dir/flags.make
CMakeFiles/Tema1.dir/debugging_aux.c.o: ../debugging_aux.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/y/SO/Tema1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Tema1.dir/debugging_aux.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tema1.dir/debugging_aux.c.o   -c /cygdrive/y/SO/Tema1/debugging_aux.c

CMakeFiles/Tema1.dir/debugging_aux.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tema1.dir/debugging_aux.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/y/SO/Tema1/debugging_aux.c > CMakeFiles/Tema1.dir/debugging_aux.c.i

CMakeFiles/Tema1.dir/debugging_aux.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tema1.dir/debugging_aux.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/y/SO/Tema1/debugging_aux.c -o CMakeFiles/Tema1.dir/debugging_aux.c.s

CMakeFiles/Tema1.dir/debugging_aux.c.o.requires:

.PHONY : CMakeFiles/Tema1.dir/debugging_aux.c.o.requires

CMakeFiles/Tema1.dir/debugging_aux.c.o.provides: CMakeFiles/Tema1.dir/debugging_aux.c.o.requires
	$(MAKE) -f CMakeFiles/Tema1.dir/build.make CMakeFiles/Tema1.dir/debugging_aux.c.o.provides.build
.PHONY : CMakeFiles/Tema1.dir/debugging_aux.c.o.provides

CMakeFiles/Tema1.dir/debugging_aux.c.o.provides.build: CMakeFiles/Tema1.dir/debugging_aux.c.o


CMakeFiles/Tema1.dir/hash_table.c.o: CMakeFiles/Tema1.dir/flags.make
CMakeFiles/Tema1.dir/hash_table.c.o: ../hash_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/y/SO/Tema1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Tema1.dir/hash_table.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tema1.dir/hash_table.c.o   -c /cygdrive/y/SO/Tema1/hash_table.c

CMakeFiles/Tema1.dir/hash_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tema1.dir/hash_table.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/y/SO/Tema1/hash_table.c > CMakeFiles/Tema1.dir/hash_table.c.i

CMakeFiles/Tema1.dir/hash_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tema1.dir/hash_table.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/y/SO/Tema1/hash_table.c -o CMakeFiles/Tema1.dir/hash_table.c.s

CMakeFiles/Tema1.dir/hash_table.c.o.requires:

.PHONY : CMakeFiles/Tema1.dir/hash_table.c.o.requires

CMakeFiles/Tema1.dir/hash_table.c.o.provides: CMakeFiles/Tema1.dir/hash_table.c.o.requires
	$(MAKE) -f CMakeFiles/Tema1.dir/build.make CMakeFiles/Tema1.dir/hash_table.c.o.provides.build
.PHONY : CMakeFiles/Tema1.dir/hash_table.c.o.provides

CMakeFiles/Tema1.dir/hash_table.c.o.provides.build: CMakeFiles/Tema1.dir/hash_table.c.o


CMakeFiles/Tema1.dir/log_service.c.o: CMakeFiles/Tema1.dir/flags.make
CMakeFiles/Tema1.dir/log_service.c.o: ../log_service.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/y/SO/Tema1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Tema1.dir/log_service.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tema1.dir/log_service.c.o   -c /cygdrive/y/SO/Tema1/log_service.c

CMakeFiles/Tema1.dir/log_service.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tema1.dir/log_service.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/y/SO/Tema1/log_service.c > CMakeFiles/Tema1.dir/log_service.c.i

CMakeFiles/Tema1.dir/log_service.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tema1.dir/log_service.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/y/SO/Tema1/log_service.c -o CMakeFiles/Tema1.dir/log_service.c.s

CMakeFiles/Tema1.dir/log_service.c.o.requires:

.PHONY : CMakeFiles/Tema1.dir/log_service.c.o.requires

CMakeFiles/Tema1.dir/log_service.c.o.provides: CMakeFiles/Tema1.dir/log_service.c.o.requires
	$(MAKE) -f CMakeFiles/Tema1.dir/build.make CMakeFiles/Tema1.dir/log_service.c.o.provides.build
.PHONY : CMakeFiles/Tema1.dir/log_service.c.o.provides

CMakeFiles/Tema1.dir/log_service.c.o.provides.build: CMakeFiles/Tema1.dir/log_service.c.o


CMakeFiles/Tema1.dir/io_aux.c.o: CMakeFiles/Tema1.dir/flags.make
CMakeFiles/Tema1.dir/io_aux.c.o: ../io_aux.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/y/SO/Tema1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Tema1.dir/io_aux.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tema1.dir/io_aux.c.o   -c /cygdrive/y/SO/Tema1/io_aux.c

CMakeFiles/Tema1.dir/io_aux.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tema1.dir/io_aux.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/y/SO/Tema1/io_aux.c > CMakeFiles/Tema1.dir/io_aux.c.i

CMakeFiles/Tema1.dir/io_aux.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tema1.dir/io_aux.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/y/SO/Tema1/io_aux.c -o CMakeFiles/Tema1.dir/io_aux.c.s

CMakeFiles/Tema1.dir/io_aux.c.o.requires:

.PHONY : CMakeFiles/Tema1.dir/io_aux.c.o.requires

CMakeFiles/Tema1.dir/io_aux.c.o.provides: CMakeFiles/Tema1.dir/io_aux.c.o.requires
	$(MAKE) -f CMakeFiles/Tema1.dir/build.make CMakeFiles/Tema1.dir/io_aux.c.o.provides.build
.PHONY : CMakeFiles/Tema1.dir/io_aux.c.o.provides

CMakeFiles/Tema1.dir/io_aux.c.o.provides.build: CMakeFiles/Tema1.dir/io_aux.c.o


# Object files for target Tema1
Tema1_OBJECTS = \
"CMakeFiles/Tema1.dir/struct.c.o" \
"CMakeFiles/Tema1.dir/main.c.o" \
"CMakeFiles/Tema1.dir/debugging_aux.c.o" \
"CMakeFiles/Tema1.dir/hash_table.c.o" \
"CMakeFiles/Tema1.dir/log_service.c.o" \
"CMakeFiles/Tema1.dir/io_aux.c.o"

# External object files for target Tema1
Tema1_EXTERNAL_OBJECTS =

Tema1.exe: CMakeFiles/Tema1.dir/struct.c.o
Tema1.exe: CMakeFiles/Tema1.dir/main.c.o
Tema1.exe: CMakeFiles/Tema1.dir/debugging_aux.c.o
Tema1.exe: CMakeFiles/Tema1.dir/hash_table.c.o
Tema1.exe: CMakeFiles/Tema1.dir/log_service.c.o
Tema1.exe: CMakeFiles/Tema1.dir/io_aux.c.o
Tema1.exe: CMakeFiles/Tema1.dir/build.make
Tema1.exe: CMakeFiles/Tema1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/y/SO/Tema1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable Tema1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tema1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tema1.dir/build: Tema1.exe

.PHONY : CMakeFiles/Tema1.dir/build

CMakeFiles/Tema1.dir/requires: CMakeFiles/Tema1.dir/struct.c.o.requires
CMakeFiles/Tema1.dir/requires: CMakeFiles/Tema1.dir/main.c.o.requires
CMakeFiles/Tema1.dir/requires: CMakeFiles/Tema1.dir/debugging_aux.c.o.requires
CMakeFiles/Tema1.dir/requires: CMakeFiles/Tema1.dir/hash_table.c.o.requires
CMakeFiles/Tema1.dir/requires: CMakeFiles/Tema1.dir/log_service.c.o.requires
CMakeFiles/Tema1.dir/requires: CMakeFiles/Tema1.dir/io_aux.c.o.requires

.PHONY : CMakeFiles/Tema1.dir/requires

CMakeFiles/Tema1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tema1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tema1.dir/clean

CMakeFiles/Tema1.dir/depend:
	cd /cygdrive/y/SO/Tema1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/y/SO/Tema1 /cygdrive/y/SO/Tema1 /cygdrive/y/SO/Tema1/cmake-build-debug /cygdrive/y/SO/Tema1/cmake-build-debug /cygdrive/y/SO/Tema1/cmake-build-debug/CMakeFiles/Tema1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tema1.dir/depend
