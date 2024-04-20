cmake_minimum_required(VERSION 3.27)
project(n_queens LANGUAGES C)

add_executable(n_queens n_queens.c)

#target_compile_options(n_queens PRIVATE -g -Wall -Wextra -Werror)
target_compile_options(n_queens PRIVATE -g)
