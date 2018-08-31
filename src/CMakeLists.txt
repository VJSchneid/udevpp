add_subdirectory(udev)
add_subdirectory(enumeration)

add_library(udev++
    $<TARGET_OBJECTS:udev++_udev>
    $<TARGET_OBJECTS:udev++_enumeration>
)
