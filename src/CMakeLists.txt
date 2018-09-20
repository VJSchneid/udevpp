add_subdirectory(udev)
add_subdirectory(enumeration)
add_subdirectory(device)

add_library(udev++
    $<TARGET_OBJECTS:udev++_udev>
    $<TARGET_OBJECTS:udev++_enumeration>
    $<TARGET_OBJECTS:udev++_device>
)

install(TARGETS udev++ DESTINATION lib)
