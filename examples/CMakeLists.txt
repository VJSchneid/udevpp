link_libraries(
    ${UDEV_LIBRARIES}
    udev++
)
add_executable(example_enumeration enumeration.cpp)
