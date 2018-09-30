#include <udev++/enumeration/match.hpp>

namespace uv::enumeration_base::match {

    subsystem::subsystem(const char *subsystem): value(subsystem) {}

    subsystem &subsystem::operator!() {
        nomatch = !nomatch;
        return *this;
    }

    sys_attribute::sys_attribute(const char *sysattr): sysattr(sysattr) {}

    sys_attribute::sys_attribute(const char *sysattr, const char *value)
            :sysattr(sysattr), value(value) {}

    sys_attribute &sys_attribute::operator!() {
        nomatch = !nomatch;
        return *this;
    }

    property::property(const char *prop): prop(prop) {}

    property::property(const char *prop, const char *value)
            :prop(prop), value(value) {}

    tag::tag(const char *tag): value(tag) {}

    sysname::sysname(const char *name): value(name) {}
}
