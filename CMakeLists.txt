cmake_minimum_required(VERSION 3.0.2)

PROJECT(mydb)

option(ENABLE_TEST "Enable test program build" ON)

set(CMAKE_CXX_FLAGS "--std=c++11 -O3 -Wall -Wextra ${CMAKE_CXX_FLAGS}")

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

include_directories(${CMAKE_SOURCE_DIR}/src)
add_subdirectory(src)