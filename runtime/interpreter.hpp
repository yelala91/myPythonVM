// runtime/interpreter.hpp

/*
    The interpreter of mpvm.

    created on 2024/12/13 by yezq.
*/

#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <stack>
#include "code_object.hpp"
#include <unordered_map>

namespace mpvm {
    class Interpreter {

    private:

        std::stack<Object*>* _stack;
        Tuple* _consts;
        Tuple* _names;
        std::unordered_map<std::string, Object*>* _names_hash;

    public:
        
        void run(CodeObject* co);
        
    };
}

#endif