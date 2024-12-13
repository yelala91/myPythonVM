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

// #include "array_list.cpp"


namespace mpvm{

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
        Tuple*          _freenames;
        Tuple*          _cellvars;
        String*         _filename;
        String*         _co_name;
        int             _firstlineno;
        String*         _notable;

        std::ostream& _display(std::ostream&) const override;


    public:
        CodeObject() {}
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
            Tuple*      freenames,
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
            _freenames(freenames),
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
            Tuple*      freenames,
            Tuple*      cellvars,
            String*     filename,
            String*     co_name, 
            int         firstlineno,
            String*     notable
        );

    };
}

#endif