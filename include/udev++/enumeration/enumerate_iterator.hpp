#pragma once

#include <iterator>
#include <libudev.h>

namespace uv {
    class enumeration;
}

namespace uv::enumeration_base {

    class Device;

    class enumerate_iterator {
        typedef std::forward_iterator_tag iterator_category;
        typedef const char* value_type;
        typedef std::size_t difference_type;
        typedef value_type* pointer;
        typedef value_type/*&*/ reference;

        friend enumeration;

    public:
        bool operator==(const enumerate_iterator &iterator) noexcept {
            return current == iterator.current;
        }

        bool operator!=(const enumerate_iterator &iterator) noexcept {
            return current != iterator.current;
        }

        enumerate_iterator operator++(int) {
            return ++(*this);
        }

        enumerate_iterator& operator++() {
            current = udev_list_entry_get_next(current);
            return *this;
        }

        reference operator*() {
            return udev_list_entry_get_name(current);
        }

    private:
        explicit enumerate_iterator(udev_list_entry *list_entry): current(list_entry) {}

        udev_list_entry *current;

    };
}
