
#include "tuple_object.hpp"
#include <iostream>

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

mpvm::Object* mpvm::Tuple::operator[](int index) const {
    if (index > _list.size()) {
        std::cerr << "Index out of range" << std::endl;
    }
    return _list[index];
}