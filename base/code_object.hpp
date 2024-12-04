// code_object.hpp

/*
    CodeObject:
        class for the .pyc file by python code generate

    created on 2024/12/4 by yezq.
*/

#ifndef _CODE_OBJECT_HPP
#define _CODE_OBJECT_HPP

#include "string.hpp"
#include "array_list.hpp"
#include "array_list.cpp"


namespace mpvm{

    class CodeObject : public Object {

    private:

        int                 _argcount;
        int                 _nlocals;
        int                 _stacksize;
        int                 _flag;
        String*             _bytecodes;
        ArrayList<Object*>* _consts;
        ArrayList<Object*>* _names;
        ArrayList<Object*>* _varnames;
        ArrayList<Object*>* _freenames;
        ArrayList<Object*>* _cellvars;
        String*             _filename;
        String*             _co_name;
        int                 _lineno;
        String*             _notable;


    public:
        CodeObject(
            int                 argcount, 
            int                 nlocals,
            int                 stacksize,
            int                 flag,
            String*             bytecodes,
            ArrayList<Object*>* consts, 
            ArrayList<Object*>* names,
            ArrayList<Object*>* varnames,
            ArrayList<Object*>* freenames,
            ArrayList<Object*>* cellvars,
            String*             filename,
            String*             co_name, 
            int                 lineno,
            String*             notable
        ):

            _argcount(argcount),
            _nlocals(nlocals),
            _stacksize(stacksize),
            _flag(flag),
            _bytecodes(bytecodes),
            _consts(consts),
            _names(names),
            _varnames(varnames),
            _freenames(freenames),
            _cellvars(cellvars),
            _filename(filename),
            _co_name(co_name),
            _lineno(lineno),
            _notable(notable){

        }
        
    };
}

#endif