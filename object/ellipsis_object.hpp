// ellipsis.hpp

/*
    define the boolen object.

    created on 2024/12/11 by yezq.
*/

#ifndef _ELLIPSIS_OBJECT_HPP
#define _ELLIPSIS_OBJECT_HPP

#include "object.hpp"
// #include <string>

namespace mpvm{

    class EllipsisKlass : public Klass {
    private:
        EllipsisKlass() : Klass("ellipsis") { }
        static EllipsisKlass* _instance;
       
    public:
        static EllipsisKlass* get_instance();
        void _display(std::ostream&, Object*) const override;
    };

    extern EllipsisKlass* ELLIPSIS_KLASS;

    class Ellipsis : public Object {
    
    private:
        static Ellipsis* _instance;
        Ellipsis() {
            set_klass(ELLIPSIS_KLASS);
        }

    public:
        static Ellipsis* get_instance() {
            if (_instance) {
                return _instance;
            } else {
                _instance = new Ellipsis();
                return _instance;
            }
        }
        
    };

    extern Ellipsis* ELLIPSIS_OBJECT;


    
}

#endif 