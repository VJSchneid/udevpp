cmake_minimum_required(VERSION 3.8.2)
project(udev++)
set(PROJECT_VERSION "0.0.1")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include(cmake/cpack.cmake)
include(cmake/udev.cmake)

add_subdirectory(cmake)
add_subdirectory(include)

include_directories(
    ${UDEV_INCLUDE_DIRS}
    include
)

add_subdirectory(src)

option(BUILD_EXAMPLES "build examples")
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
