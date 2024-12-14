#include "interpreter.hpp"
#include "constant.hpp"

void mpvm::Interpreter::run(mpvm::CodeObject* co) {

    using namespace mpvm::op_code;
    
    
    _stack = new std::stack<mpvm::Object*>(co->_stacksize);

    int num_op_codes = co->_bytecodes->length();

    unsigned int op_code, work_num;
    int c_idx = 0;

    while (c_idx < num_op_codes) {
        op_code = co->_bytecodes->value()[c_idx++] & 0xff;
        work_num = co->_bytecodes->value()[c_idx++] & 0xff;
        
        switch(op_code) {
            case LOAD_CONST:
                _stack->push(co->_consts->get(work_num));
                break;

            case LOAD_NAME:
                _stack->push(co->_names->get(work_num));
                break;
                
            case LOAD_FAST:
                _stack->push(co->_varnames->value()[work_num]);
                break;

        }

    }


}