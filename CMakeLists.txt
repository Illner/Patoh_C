cmake_minimum_required(VERSION 3.14)
project(Patoh)

set (CMAKE_CXX_STANDARD 20)

add_executable(Patoh main.cpp)

# macOS
IF (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    # Apple Silicon
    IF (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "arm64")
        message("Operating system: macOS (Apple Silicon)")
        target_link_libraries(Patoh "${CMAKE_SOURCE_DIR}/macOS/Apple Silicon/libpatoh.a")
    # Intel
    ELSE ()
        message("Operating system: macOS (Intel)")
        target_link_libraries(Patoh "${CMAKE_SOURCE_DIR}/macOS/Intel/libpatoh.a")
    ENDIF ()

# Windows
ELSEIF ((${CMAKE_SYSTEM_NAME} STREQUAL "Windows") OR (CMAKE_SYSTEM_NAME STREQUAL "CYGWIN"))
    message("Operating system: Windows")
    message("PaToH is not supported!")

# Linux
ELSEIF (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message("Operating system: Linux")
    target_link_libraries(Patoh ${CMAKE_SOURCE_DIR}/Linux/libpatoh.a)

# Undefined
ELSE()
    message(FATAL_ERROR "Your operating system (" ${CMAKE_SYSTEM_NAME} ") is not supported!")
ENDIF()
