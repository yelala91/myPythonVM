
#include "tuple_object.hpp"
#include <iostream>

mpvm::Object* mpvm::Tuple::operator[](int index) const {
    if (index > _list.size()) {
        std::cerr << "Index out of range" << std::endl;
    }
    return _list[index];
}

mpvm::TupleKlass* mpvm::TupleKlass::_instance = nullptr;

mpvm::TupleKlass* mpvm::TupleKlass::get_instance() {
    if (_instance == nullptr) {
        _instance = new TupleKlass();
    }
    return _instance;
}

void mpvm::TupleKlass::_display(std::ostream& out, Object* obj) const {
    Tuple* tuple = static_cast<Tuple*>(obj);
    out << "(";
    for (int i = 0; i < tuple->size(); i++) {
        out << *tuple->get(i);
        if (i != tuple->size() - 1) {
            out << ", ";
        }
    }
    out << ")";
}