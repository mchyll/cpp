cmake_minimum_required(VERSION 2.8)

project(oving_7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(oppgave_1 oppgave_1.cpp fraction.cpp)
add_executable(oppgave_2 oppgave_2.cpp set.cpp)
