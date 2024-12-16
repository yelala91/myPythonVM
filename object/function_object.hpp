// function_object.hpp

/*
    The function object of mpvm.

    created on 2024/12/16 by yezq.
*/

#ifndef FUNCTION_OBJECT_HPP
#define FUNCTION_OBJECT_HPP

#include "code_object.hpp"
#include <string>

namespace mpvm {

    class FunctionKlass : public Klass {

    private:
        FunctionKlass() : Klass("function") { }
        static FunctionKlass* _instance;

    public:
        static FunctionKlass* get_instance();
        void _display(std::ostream& os, Object* obj) const;

    };

    extern FunctionKlass* FUNCTION_KLASS;

    class FrameObject;

    class FunctionObject : public Object {

    private:
        CodeObject* _func_code;
        std::string _func_name;

        unsigned int _flags;

    public:
        FunctionObject(Object* co);
        FunctionObject(Klass* klass) {
            set_klass(klass);

            _func_code = nullptr;
            _func_name = "";
            _flags = 0;
        }

        std::string func_name() const { return _func_name;}
        int flags() const { return _flags; }

        friend class FrameObject;

    };
}

#endif