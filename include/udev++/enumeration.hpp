#pragma once

#include <udev++/udev.hpp>
#include <udev++/enumeration/enumerate_iterator.hpp>

namespace uv {

    class enumeration {
    public:
        typedef enumeration_base::enumerate_iterator Iterator;

        enumeration();
        enumeration(const udev &core_value);
        enumeration(const enumeration &value) noexcept;
        enumeration(enumeration &&value) noexcept;

        ~enumeration() noexcept;

        enumeration& operator=(const enumeration &value) noexcept;
        enumeration& operator=(enumeration &&value) noexcept;

        template<typename MatchType>
        void add_match(const MatchType &match) {
            match.apply(base);
        }

        constexpr udev &get_udev() noexcept {
            return core;
        }

        Iterator begin();
        Iterator end();

    private:
        inline void init_base() noexcept(false);

        udev core;
        udev_enumerate *base;
    };

}
