
#include "none_object.hpp"

std::ostream& mpvm::NoneObject::_display(std::ostream& os) const{
    return os << "None";
}