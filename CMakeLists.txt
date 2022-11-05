cmake_minimum_required(VERSION 3.23)
project(Patoh)

set (CMAKE_CXX_STANDARD 20)

add_executable(Patoh main.cpp)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(Patoh ${CMAKE_SOURCE_DIR}/macOS/libpatoh.a)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(Patoh ${CMAKE_SOURCE_DIR}/Linux/libpatoh.a)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
