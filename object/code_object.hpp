// code_object.hpp

/*
    CodeObject:
        class for the .pyc file by python code generate

    created on 2024/12/4 by yezq.
*/

#ifndef _CODE_OBJECT_HPP
#define _CODE_OBJECT_HPP

#include "string.hpp"
#include "tuple_object.hpp"
#include "object.hpp"
// #include "array_list.cpp"



namespace mpvm{

    class CodeKlass : public Klass {
    
    private:
        CodeKlass() : Klass("code") { }
        static CodeKlass* _instance;
        

    public:
        static CodeKlass* get_instance();
        void _display(std::ostream&, Object*) const override;
    };

    extern CodeKlass* CODE_KLASS;


    // class Interpreter;
    class FrameObject;
    class FunctionObject;

    class CodeObject : public Object {

    private:

        int             _argcount;
        int             _posonlyargcount;
        int             _kwonlyargcount;
        int             _nlocals;
        int             _stacksize;
        int             _flags;
        String*         _bytecodes;
        Tuple*          _consts;
        Tuple*          _names;
        Tuple*          _varnames;
        Tuple*          _freevars;
        Tuple*          _cellvars;
        String*         _filename;
        String*         _co_name;
        int             _firstlineno;
        String*         _notable;


    public:
        CodeObject() {
            set_klass(CODE_KLASS);
        }
        CodeObject(
            int         argcount, 
            int         posonlyargcount,
            int         kwonlyargcount,
            int         nlocals,
            int         stacksize,
            int         flags,
            String*     bytecodes,
            Tuple*      consts, 
            Tuple*      names,
            Tuple*      varnames,
            Tuple*      freevars,
            Tuple*      cellvars,
            String*     filename,
            String*     co_name, 
            int         firstlineno,
            String*     notable
        ):

            _argcount(argcount),
            _posonlyargcount(posonlyargcount),
            _kwonlyargcount(kwonlyargcount),
            _nlocals(nlocals),
            _stacksize(stacksize),
            _flags(flags),
            _bytecodes(bytecodes),
            _consts(consts),
            _names(names),
            _varnames(varnames),
            _freevars(freevars),
            _cellvars(cellvars),
            _filename(filename),
            _co_name(co_name),
            _firstlineno(firstlineno),
            _notable(notable)
        {

        }

        void set(
            int         argcount, 
            int         posonlyargcount,
            int         kwonlyargcount,
            int         nlocals,
            int         stacksize,
            int         flags,
            String*     bytecodes,
            Tuple*      consts, 
            Tuple*      names,
            Tuple*      varnames,
            Tuple*      freevars,
            Tuple*      cellvars,
            String*     filename,
            String*     co_name, 
            int         firstlineno,
            String*     notable
        );

        friend class FrameObject;
        friend class CodeKlass;
        friend class FunctionObject;

    };

}

#endif