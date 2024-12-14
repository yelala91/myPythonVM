
#include "integer.hpp"
#include "bool_object.hpp"

std::ostream& mpvm::Integer::_display(std::ostream& os) const {
    os << _value;
    return os;
}

std::ostream& mpvm::Long::_display(std::ostream& os) const {
    os << _value;
    return os;
}

mpvm::Object* mpvm::Integer::_add(Object* other) const {
    mpvm::Integer* temp_int = static_cast<mpvm::Integer*>(other);

    return new mpvm::Integer(_value + temp_int->_value);
}

mpvm::Object* mpvm::Integer::_greater(Object* other) const {
    mpvm::Integer* temp_int = static_cast<mpvm::Integer*>(other);
    
    if (_value > temp_int->_value) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}

mpvm::Object* mpvm::Integer::_less(Object* other) const {
    mpvm::Integer* temp_int = static_cast<mpvm::Integer*>(other);
    if (_value < temp_int->_value) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}

mpvm::Object* mpvm::Integer::_equal(Object* other) const {
    mpvm::Integer* temp_int = static_cast<mpvm::Integer*>(other);
    if (_value == temp_int->_value) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}

mpvm::Object* mpvm::Integer::_not_equal(Object* other) const {
    mpvm::Integer* temp_int = static_cast<mpvm::Integer*>(other);
    if (_value != temp_int->_value) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}

mpvm::Object* mpvm::Integer::_geq(Object* other) const {
    mpvm::Integer* temp_int = static_cast<mpvm::Integer*>(other);
    if (_value >= temp_int->_value) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}
mpvm::Object* mpvm::Integer::_leq(Object* other) const {
    mpvm::Integer* temp_int = static_cast<mpvm::Integer*>(other);
    if (_value <= temp_int->_value) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}
