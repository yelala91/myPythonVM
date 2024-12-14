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

        Object* _add(Object*) const override;
        Object* _greater(Object*) const override;
        Object* _less(Object*) const override;
        Object* _equal(Object*) const override;
        Object* _not_equal(Object*) const override;
        Object* _geq(Object*) const override;
        Object* _leq(Object*) const override;

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