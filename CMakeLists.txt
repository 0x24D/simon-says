cmake_minimum_required(VERSION 3.13)
project(simon_says)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lGL -lglfw -ldl")
find_package(glfw3 3.2 REQUIRED)

add_executable(simon_says src/main.cpp src/glad.c)

include_directories(simon_says /usr/include include)