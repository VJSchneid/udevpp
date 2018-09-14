#pragma once

#include <string>
#include <udev++/enumeration.hpp>

namespace uv {
    class device;
}

namespace uv::enumeration_base::match {

    class subsystem {
        friend enumeration;
    public:
        explicit subsystem(const char *subsystem);

        subsystem &operator!();

    private:
        inline void apply(udev_enumerate *enumerate) const {
            if (nomatch) {
                udev_enumerate_add_nomatch_subsystem(enumerate, value);
            } else {
                udev_enumerate_add_match_subsystem(enumerate, value);
            }
        }

        const char *value;
        bool nomatch = false;
    };

    class sys_attribute {
        friend enumeration;
    public:
        explicit sys_attribute(const char *sysattr);
        sys_attribute(const char *sysattr, const char *value);

        sys_attribute &operator!();

    private:
        inline void apply(udev_enumerate *enumerate) const {
            if (nomatch) {
                udev_enumerate_add_nomatch_sysattr(enumerate, sysattr, value);
            } else {
                udev_enumerate_add_match_sysattr(enumerate, sysattr, value);
            }
        }

        const char *sysattr;
        const char *value = nullptr;
        bool nomatch = false;
    };

    class property {
        friend enumeration;
    public:
        explicit property(const char *prop);
        property(const char *prop, const char *value);

    private:
        inline void apply(udev_enumerate *enumerate) const {
            udev_enumerate_add_match_property(enumerate, prop, value);
        }

        const char *prop;
        const char *value = nullptr;
    };

    class tag {
        friend enumeration;
    public:
        tag(const char *tag);

    private:

        inline void apply(udev_enumerate *enumerate) const {
            udev_enumerate_add_match_tag(enumerate, value);
        }

        const char *value;
    };

    /*class parent {
        friend enumeration;
    public:
        parent(const device &value);

    private:
        inline void apply(udev_enumerate *enumerate) const {
            udev_enumerate_add_match_parent(enumerate, value.get_base());
        }

        const device &value;
    };*/

    class is_initialized {
        friend enumeration;
    private:
        inline void apply(udev_enumerate *enumerate) const {
            udev_enumerate_add_match_is_initialized(enumerate);
        }
    };

    class sysname {
        friend enumeration;
    public:
        sysname(const char *name);

    private:
        inline void apply(udev_enumerate *enumerate) const {
            udev_enumerate_add_match_sysname(enumerate, value);
        }

        const char *value;
    };

}
