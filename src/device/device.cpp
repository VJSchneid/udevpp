#include <udev++/device.hpp>
#include <utility>

namespace uv {
    device::device(const device &value) noexcept: core(value.core) {
        udev_device_ref(value.base);
        base = value.base;
    }

    device::device(device &&value) noexcept: core(std::move(value.core)) {
        base = value.base;
        value.base = nullptr;
    }

    device::device(const udev &core, udev_device *value) noexcept: core(core) {
        base = value;
    }

    device::~device() {
        udev_device_unref(base);
    }

    device& device::operator=(const device &value) noexcept {
        udev_device_unref(base);
        core = value.core;
        udev_device_ref(value.base);
        base = value.base;

        return *this;
    }

    device& device::operator=(device &&value) noexcept {
        std::swap(core, value.core);
        std::swap(base, value.base);

        return *this;
    }

    const char *device::get_sysname() const noexcept {
        return udev_device_get_sysname(base);
    }

    std::optional<const char *> device::get_sysattribute(const char *name) const noexcept {
        auto value = udev_device_get_sysattr_value(base, name);
        if (value == nullptr) {
            return std::nullopt;
        }
        return value;
    }

    device device::make_from_syspath(const char *syspath, const udev &core) {
        auto dev = udev_device_new_from_syspath(core.base, syspath);
        return device(core, dev);
    }
}
