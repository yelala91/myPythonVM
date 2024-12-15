// string.cpp

#include "string.hpp"
#include <string.h>
#include <iomanip>
#include "bool_object.hpp"

mpvm::String::String(const char* x, bool ascii) : _ascii(ascii){
    _length = strlen(x);
    _value = std::move(std::string(x, _length));

    set_klass(STRING_KLASS);

    // strcpy(_value, x);
}

mpvm::String::String(const char* x, const int length, bool ascii) : _ascii(ascii) {
    // _length = strlen(x);
    _length = length;
    // _value = new char[_length];
    _value = std::move(std::string(x, length));
    
    set_klass(STRING_KLASS);

    // for (int i = 0; i < length; i++) {
    //     _value[i] = x[i];
    // }
}

mpvm::StringKlass* mpvm::StringKlass::_instance = nullptr;

mpvm::StringKlass* mpvm::StringKlass::get_instance() {
    if (!_instance) {
        _instance = new StringKlass();
    }

    return _instance;
}

void mpvm::StringKlass::_display(std::ostream& os, Object* obj) const {
    String* sobj = static_cast<String*>(obj);
    if (!sobj->_ascii) {
        os << "b\"" << std::hex ;
        for (int i = 0; i < sobj->_length; i++) {
            os << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(sobj->_value[i] & 0xff);
        }
        os << "\"" << std::dec << std::endl;
    }else {
        os << sobj->_value;
    }
}

mpvm::Object* mpvm::StringKlass::_equal(Object* x, Object* y) const {
    mpvm::String* sx = static_cast<mpvm::String*>(x);
    mpvm::String* sy = static_cast<mpvm::String*>(y);

    if (sx->value() == sy->value()) {
        return mpvm::TRUE_OBJECT;
    } else {
        return mpvm::FALSE_OBJECT;
    }
}

mpvm::Object* mpvm::StringKlass::_not_equal(Object* x, Object* y) const {
    
    if (_equal(x, y) == mpvm::TRUE_OBJECT) {
        return mpvm::FALSE_OBJECT;
    } else {
        return mpvm::TRUE_OBJECT;
    }
}