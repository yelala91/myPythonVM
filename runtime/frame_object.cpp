#include "frame_object.hpp"
#include "string.hpp"

mpvm::FrameObject::FrameObject(mpvm::CodeObject* co) {
    _codes = co;
    _pc = 0;

    _consts     = co->_consts;
    _names      = co->_names;
    _var_names  = co->_varnames;
    _free_vars  = co->_freevars;
    _cell_vars  = co->_cellvars;

    _locals = new std::unordered_map<std::string, mpvm::Object*>();
    _globals = new std::unordered_map<std::string, mpvm::Object*>();

    _stack = new std::stack<mpvm::Object*>();

    _sender = nullptr;
}

mpvm::FrameObject::FrameObject(mpvm::FunctionObject* func) {
    _codes = func->_func_code;
    _pc = 0;

    _consts     = _codes->_consts;
    _names      = _codes->_names;
    _var_names  = _codes->_varnames;
    _free_vars  = _codes->_freevars;
    _cell_vars  = _codes->_cellvars;
    _locals = new std::unordered_map<std::string, mpvm::Object*>();
    _globals = new std::unordered_map<std::string, mpvm::Object*>();
    _stack = new std::stack<mpvm::Object*>();
    _sender = nullptr;
}

void mpvm::FrameObject::store_global(mpvm::Object* name, mpvm::Object* obj) {
    mpvm::String* sname = static_cast<mpvm::String*>(name);

    (*_globals)[sname->value()] = obj;
}

void mpvm::FrameObject::store_local(mpvm::Object* name, mpvm::Object* obj) {
    mpvm::String* sname = static_cast<mpvm::String*>(name);

    (*_locals)[sname->value()] = obj;
}

void mpvm::FrameObject::load_global(int idx) {
    
    mpvm::String* sname = static_cast<mpvm::String*>(_names->get(idx));

    _stack->push((*_globals)[sname->value()]);
}

void mpvm::FrameObject::load_local(int idx) {
    mpvm::String* sname = static_cast<mpvm::String*>(_var_names->get(idx));

    _stack->push((*_locals)[sname->value()]);
}

void mpvm::FrameObject::load_const(int idx) {
    _stack->push(_consts->get(idx));
}

bool mpvm::FrameObject::has_more_code() {
    return _pc < _codes->_bytecodes->length();
}

unsigned char mpvm::FrameObject::next_opcode() {
    return _codes->_bytecodes->value()[_pc++];
}

int mpvm::FrameObject::next_op_arg() {
    return _codes->_bytecodes->value()[_pc++] & 0xff;
}

