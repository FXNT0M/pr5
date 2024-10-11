cmake_minimum_required(VERSION 3.10)
project(user_process_util)

set(CMAKE_C_STANDARD 99)

add_executable(user_process_util src/main.c src/users.c src/processes.c src/help.c src/log.c src/error.c)
