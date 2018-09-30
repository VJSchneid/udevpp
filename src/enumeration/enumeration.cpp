#include <udev++/enumeration.hpp>

#include <exception>

namespace uv {
    enumeration::enumeration() {
        init_base();
    }

    enumeration::enumeration(const udev &core_value): core(core_value) {
        init_base();
    }

    enumeration::enumeration(const enumeration &value) noexcept: core(value.core) {
        base = value.base;
        udev_enumerate_ref(base);
    }

    enumeration::enumeration(enumeration &&value) noexcept: core(std::move(value.core)) {
        base = value.base;
        value.base = nullptr;
    }

    enumeration::~enumeration() {
        udev_enumerate_unref(base);
    }

    enumeration &enumeration::operator=(const enumeration &value) noexcept {
        udev_enumerate_unref(base);
        core = value.core;
        base = value.base;
        udev_enumerate_ref(base);

        return *this;
    }

    enumeration &enumeration::operator=(enumeration &&value) noexcept {
        std::swap(core, value.core);
        std::swap(base, value.base);

        return *this;
    }

    void enumeration::init_base() noexcept(false) {
        base = udev_enumerate_new(core.base);
        if (base == nullptr) {
            std::bad_alloc();
        }
    }

    bool enumeration::scan_devices() noexcept {
        return udev_enumerate_scan_devices(base) == 0;
    }

    bool enumeration::scan_subsystems() noexcept {
        return udev_enumerate_scan_subsystems(base) == 0;
    }


    enumeration::Iterator enumeration::begin() {
        udev_list_entry *list_entry;
        auto devices = udev_enumerate_get_list_entry(base);
        return Iterator(devices);
    }

    enumeration::Iterator enumeration::end() {
        return Iterator(nullptr);
    }
}
