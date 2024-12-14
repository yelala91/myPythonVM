// object.hpp

/*
    Object is the father class of all class in this vm.

    created on 2024/12/4 by yezq.
*/

#ifndef _OBJECT_HPP
#define _OBJECT_HPP

#include <ostream>

namespace mpvm{

    class Object{
    
    private:
        virtual std::ostream& _display(std::ostream&) const = 0;

        virtual Object* _add        (Object*) const { return nullptr;}
        virtual Object* _greater    (Object*) const { return nullptr;}
        virtual Object* _less       (Object*) const { return nullptr;}
        virtual Object* _equal      (Object*) const { return nullptr;}
        virtual Object* _not_equal  (Object*) const { return nullptr;}
        virtual Object* _geq        (Object*) const { return nullptr;}
        virtual Object* _leq        (Object*) const { return nullptr;}

    public:
        friend std::ostream& operator<<(std::ostream&, const Object&);

        Object* operator+(Object*);
        Object* operator>(Object*);
        Object* operator<(Object*);
        Object* operator==(Object*);
        Object* operator!=(Object*);
        Object* operator>=(Object*);
        Object* operator<=(Object*);

    };

    std::ostream& operator<<(std::ostream&, const Object&);

}

#endif