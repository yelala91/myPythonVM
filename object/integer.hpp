// integer.hpp

/*
    The class int for mpvm.

    created on 2024/12/4 by yezq.
*/

#ifndef _INTEGER_HPP
#define _INTEGER_HPP

#include "object.hpp"

namespace mpvm{

    class IntegerKlass : public Klass {
    private:
        IntegerKlass() : Klass("int") { }
        static IntegerKlass* _instance;

    public:
    
        void _display(std::ostream&, Object*) const override;
        static IntegerKlass* get_instance();

        virtual Object* _add        (Object* x, Object* y) const override;
        virtual Object* _sub        (Object* x, Object* y) const override;
        virtual Object* _mul        (Object* x, Object* y) const override;
        virtual Object* _div        (Object* x, Object* y) const override;
        virtual Object* _mod        (Object* x, Object* y) const override;

        virtual Object* _greater    (Object* x, Object* y) const override;
        virtual Object* _less       (Object* x, Object* y) const override;
        virtual Object* _equal      (Object* x, Object* y) const override;
        virtual Object* _not_equal  (Object* x, Object* y) const override;
        virtual Object* _geq        (Object* x, Object* y) const override;
        virtual Object* _leq        (Object* x, Object* y) const override;

    };
    
    extern IntegerKlass* INTEGER_KLASS;

    class Integer : public Object {
    private:
        int _value;

    public:
        Integer(int x) : _value(x) {
            set_klass(INTEGER_KLASS);
        }
        inline int value() const {return _value;}
    };


    // class Long : public Object {
    // private:
    //     long _value;

    //     std::ostream& _display(std::ostream&) const override;

    // public:
    //     Long(long x) : _value(x) {}
    //     inline int value() const {return _value;}
    // };


}
#endif