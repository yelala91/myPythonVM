#include "ellipsis_object.hpp"


mpvm::Ellipsis* mpvm::Ellipsis::_instance = nullptr;

mpvm::EllipsisKlass* mpvm::EllipsisKlass::_instance = nullptr;

void mpvm::EllipsisKlass::_display(std::ostream& os, Object* obj) const {
    os << "...";
}

mpvm::EllipsisKlass* mpvm::EllipsisKlass::get_instance() {
    if (_instance == nullptr) {
        _instance = new EllipsisKlass();
    }
    return _instance;
}