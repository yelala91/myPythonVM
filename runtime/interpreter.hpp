// runtime/interpreter.hpp

/*
    The interpreter of mpvm.

    created on 2024/12/13 by yezq.
*/

#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <stack>
#include "code_object.hpp"

namespace mpvm {
    class Interpreter {

    private:

        std::stack<Object*> _stack;

    public:
        
        void run(CodeObject* co);
        
    };
}

#endif