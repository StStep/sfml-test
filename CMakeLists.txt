cmake_minimum_required(VERSION 3.0.0)
project(sfml-test VERSION 0.1.0)

include(CTest)
enable_testing()

# Find SFML libs
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 COMPONENTS graphics window system)
add_compile_definitions(SFML_STATIC)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "Failed to find SFML Libraries")
endif()

add_executable(sfml-test main.cpp)

target_link_libraries(sfml-test sfml-graphics sfml-window sfml-system)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
