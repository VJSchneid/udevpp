#include <iostream>
#include <udev++.hpp>

int main() {
    uv::udev test1;
    uv::udev test2;
    test2 = std::move(test1);
}
