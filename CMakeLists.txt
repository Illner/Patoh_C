cmake_minimum_required(VERSION 3.23)
project(Patoh)

set (CMAKE_CXX_STANDARD 20)

add_executable(Patoh main.cpp)

find_library (PATOH_MAC_OS_APPLE_SILICON_LIBRARY libpatoh "./macOS")
target_link_libraries (Patoh LINK_PUBLIC ${PATOH_MAC_OS_APPLE_SILICON_LIBRARY})
