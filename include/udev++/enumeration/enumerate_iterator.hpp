#pragma once

#include <iterator>

namespace uv::enumeration_base {

    class Device;

    class enumerate_iterator {

        typedef std::forward_iterator_tag iterator_category;
        typedef Device value_type;
        typedef std::size_t difference_type;
        typedef Device* pointer;
        typedef Device& reference;
    };
}
