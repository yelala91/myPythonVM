#include "function_object.hpp"

mpvm::FunctionKlass* mpvm::FunctionKlass::_instance = nullptr;

mpvm::FunctionKlass* mpvm::FunctionKlass::get_instance() {
    if (!_instance) {
        _instance = new FunctionKlass();
    }
    return _instance;
}

void mpvm::FunctionKlass::_display(std::ostream& os, Object* obj) const {
    FunctionObject* func = (FunctionObject*)obj;
    os << "<function " << func->func_name() << ">";
}

mpvm::FunctionObject::FunctionObject(Object* obj) {
    CodeObject* co = static_cast<CodeObject*>(obj);

    _func_code = co;
    _func_name = co->_co_name->value();
    _flags = co->_flags;

    set_klass(mpvm::FUNCTION_KLASS);
}
