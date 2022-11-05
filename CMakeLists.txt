cmake_minimum_required(VERSION 3.14)
project(Patoh)

set (CMAKE_CXX_STANDARD 20)

add_executable(Patoh main.cpp)

target_link_libraries(Patoh ${CMAKE_SOURCE_DIR}/Linux/libpatoh.a)
