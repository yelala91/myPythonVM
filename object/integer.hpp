// integer.hpp

/*
    The class int for mpvm.

    created on 2024/12/4 by yezq.
*/

#ifndef _INTEGER_HPP
#define _INTEGER_HPP

#include "object.hpp"

namespace mpvm{

    class Integer : public Object {
    private:
        int _value;

        std::ostream& _display(std::ostream&) const override;

    public:
        Integer(int x) : _value(x) {}
        inline int value() const {return _value;}
    };


    class Long : public Object {
    private:
        long _value;

        std::ostream& _display(std::ostream&) const override;

    public:
        Long(long x) : _value(x) {}
        inline int value() const {return _value;}
    };
}
#endif