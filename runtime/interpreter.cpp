#include "interpreter.hpp"
#include "constant.hpp"
#include "bool_object.hpp"
#include "function_object.hpp"
#include <iostream>

#define DEBUG

#define PUSH(x)     _frame->stack()->push((x))
#define POP()       _frame->stack()->pop()
#define TOP()       _frame->stack()->top()

void mpvm::Interpreter::build_frame(Object* callable) {
    FrameObject* frame = new FrameObject(static_cast<FunctionObject*>(callable));
    frame->set_sender(_frame);
    _frame = frame;

}

void mpvm::Interpreter::destroy_frame() {
    FrameObject* frame = _frame;
    _frame = _frame->sender();
    delete frame;
}

void mpvm::Interpreter::leave_frame() {
    destroy_frame();
    PUSH(_ret_val);
}

void mpvm::Interpreter::eval_frame() {
    using namespace mpvm;

#ifdef DEBUG
    int op_line = 1;
#endif
    
    unsigned int ope, op_arg;
    Object *obj1, *obj2, *obj;
    String* func;

    while (_frame->has_more_code()) {
        ope = _frame->next_opcode();
        op_arg = _frame->next_op_arg();
        
        switch(ope) {
            case op_code::LOAD_CONST:
                _frame->load_const(op_arg);
                // _stack->push((*_consts)[op_arg]);

#ifdef DEBUG
    std::cout << op_line << "\t\t\tload const: " << op_arg << std::endl;
#endif

                break;

            case op_code::LOAD_NAME:

                _frame->load_global(op_arg);
                // name = static_cast<String*>((*_names)[op_arg]);

                // if (_names_hash->find(name->value()) == _names_hash->end()) {
                //     _stack->push(name);
                // } else {
                //     _stack->push(_names_hash->find(name->value())->second);
                // }
                
#ifdef DEBUG
    std::cout << op_line <<  "\t\t\tload name: " << op_arg << std::endl;
#endif

                break;

            case op_code::STORE_NAME:
                obj = _frame->names()->get(op_arg);
                _frame->store_global(obj, TOP());   

                POP();

                // name = static_cast<String*>((*_names)[op_arg]); 
                // if (_names_hash->find(name->value()) == _names_hash->end()) {
                //     _names_hash->insert({name->value(), _stack->top()});
                // } else {
                //     (*_names_hash)[name->value()] = _stack->top();
                // }
                
                // _stack->pop();

#ifdef DEBUG
    std::cout << op_line << "\t\t\tstore name: " << op_arg << std::endl;
#endif
                break;
                
            case op_code::BINARY_ADD:
                obj2 = TOP();   POP();
                obj1 = TOP();   POP();

                PUSH(mpvm::add(obj1, obj2));
                // obj1 = _stack->top(); _stack->pop();
                // obj2 = _stack->top(); _stack->pop();
                // _stack->push(mpvm::add(obj1, obj2));

#ifdef DEBUG
    std::cout << op_line <<  "\t\t\t binary add: " << op_arg << std::endl;
#endif
                
                break;

            case op_code::INPLACE_ADD:

                obj2 = TOP();   POP();
                obj1 = TOP();   POP();

                PUSH(mpvm::add(obj1, obj2));

                // obj2 = _stack->top(); _stack->pop();
                // obj1 = _stack->top(); _stack->pop();

                // _stack->push(mpvm::add(obj1, obj2));

#ifdef DEBUG
    std::cout << op_line <<  "\t\t\t inplace add: " << op_arg << std::endl;
#endif 

                break;

            case op_code::COMPARE_OP:

                obj2 = TOP();   POP();
                obj1 = TOP();   POP();

                // obj2 = _stack->top(); _stack->pop();
                // obj1 = _stack->top(); _stack->pop();

                switch(op_arg) {
                    case compare_op::LESS:
                        PUSH(mpvm::less(obj1, obj2));
                        // _stack->push(mpvm::less(obj1, obj2));
                        break;
                    
                    case compare_op::GREATER:
                        PUSH(mpvm::greater(obj1, obj2));
                        // _stack->push(mpvm::greater(obj1, obj2));
                        break;
                    
                    case compare_op::EQUAL:
                        PUSH(mpvm::equal(obj1, obj2));
                        // _stack->push(mpvm::equal(obj1, obj2));
                        break;

                    case compare_op::NOT_EQUAL:
                        PUSH(mpvm::not_equal(obj1, obj2));
                        // _stack->push(mpvm::not_equal(obj1, obj2));
                        break;
                    case compare_op::GREATER_EQUAL:
                        PUSH(mpvm::geq(obj1, obj2));
                        // _stack->push(mpvm::geq(obj1, obj2));
                        break;
                    case compare_op::LESS_EQUAL:
                        PUSH(mpvm::leq(obj1, obj2));
                        // _stack->push(mpvm::leq(obj1, obj2));
                        break;

                    default:
                        std::cerr << "unknown compare op: " << op_arg << std::endl;
                        
                        break;
                }

#ifdef DEBUG
    std::cout << op_line << "\t\t\tcompare op: " << op_arg << std::endl;
#endif

                break;
            
            case op_code::POP_JUMP_IF_FALSE:
                obj = TOP();    POP();

                // obj = _stack->top(); _stack->pop();
                if (obj == FALSE_OBJECT)
                    // c_idx = op_arg << 1;
                    _frame->set_pc(op_arg << 1);

#ifdef DEBUG
    std::cout << op_line << "\t\t\tpop jump if false: " << op_arg << std::endl;
#endif

                break;

            case op_code::POP_JUMP_IF_TRUE:
                obj = TOP();    POP();

                if (obj == TRUE_OBJECT)
                    _frame->set_pc(op_arg << 1);

                // obj = _stack->top(); _stack->pop();
                // if (obj == TRUE_OBJECT)
                //     c_idx = op_arg << 1;

#ifdef DEBUG
    std::cout << op_line << "\t\t\tpop jump if true: " << op_arg << std::endl;
#endif

                break;

            case op_code::JUMP_FORWARD:
                _frame->set_pc(_frame->get_pc() + op_arg);
                // c_idx += op_arg;

#ifdef DEBUG
    std::cout << op_line << "\t\t\tjump forward: " << op_arg << std::endl;
#endif

                break;

            case op_code::JUMP_ABSOLUTE:
                _frame->set_pc(op_arg << 1);
                // c_idx = op_arg << 1;

#ifdef DEBUG
    std::cout << op_line << "\t\t\tjump absolute: " << op_arg << std::endl;
#endif

                break;

            case op_code::MAKE_FUNCTION:
                obj2 = TOP();    POP();
                obj1 = TOP();    POP();

                obj = new FunctionObject(obj1);
                PUSH(obj);

#ifdef DEBUG
    std::cout << op_line <<  "\t\t\tmake function: " << op_arg << std::endl;
#endif 
                break;

            case op_code::CALL_FUNCTION:
            {
                obj = TOP();    POP();
                build_frame(obj);

#ifdef DEBUG    
    std::cout << op_line <<  "\t\t\tcall function: " << op_arg << std::endl;
#endif

                break;
            }
            case op_code::POP_TOP:

#ifdef DEBUG
    std::cout << "\t\t\tpop top " << op_arg<< std::endl;
#endif
                
                break;

            case op_code::RETURN_VALUE:
                _ret_val = TOP();
                

#ifdef DEBUG
    std::cout << "\t\t\treturn value " << *_ret_val << std::endl;
#endif
                if (_frame->is_first_frame()) {
                    return;
                }
                leave_frame();
                break;
            

            default:

                std::cerr << "unknown op code: " << ope << std::endl;
                break;

        }


#ifdef DEBUG
    op_line++;
#endif 

    }
}

void mpvm::Interpreter::run(mpvm::CodeObject* co) {
    _frame = new FrameObject(co);
    eval_frame();
    destroy_frame();
}