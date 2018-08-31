configure_file(udev++Config.cmake.in udev++Config.cmake @ONLY)
configure_file(udev++ConfigVersion.cmake.in udev++ConfigVersion.cmake @ONLY)

set(INSTALL_FILES
    ${CMAKE_CURRENT_BINARY_DIR}/udev++Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/udev++ConfigVersion.cmake
)

install(FILES ${INSTALL_FILES} DESTINATION lib/cmake/udev++/)
