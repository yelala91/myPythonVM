
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

mpvm::CodeKlass* mpvm::CodeKlass::_instance = nullptr;

void mpvm::CodeKlass::_display(std::ostream& os, Object* obj) const {
    mpvm::CodeObject* code_obj = static_cast<mpvm::CodeObject*>(obj);

    os << "========== CodeObject ==========" << std::endl;
    os << "argcount: "          << code_obj->_argcount << std::endl;
    os << "posonlyargcount: "   << code_obj->_posonlyargcount << std::endl;
    os << "kwonlyargcount: "    << code_obj->_kwonlyargcount << std::endl;
    os << "nlocals: "           << code_obj->_nlocals << std::endl;
    os << "stacksize: "         << code_obj->_stacksize << std::endl;
    os << "flags: "             << code_obj->_flags << std::endl;
    os << "bytecodes: "         << *code_obj->_bytecodes << std::endl;
    os << "consts: "            << *code_obj->_consts << std::endl;
    os << "names: "             << *code_obj->_names << std::endl;
    os << "varnames: "          << *code_obj->_varnames << std::endl;
    os << "freenames: "         << *code_obj->_freenames << std::endl;
    os << "cellvars: "          << *code_obj->_cellvars << std::endl;
    os << "filename: "          << *code_obj->_filename << std::endl;
    os << "co_name: "           << *code_obj->_co_name << std::endl;
    os << "firstlineno: "       << code_obj->_firstlineno << std::endl;
    os << "notable: "           << *code_obj->_notable << std::endl;
}

mpvm::CodeKlass* mpvm::CodeKlass::get_instance() {
    if (_instance == nullptr) {
        _instance = new CodeKlass();
    }
    return _instance;
}
