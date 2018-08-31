include(CPack)

# generic configuration
set(CPACK_PACKAGE_CONTACT "Viktor Schneider <info@vjs.io>")
set(CPACK_PACKAGE_VENDOR "VJSchneid")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/readme.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "C++17 Wrapper for libudev")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_STRIP_FILES YES)

# debian configuration
set(CPACK_DEBIAN_PACKAGE_NAME "libudev++-dev")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libstdc++6, libc6, libgcc1, libudev-dev")
