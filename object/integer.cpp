
#include "integer.hpp"
#include "bool_object.hpp"

void mpvm::IntegerKlass::_display(std::ostream& os, Object* obj) const {
    mpvm::Integer* iobj = static_cast<mpvm::Integer*>(obj);

    os << iobj->value();
}

mpvm::Object* mpvm::IntegerKlass::_add(Object* x, Object* y) const {
    mpvm::Integer* ix = static_cast<mpvm::Integer*>(x);
    mpvm::Integer* iy = static_cast<mpvm::Integer*>(y);

    return new Integer(ix->value() + iy->value());
}

mpvm::Object* mpvm::IntegerKlass::_sub(Object* x, Object* y) const {
    mpvm::Integer* ix = static_cast<mpvm::Integer*>(x);
    mpvm::Integer* iy = static_cast<mpvm::Integer*>(y);
    return new Integer(ix->value() - iy->value());
}

mpvm::Object* mpvm::IntegerKlass::_mul(Object* x, Object* y) const {
    mpvm::Integer* ix = static_cast<mpvm::Integer*>(x);
    mpvm::Integer* iy = static_cast<mpvm::Integer*>(y);
    return new Integer(ix->value() * iy->value());
}

mpvm::Object* mpvm::IntegerKlass::_div(Object* x, Object* y) const {
    mpvm::Integer* ix = static_cast<mpvm::Integer*>(x);
    mpvm::Integer* iy = static_cast<mpvm::Integer*>(y);
    return new Integer(ix->value() / iy->value());
}

mpvm::Object* mpvm::IntegerKlass::_mod(Object* x, Object* y) const {
    mpvm::Integer* ix = static_cast<mpvm::Integer*>(x);
    mpvm::Integer* iy = static_cast<mpvm::Integer*>(y);
    return new Integer(ix->value() % iy->value());
}

mpvm::Object* mpvm::IntegerKlass::_greater(Object* x, Object* y) const {
    mpvm::Integer* ix = static_cast<mpvm::Integer*>(x);
    mpvm::Integer* iy = static_cast<mpvm::Integer*>(y);
    if (ix->value() > iy->value()) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}

mpvm::Object* mpvm::IntegerKlass::_less(Object* x, Object* y) const {
    mpvm::Integer* ix = static_cast<mpvm::Integer*>(x);
    mpvm::Integer* iy = static_cast<mpvm::Integer*>(y);
    
    if (ix->value() < iy->value()) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}

mpvm::Object* mpvm::IntegerKlass::_equal(Object* x, Object* y) const {
    mpvm::Integer* ix = static_cast<mpvm::Integer*>(x);
    mpvm::Integer* iy = static_cast<mpvm::Integer*>(y);
    
    if (ix->value() == iy->value()) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}

mpvm::Object* mpvm::IntegerKlass::_not_equal(Object* x, Object* y) const {
    mpvm::Integer* ix = static_cast<mpvm::Integer*>(x);
    mpvm::Integer* iy = static_cast<mpvm::Integer*>(y);
    if (ix->value() != iy->value()) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}

mpvm::Object* mpvm::IntegerKlass::_geq(Object* x, Object* y) const {
    mpvm::Integer* ix = static_cast<mpvm::Integer*>(x);
    mpvm::Integer* iy = static_cast<mpvm::Integer*>(y);
    if (ix->value() >= iy->value()) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}
mpvm::Object* mpvm::IntegerKlass::_leq(Object* x, Object* y) const {
    mpvm::Integer* ix = static_cast<mpvm::Integer*>(x);
    mpvm::Integer* iy = static_cast<mpvm::Integer*>(y);
    if (ix->value() <= iy->value()) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}

mpvm::IntegerKlass* mpvm::IntegerKlass::_instance = nullptr;

mpvm::IntegerKlass* mpvm::IntegerKlass::get_instance() {
    if (_instance == nullptr) {
        _instance = new IntegerKlass();
    }
    return _instance;
}