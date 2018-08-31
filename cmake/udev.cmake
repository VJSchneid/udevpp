find_library(UDEV_LIBRARIES udev)
if(NOT UDEV_LIBRARIES)
    message(FATAL_ERROR "Failed to find libudev")
endif()

find_path(UDEV_INCLUDE_DIRS "libudev.h")
if(NOT UDEV_INCLUDE_DIRS)
    message(FATAL_ERROR "Failed to find libudev include path")
endif()

message(STATUS "Found libudev")
