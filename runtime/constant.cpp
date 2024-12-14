

#include "constant.hpp"
#include "object.hpp"
#include <iostream>

mpvm::builtin::builtin_functions = {
    "print" : [](mpvm::Object* obj) {std::cout << *obj << std::endl;}
}