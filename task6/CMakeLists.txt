cmake_minimum_required(VERSION 3.5)

project(task6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

add_executable(task6 main.cpp)
target_link_libraries(task6 ${Boost_LIBRARIES})
