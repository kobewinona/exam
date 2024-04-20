cmake_minimum_required(VERSION 3.27)
project(rip LANGUAGES C)

add_executable(rip rip.c)

target_compile_options(rip PRIVATE -g -Wall -Wextra -Werror)
