// object.hpp

/*
    Object is the father class of all class in this vm.

    created on 2024/12/4 by yezq.
*/

#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <iostream>

namespace mpvm{

    class Object;

    class Klass {

    private:
        std::string _name;

    public:
        Klass(std::string name) : _name(std::move(name)) {}
        inline std::string name() const {return _name;}

        virtual void _display(std::ostream&, Object*) const = 0;

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
        
    };


    class Object{
    
    private:
        Klass* _klass;

    public:

        Klass* klass() const { return _klass;}
        void set_klass(Klass* k) { _klass = k;}

        friend std::ostream& operator<<(std::ostream&, const Object&);

        friend Object* add(Object*, Object*);
        friend Object* sub(Object*, Object*);
        friend Object* mul(Object*, Object*);
        friend Object* div(Object*, Object*);
        friend Object* mod(Object*, Object*);
        friend Object* less(Object*, Object*);
        friend Object* equal(Object*, Object*);
        friend Object* not_equal(Object*, Object*);
        friend Object* greater(Object*, Object*);
        friend Object* geq(Object*, Object*);
        friend Object* leq(Object*, Object*);

    };

    std::ostream& operator<<(std::ostream&, Object&);

    Object* add(Object*, Object*);
    Object* sub(Object*, Object*);
    Object* mul(Object*, Object*);
    Object* div(Object*, Object*);
    Object* mod(Object*, Object*);
    Object* less(Object*, Object*);
    Object* equal(Object*, Object*);
    Object* not_equal(Object*, Object*);
    Object* greater(Object*, Object*);
    Object* geq(Object*, Object*);
    Object* leq(Object*, Object*);


    
}

#endif