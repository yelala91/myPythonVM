
#include "tuple_object.hpp"

std::ostream& mpvm::Tuple::_display(std::ostream& os) const {
    os << '(';
    for (int i=0; i<_list.size(); i++) {
        os << *_list[i];
        if (i!=_list.size()-1) {
            os << ", ";
        }
    }
    os << ')';
    return os;
}