cmake_minimum_required(VERSION 3.10)
include(GNUInstallDirs)

project(moderncpp-project)

add_compile_options("-O2")
set(CMAKE_CXX_STANDARD 17)
if (NOT CMAKE_BUILD_TYPE)
 set(CMAKE_BUILD_TYPE "Release")
endif()

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

add_executable(cpp-test main.cpp)
target_link_libraries(cpp-test pthread)