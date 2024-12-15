// none_object.hpp

/*
    define the none object.

    created on 2024/12/13 by yezq.
*/

#ifndef _NONE_OBJECT_HPP
#define _NONE_OBJECT_HPP

#include "object.hpp"

namespace mpvm{

    class NoneKlass : public Klass {
    private:
        NoneKlass() : Klass("None") { }
        static NoneKlass* _instance;
        

    public:
        void _display(std::ostream&, Object*) const override;
        static NoneKlass* get_instance();
    };

    extern NoneKlass* NONE_KLASS;

    class NoneObject : public Object {

    private:
        static NoneObject* _instance;

    public:
        NoneObject() {
            set_klass(NONE_KLASS);
        }
        static NoneObject* get_instance();
    };

    extern NoneObject* NONE_OBJECT;

}

#endif