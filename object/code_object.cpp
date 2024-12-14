
#include "code_object.hpp"

void mpvm::CodeObject::set(
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
) {
    _argcount = argcount;
    _posonlyargcount = posonlyargcount;
    _kwonlyargcount = kwonlyargcount;
    _nlocals = nlocals;
    _stacksize = stacksize;
    _flags = flags;
    _bytecodes = bytecodes;
    _consts = consts;
    _names = names;
    _varnames = varnames;
    _freenames = freenames;
    _cellvars = cellvars;
    _filename = filename;
    _co_name = co_name;
    _firstlineno = firstlineno;
    _notable = notable;
}

std::ostream& mpvm::CodeObject::_display(std::ostream& os) const {
    os << "========== CodeObject ==========" << std::endl;
    os << "argcount: " << _argcount << std::endl;
    os << "posonlyargcount: " << _posonlyargcount << std::endl;
    os << "kwonlyargcount: " << _kwonlyargcount << std::endl;
    os << "nlocals: " << _nlocals << std::endl;
    os << "stacksize: " << _stacksize << std::endl;
    os << "flags: " << _flags << std::endl;
    os << "bytecodes: " << *_bytecodes << std::endl;
    os << "consts: " << *_consts << std::endl;
    os << "names: " << *_names << std::endl;
    os << "varnames: " << *_varnames << std::endl;
    os << "freenames: " << *_freenames << std::endl;
    os << "cellvars: " << *_cellvars << std::endl;
    os << "filename: " << *_filename << std::endl;
    os << "co_name: " << *_co_name << std::endl;
    os << "firstlineno: " << _firstlineno << std::endl;
    os << "notable: " << *_notable << std::endl;

    return os;

}

