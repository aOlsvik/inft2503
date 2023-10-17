cmake_minimum_required(VERSION 3.24)
project(task3)

set(CMAKE_CXX_STANDARD 17)

add_executable(taskB src/taskB.cpp include/taskA.hpp)
add_executable(taskC src/taskC.cpp include/commodity.hpp)
add_executable(taskD src/taskD.cpp)