// runtime/interpreter.hpp

/*
    The interpreter of mpvm.

    created on 2024/12/13 by yezq.
*/

#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "frame_object.hpp"

namespace mpvm {
    class Interpreter {

    private:

        FrameObject* _frame;
        Object* _ret_val;

    public:
        
        void run(CodeObject* co);
        void build_frame(Object* callable);
        void eval_frame();
        void destroy_frame();
        void leave_frame();
        
    };
}

#endif