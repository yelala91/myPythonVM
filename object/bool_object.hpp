// bool_object.hpp

/*
    define the boolen object.

    created on 2024/12/11 by yezq.
*/

#ifndef _BOOL_OBJECT_HPP
#define _BOOL_OBJECT_HPP

#include "object.hpp"

namespace mpvm{

    class BoolKlass : public Klass {
    private:
        BoolKlass() : Klass("bool") { }
        static BoolKlass* _instance;
        
    public:
        
        static BoolKlass* get_instance();
        void _display(std::ostream&, Object*) const override;
    };

    extern BoolKlass* BOOL_KLASS;

    class BoolObject : public Object {
    
    private:
        bool _value;

        static BoolObject* _true_instance;   
        static BoolObject* _false_instance;  

    public:
        BoolObject(bool v) : _value(v) { 
            set_klass(BOOL_KLASS);
        }

        static BoolObject* get_true_instance() {
            if (!_true_instance) {
                _true_instance = new BoolObject(true);
            } 
            
            return _true_instance;
        }

        static BoolObject* get_false_instance() {
            if (!_false_instance) {
                _false_instance = new BoolObject(false);
            }

            return _false_instance;
        }

    };

    extern BoolObject* TRUE_OBJECT;
    extern BoolObject* FALSE_OBJECT;


}



#endif