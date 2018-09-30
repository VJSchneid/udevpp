#pragma once

#include "udev.hpp"
#include <optional>

namespace uv {
    class device {
    public:
        device(const device &value) noexcept;
        device(device &&value) noexcept;

        ~device() noexcept;

        device& operator=(const device &value) noexcept;
        device& operator=(device &&value) noexcept;

        const char *get_sysname() const noexcept;
        std::optional<const char *> get_sysattribute(const char *name) const noexcept;
        bool set_sysattribute(const char *name, const char *value) noexcept;

        static device make_from_syspath(const char *syspath, const udev &core = udev());

    private:
        device(const udev &core, udev_device *value) noexcept;

        udev core;
        udev_device *base;
    };
}
