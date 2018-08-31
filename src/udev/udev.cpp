#include <udev++/udev.hpp>

#include <exception>

namespace uv {
    udev::udev() {
        init_base();
    }

    udev::udev(const udev &value) noexcept {
        base = value.base;
        udev_ref(base);
    }

    udev::udev(udev &&value) noexcept {
        base = value.base;
        value.base = nullptr;
    }

    udev::~udev() noexcept {
        udev_unref(base);
    }

    udev &udev::operator=(const udev &value) noexcept {
        udev_unref(base);
        base = value.base;
        udev_ref(base);

        return *this;
    }

    udev &udev::operator=(udev &&value) noexcept {
        std::swap(base, value.base);
        return *this;
    }

    void udev::init_base() {
        base = udev_new();
        if (base == nullptr) {
            throw std::bad_alloc();
        }
    }
}
