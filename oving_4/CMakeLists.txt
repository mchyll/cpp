cmake_minimum_required(VERSION 2.8)

project(oving_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

include(FindPkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(oppgave_1 oppgave_1.cpp)

add_executable(oppgave_2 oppgave_2.cpp)
target_link_libraries(oppgave_2 ${GTKMM_LIBRARIES})
