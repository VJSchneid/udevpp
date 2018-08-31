set(INSTALL_FILES
    udev++.hpp
    enumeration.hpp
    udev.hpp
)

set(INSTALL_DIRECTORIES
    udev++
)

install(FILES ${INSTALL_FILES} DESTINATION include)
install(DIRECTORY ${INSTALL_DIRECTORIES} DESTINATION include)
