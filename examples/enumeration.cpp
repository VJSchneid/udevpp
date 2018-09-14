#include <iostream>
#include <udev++.hpp>

int main() {
    uv::enumeration test;
    test.add_match(!uv::enumeration_base::match::subsystem("blabla"));
}
