cmake_minimum_required(VERSION 3.0.0)
project(sfml-test VERSION 0.1.0)

include(CTest)
enable_testing()

# Find RVO libs
find_library(RVO_LIB RVO PATH_SUFFIXES Release)
find_library(RVO_LIB_DEBUG RVO PATH_SUFFIXES Debug)
find_path(RVO_INC RVO/RVO.h)

# Verify RVO Libs
if(NOT RVO_INC OR NOT RVO_LIB_DEBUG OR NOT RVO_INC)
    message(FATAL_ERROR "Failed to find library
        RVO Release: ${RVO_LIB}
        RVO Debug: ${RVO_LIB_DEBUG}
        RVO Include: ${RVO_INC}")
endif()
include_directories("${RVO_INC}")

# Find SFML libs
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics window system main)
add_compile_definitions(SFML_STATIC)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "Failed to find SFML Libraries")
endif()

if(WIN32)
    add_executable(sfml-test WIN32 main.cpp)
else()
    add_executable(sfml-test main.cpp)
endif()

target_link_libraries(
    sfml-test sfml-graphics sfml-window sfml-system sfml-main
    debug ${RVO_LIB_DEBUG} optimized ${RVO_LIB})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
