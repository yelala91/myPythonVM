// frame_object.hpp

/*
    FrameObject is the tool of call function.

    created on 2024/12/16 by yezq.
*/

#ifndef _FRAME_OBJECT_HPP
#define _FRAME_OBJECT_HPP

// #include "tuple_object.hpp"
#include "code_object.hpp"
#include "function_object.hpp"
#include <stack>
#include <unordered_map>

namespace mpvm {
    
    class FrameObject {
    
    private:
        std::stack<Object*>* _stack;

        Tuple* _consts;
        Tuple* _names;
        Tuple* _var_names;
        Tuple* _free_vars;
        Tuple* _cell_vars;
        
        std::unordered_map<std::string, Object*>* _globals;
        std::unordered_map<std::string, Object*>* _locals;

        CodeObject* _codes;
        int _pc;

        FrameObject* _sender;

    public:
        FrameObject(CodeObject* codes);
        FrameObject(FunctionObject* func);
        FrameObject() { }

        void set_pc(int pc) { _pc = pc;}
        int get_pc() { return _pc;}

        std::stack<Object*>* stack() { return _stack;}
        Tuple* consts() { return _consts;}
        Tuple* names() { return _names;}
        Tuple* var_names() { return _var_names;}
        Tuple* free_vars() { return _free_vars;}
        Tuple* cell_vars() { return _cell_vars;}
    
        void store_global(Object* name, Object* obj);
        void store_local(Object* name, Object* obj);

        void load_global(int idx);
        void load_local(int idx);

        void load_const(int idx);
        
        bool has_more_code();
        unsigned char next_opcode();
        int next_op_arg();

        void set_sender(FrameObject* sender) { _sender = sender;}
        FrameObject* sender() { return _sender;}

        bool is_first_frame() { return _sender == nullptr;}
    };
}

#endif