
#include "bool_object.hpp"

mpvm::BoolObject* mpvm::BoolObject::_true_instance = nullptr;
mpvm::BoolObject* mpvm::BoolObject::_false_instance = nullptr;

mpvm::BoolKlass* mpvm::BoolKlass::_instance = nullptr;

void mpvm::BoolKlass::_display(std::ostream& os, mpvm::Object* obj) const {
    if (obj == mpvm::TRUE_OBJECT) {
        os << "True";
    } else if (obj == mpvm::FALSE_OBJECT){
        os << "False";
    } else {
        os << "Don't support Bool value" << std::endl;
    }
}

mpvm::BoolKlass* mpvm::BoolKlass::get_instance() {
    if (!_instance) {
        _instance = new BoolKlass();
    }

    return _instance;
}