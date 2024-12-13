
#include "bool_object.hpp"

std::ostream& mpvm::BoolObject::_display(std::ostream& os) const {
    os << (_value? "True" : "False");
    return os;
}
