#include "object.hpp"

std::ostream& mpvm::operator<<(std::ostream& out, const Object& obj) {
    return obj._display(out);
}

mpvm::Object* mpvm::Object::operator+(Object* obj) {
    return _add(obj);
}

mpvm::Object* mpvm::Object::operator>(Object* obj) {
    return _greater(obj);
}

mpvm::Object* mpvm::Object::operator<(Object* obj) {
    return _less(obj);
}

mpvm::Object* mpvm::Object::operator==(Object* obj) {
    return _equal(obj);
}

mpvm::Object* mpvm::Object::operator!=(Object* obj) {
    return _not_equal(obj);
}

mpvm::Object* mpvm::Object::operator>=(Object* obj) {
    return _geq(obj);
}

mpvm::Object* mpvm::Object::operator<=(Object* obj) {
    return _leq(obj);
}