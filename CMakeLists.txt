cmake_minimum_required(VERSION 3.24)
project(todoapp C)

set(CMAKE_C_STANDARD 11)

set(SRC
    src/main.c
    src/todos.h
    src/todos.c)

add_executable(todoapp ${SRC})
