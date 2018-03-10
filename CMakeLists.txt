cmake_minimum_required(VERSION 3.9)
project(Tema1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        struct.c
        main.c
        debugging_aux.c
        hash_table.c
        log_service.c
        io_aux.c debugging_aux.h struct.h io_aux.h log_service.h std.h hash_table.h)

add_executable(Tema1 ${SOURCE_FILES})
