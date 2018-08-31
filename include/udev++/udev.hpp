#pragma once

#include <libudev.h>

namespace uv {
    class enumeration;

    class udev {
    public:
        udev();
        udev(const udev &value) noexcept;
        udev(udev &&value) noexcept;

        ~udev() noexcept;

        udev& operator=(const udev &value) noexcept;
        udev& operator=(udev &&value) noexcept;

    private:
        inline void init_base() noexcept(false);

        friend uv::enumeration;

        ::udev *base;

    };
}
