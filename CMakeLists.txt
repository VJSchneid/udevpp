cmake_minimum_required(VERSION 3.8.2)
project(udev++)
set(PROJECT_VERSION "0.0.1")

include(cmake/cpack.cmake)
include(cmake/udev.cmake)

add_subdirectory(cmake)
add_subdirectory(include)

include_directories(
    ${UDEV_INCLUDE_DIRS}
    include
)

add_subdirectory(src)
