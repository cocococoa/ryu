cmake_minimum_required(VERSION 3.10)

project(ryu LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)
