cmake_minimum_required(VERSION 3.5)

project(ex2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")

add_executable(ex2 main.cpp)
target_link_libraries(ex2 ${Boost_LIBRARIES})
