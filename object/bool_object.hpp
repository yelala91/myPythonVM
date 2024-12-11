// bool_object.hpp

/*
    define the boolen object.

    created on 2024/12/11 by yezq.
*/

#ifndef _BOOL_OBJECT_HPP
#define _BOOL_OBJECT_HPP

#include "object.hpp"

namespace mpvm{

    class BoolObject : public Object {
    
    private:
        bool _value;

        static BoolObject* _true_instance   = nullptr;
        static BoolObject* _false_instance  = nullptr;

    public:
        BoolObject(bool v) : _value(v) { }

        static BoolObject* get_true_instance() {
            if (_true_instance) {
                return _true_instance;
            } else {
                return new BoolObject(true);
            }
        }

        static BoolObject* get_false_instance() {
            if (_false_instance) {
                return _false_instance;
            } else {
                return new BoolObject(false);
            }
        }

    }

    extern
}



#endif