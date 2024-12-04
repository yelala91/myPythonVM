// string.cpp

#include "string.hpp"
#include <string.h>

mpvm::String::String(const char* x) {
    _length = strlen(x);
    _value = new char[_length];

    strcpy(_value, x);
}

mpvm::String::String(const char* x, const int length) {
    _length = strlen(x);
    _value = new char[_length];

    for (int i = 0; i < length; i++) {
        _value[i] = x[i];
    }
}