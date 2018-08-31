#pragma once

#include <udev++/udev.hpp>

namespace uv {

    class enumeration {
    public:
        enumeration();
        enumeration(const udev &core_value);
        enumeration(const enumeration &value) noexcept;
        enumeration(enumeration &&value) noexcept;

        ~enumeration() noexcept;

        enumeration& operator=(const enumeration &value) noexcept;
        enumeration& operator=(enumeration &&value) noexcept;

        template<typename FilterType>
        void add_filter(const FilterType &filter, bool negative = false) {

        }

    private:
        inline void init_base() noexcept(false);

        udev core;
        udev_enumerate *base;
    };

}
