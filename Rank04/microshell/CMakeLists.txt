cmake_minimum_required(VERSION 3.27)
project(microshell C)

set(CMAKE_C_STANDARD 11)

add_executable(microshell
        microshell.c
        handle_parsing.c
        microshell.h)

target_compile_options(microshell PRIVATE -g -Wall -Wextra -Werror)