
#include "none_object.hpp"

mpvm::NoneObject* mpvm::NoneObject::_instance = nullptr;

mpvm::NoneObject* mpvm::NoneObject::get_instance() {
    if (!_instance) {
        _instance = new NoneObject();
    }
    return _instance;
}

void mpvm::NoneKlass::_display(std::ostream& os, Object* obj) const {
    os << "None";
}

mpvm::NoneKlass* mpvm::NoneKlass::_instance = nullptr;

mpvm::NoneKlass* mpvm::NoneKlass::get_instance() {
    if (!_instance) {
        _instance = new NoneKlass();
    }
    return _instance;
}