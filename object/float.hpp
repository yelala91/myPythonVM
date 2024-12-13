// integer.hpp

/*
    The class float for mpvm.

    created on 2024/12/4 by yezq.
*/

#ifndef _FLOAT_HPP
#define _FLOAT_HPP

#include "object.hpp"

namespace mpvm{

    class Float : public Object {
    private:
        float _value;

    public:
        Integer(float x) : _value(x) {}
        inline int value() const {return _value;}
    };

    class Double : public Object {
    private:
        float _value;

    public:
        Integer(double x) : _value(x) {}
        inline int value() const {return _value;}
    };

}
#endif