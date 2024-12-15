// klass.hpp

/*
    The class Klass for mpvm.

    created on 2024/12/15 by yezq.
*/

#ifndef _KLASS_HPP
#define _KLASS_HPP

#include <string>

namespace mpvm {

    class Object;

    class Klass {

    private:
        std::string _name;

        virtual void _display(Object*) const;

        virtual Object* _add        (Object* x, Object* y) const { return nullptr;}
        virtual Object* _sub        (Object* x, Object* y) const { return nullptr;}
        virtual Object* _mul        (Object* x, Object* y) const { return nullptr;}
        virtual Object* _div        (Object* x, Object* y) const { return nullptr;}
        virtual Object* _mod        (Object* x, Object* y) const { return nullptr;}

        virtual Object* _greater    (Object* x, Object* y) const { return nullptr;}
        virtual Object* _less       (Object* x, Object* y) const { return nullptr;}
        virtual Object* _equal      (Object* x, Object* y) const { return nullptr;}
        virtual Object* _not_equal  (Object* x, Object* y) const { return nullptr;}
        virtual Object* _geq        (Object* x, Object* y) const { return nullptr;}
        virtual Object* _leq        (Object* x, Object* y) const { return nullptr;}

    public:
        Klass(std::string name) : _name(std::move(name)) {}
        inline std::string name() const {return _name;}
        


        Object* operator+(Object* x, Object* y) const { return _add(x, y);}
        Object* operator-(Object* x, Object* y) const { return _sub(x, y);}
        Object* operator*(Object* x, Object* y) const { return nullptr;}
        Object* operator/(Object* x, Object* y) const { return nullptr;}
        Object* operator%(Object* x, Object* y) const { return nullptr;}
        Object* operator>(Object* x, Object* y) const { return nullptr;}
        Object* operator<(Object* x, Object* y) const { return nullptr;}
        Object* operator==(Object* x, Object* y) const { return nullptr;}
        Object* operator!=(Object* x, Object* y) const { return nullptr;}
        Object* operator>=(Object* x, Object* y) const { return nullptr;}
        Object* operator<=(Object* x, Object* y) const { return nullptr;}

    }

}

#endif