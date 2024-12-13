
#include "integer.hpp"

std::ostream& mpvm::Integer::_display(std::ostream& os) const {
    os << _value;
    return os;
}

std::ostream& mpvm::Long::_display(std::ostream& os) const {
    os << _value;
    return os;
}