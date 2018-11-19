cmake_minimum_required(VERSION 2.8)

project(oving_6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(oppgave_1 oppgave_1.cpp)

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(oppgave_2 oppgave_2.cpp)
target_link_libraries(oppgave_2 ${Boost_LIBRARIES})
