// string.cpp

#include "string.hpp"
#include <string.h>
#include <iomanip>

mpvm::String::String(const char* x, bool ascii) : _ascii(ascii){
    _length = strlen(x);
    _value = new char[_length];

    strcpy(_value, x);
}

mpvm::String::String(const char* x, const int length, bool ascii) : _ascii(ascii) {
    // _length = strlen(x);
    _length = length;
    _value = new char[_length];

    for (int i = 0; i < length; i++) {
        _value[i] = x[i];
    }
}

std::ostream& mpvm::String::_display(std::ostream& os) const {
    if (!_ascii) {
        os << "b\"" << std::hex ;
        for (int i = 0; i < _length; i++) {
            os << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(_value[i] & 0xff);
        }
        os << "\"" << std::dec << std::endl;
    }else {
        os <<_value;
    }
    return os;
}