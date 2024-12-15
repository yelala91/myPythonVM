#include "object.hpp"

std::ostream& mpvm::operator<<(std::ostream& out, Object& obj) {
    obj.klass()->_display(out, &obj);
    return out;
}

mpvm::Object* mpvm::add(Object* x, Object* y) {
    return x->_klass->_add(x, y);
}

mpvm::Object* mpvm::sub(Object* x, Object* y) {
    return x->_klass->_sub(x, y);
}

mpvm::Object* mpvm::mul(Object* x, Object* y) {
    return x->_klass->_mul(x, y);
}

mpvm::Object* mpvm::div(Object* x, Object* y) {
    return x->_klass->_div(x, y);
}

mpvm::Object* mpvm::mod(Object* x, Object* y) {
    return x->_klass->_mod(x, y);
}

mpvm::Object* mpvm::less(Object* x, Object* y) {
    return x->_klass->_less(x, y);
}

mpvm::Object* mpvm::equal(Object* x, Object* y) {
    return x->_klass->_equal(x, y);
}

mpvm::Object* mpvm::not_equal(Object* x, Object* y) {
    return x->_klass->_not_equal(x, y);
}

mpvm::Object* mpvm::greater(Object* x, Object* y) {
    return x->_klass->_greater(x, y);
}

mpvm::Object* mpvm::geq(Object* x, Object* y) {
    return x->_klass->_geq(x, y);
}

mpvm::Object* mpvm::leq(Object* x, Object* y) {
    return x->_klass->_leq(x, y);
}