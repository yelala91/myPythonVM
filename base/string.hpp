// string.hpp

/*
    A string class for mpvm.

    created on 2024/12/4 by yezq.
*/


#ifndef _STRING_HPP
#define _STRING_HPP

#include "object.hpp"

namespace mpvm{

    class String : public Object {
    private:
        char* _value;
        int   _length;

    public:
        String(const char* x);
        String(const char* x, const int length);

        /* move */
        String(String&& other) noexcept : _value(other._value) {
            other._value = nullptr; 
        }

        String& operator=(String&& other) noexcept {
            if (this != &other) {
                delete[] _value; 
                _value = other._value; 
                other._value = nullptr;
            }
            return *this;
        }

        inline const char* value() const     {return _value;}
        inline int length() const            {return _length;}
    };
}


#endif