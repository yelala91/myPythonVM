#include "interpreter.hpp"
#include "constant.hpp"
#include "bool_object.hpp"
#include <iostream>

// #define DEBUG

void mpvm::Interpreter::run(mpvm::CodeObject* co) {

    using namespace mpvm;

#ifdef DEBUG
    int op_line = 1;
#endif
    
    
    _stack = new std::stack<mpvm::Object*>();
    _consts = co->_consts;
    _names = co->_names;

    _names_hash = new std::unordered_map<std::string, mpvm::Object*>();

    int num_op_codes = co->_bytecodes->length();

    unsigned int op_code, work_num;
    String *name, *func;
    Object *obj1, *obj2, *obj;
    int c_idx = 0;

    while (c_idx < num_op_codes) {
        op_code = co->_bytecodes->value()[c_idx++] & 0xff;
        work_num = co->_bytecodes->value()[c_idx++] & 0xff;
        
        switch(op_code) {
            case op_code::LOAD_CONST:
                _stack->push((*_consts)[work_num]);

#ifdef DEBUG
    std::cout << op_line << "\t\t\tload const: " << *((*_consts)[work_num]) << std::endl;
#endif

                break;

            case op_code::LOAD_NAME:
                name = static_cast<String*>((*_names)[work_num]);

                if (_names_hash->find(name->value()) == _names_hash->end()) {
                    _stack->push(name);
                } else {
                    _stack->push(_names_hash->find(name->value())->second);
                }
                
#ifdef DEBUG
    std::cout << op_line <<  "\t\t\tload name: " << *name << " = " << *(_stack->top()) << std::endl;
#endif

                break;

            case op_code::STORE_NAME:
                name = static_cast<String*>((*_names)[work_num]); 
                if (_names_hash->find(name->value()) == _names_hash->end()) {
                    _names_hash->insert({name->value(), _stack->top()});
                } else {
                    (*_names_hash)[name->value()] = _stack->top();
                }
                
                _stack->pop();

#ifdef DEBUG
    std::cout << op_line << "\t\t\tstore name: " << name->value() << " = " << *(*_names_hash)[name->value()] << std::endl;
#endif
                break;
                
            case op_code::BINARY_ADD:
                obj1 = _stack->top(); _stack->pop();
                obj2 = _stack->top(); _stack->pop();
                _stack->push(obj1->operator+(obj2));

#ifdef DEBUG
    std::cout << op_line <<  "\t\t\t binary add: " << *obj1 << " + " << *obj2 << " = " << *(_stack->top()) << std::endl;
#endif
                
                break;

            case op_code::INPLACE_ADD:

                obj2 = _stack->top(); _stack->pop();
                obj1 = _stack->top(); _stack->pop();

                _stack->push(obj1->operator+(obj2));

#ifdef DEBUG
    std::cout << op_line <<  "\t\t\t inplace add: " << *obj1 << " + " << *obj2 << " = " << *_stack->top() << std::endl;
#endif 

                break;

            case op_code::COMPARE_OP:

                obj2 = _stack->top(); _stack->pop();
                obj1 = _stack->top(); _stack->pop();

                switch(work_num) {
                    case compare_op::LESS:
                        _stack->push(obj1->operator<(obj2));
                        break;
                    
                    case compare_op::GREATER:
                        _stack->push(obj1->operator>(obj2));
                        break;
                    
                    case compare_op::EQUAL:
                        _stack->push(obj1->operator==(obj2));
                        break;

                    case compare_op::NOT_EQUAL:
                        _stack->push(obj1->operator!=(obj2));
                        break;
                    case compare_op::GREATER_EQUAL:
                        _stack->push(obj1->operator>=(obj2));
                        break;
                    case compare_op::LESS_EQUAL:
                        _stack->push(obj1->operator<=(obj2));
                        break;

                    default:
                        std::cerr << "unknown compare op: " << work_num << std::endl;
                        break;
                }

#ifdef DEBUG
    std::cout << op_line << "\t\t\tcompare op: " << work_num << std::endl;
#endif

                break;
            
            case op_code::POP_JUMP_IF_FALSE:
                obj = _stack->top(); _stack->pop();
                if (obj == FALSE_OBJECT)
                    c_idx = work_num << 1;

#ifdef DEBUG
    std::cout << op_line << "\t\t\tpop jump if false: " << *obj << std::endl;
#endif

                break;

            case op_code::POP_JUMP_IF_TRUE:
                obj = _stack->top(); _stack->pop();
                if (obj == TRUE_OBJECT)
                    c_idx = work_num << 1;

#ifdef DEBUG
    std::cout << op_line << "\t\t\tpop jump if true: " << *obj << std::endl;
#endif

                break;

            case op_code::JUMP_FORWARD:

                c_idx += work_num;

#ifdef DEBUG
    std::cout << op_line << "\t\t\tjump forward: " << c_idx << std::endl;
#endif

                break;

            case op_code::JUMP_ABSOLUTE:

                c_idx = work_num << 1;

#ifdef DEBUG
    std::cout << op_line << "\t\t\tjump absolute: " << c_idx << std::endl;
#endif

                break;

            case op_code::CALL_FUNCTION:
            {
                obj = _stack->top(); _stack->pop();
                func = static_cast<String*>(_stack->top()); _stack->pop();

                if (func->value() == "print") {
                    std::cout << *obj << std::endl;
                }

#ifdef DEBUG    
    std::cout << op_line <<  "\t\t\tcall function: " << *func  << "(" << *obj << ")" << std::endl;
#endif

                break;
            }
            case op_code::POP_TOP:

#ifdef DEBUG
    std::cout << "\t\t\tpop top" << std::endl;
#endif
                
                break;

            case op_code::RETURN_VALUE:

#ifdef DEBUG
    std::cout << "\t\t\treturn value" << std::endl;
#endif

                break;
            

            default:

                std::cerr << "unknown op code: " << op_code << std::endl;
                break;

        }

        if (op_code == op_code::RETURN_VALUE) {
            break;
        }
#ifdef DEBUG
    op_line++;
#endif 

    }

    delete _stack;
    delete _names_hash;


}