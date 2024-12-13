#include "ellipsis_object.hpp"

std::ostream&  mpvm::Ellipsis::_display(std::ostream& os) const {
    os << "...";
    return os;
}