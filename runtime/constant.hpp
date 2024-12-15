// runtime/constant.hpp

/*
    The implement of Constant.

    created on 2024/12/13 by yezq.
*/

#ifndef _CONSTANT_HPP
#define _CONSTANT_HPP

#include <unordered_map>
#include <functional>
#include <string>

namespace mpvm {
    namespace op_code {
         inline constexpr unsigned char POP_TOP = 1;
         inline constexpr unsigned char ROT_TWO = 2;
         inline constexpr unsigned char ROT_THREE = 3;
         inline constexpr unsigned char DUP_TOP = 4;
         inline constexpr unsigned char DUP_TOP_TWO = 5;
         inline constexpr unsigned char ROT_FOUR = 6;
         inline constexpr unsigned char NOP = 9;
         inline constexpr unsigned char UNARY_POSITIVE = 10;
         inline constexpr unsigned char UNARY_NEGATIVE = 11;
         inline constexpr unsigned char UNARY_NOT = 12;
         inline constexpr unsigned char UNARY_INVERT = 15;
         inline constexpr unsigned char BINARY_MATRIX_MULTIPLY = 16;
         inline constexpr unsigned char INPLACE_MATRIX_MULTIPLY = 17;
         inline constexpr unsigned char BINARY_POWER = 19;
         inline constexpr unsigned char BINARY_MULTIPLY = 20;
         inline constexpr unsigned char BINARY_MODULO = 22;
         inline constexpr unsigned char BINARY_ADD = 23;
         inline constexpr unsigned char BINARY_SUBTRACT = 24;
         inline constexpr unsigned char BINARY_SUBSCR = 25;
         inline constexpr unsigned char BINARY_FLOOR_DIVIDE = 26;
         inline constexpr unsigned char BINARY_TRUE_DIVIDE = 27;
         inline constexpr unsigned char INPLACE_FLOOR_DIVIDE = 28;
         inline constexpr unsigned char INPLACE_TRUE_DIVIDE = 29;
         inline constexpr unsigned char GET_LEN = 30;
         inline constexpr unsigned char MATCH_MAPPING = 31;
         inline constexpr unsigned char MATCH_SEQUENCE = 32;
         inline constexpr unsigned char MATCH_KEYS = 33;
         inline constexpr unsigned char COPY_DICT_WITHOUT_KEYS = 34;
         inline constexpr unsigned char WITH_EXCEPT_START = 49;
         inline constexpr unsigned char GET_AITER = 50;
         inline constexpr unsigned char GET_ANEXT = 51;
         inline constexpr unsigned char BEFORE_ASYNC_WITH = 52;
         inline constexpr unsigned char END_ASYNC_FOR = 54;
         inline constexpr unsigned char INPLACE_ADD = 55;
         inline constexpr unsigned char INPLACE_SUBTRACT = 56;
         inline constexpr unsigned char INPLACE_MULTIPLY = 57;
         inline constexpr unsigned char INPLACE_MODULO = 59;
         inline constexpr unsigned char STORE_SUBSCR = 60;
         inline constexpr unsigned char DELETE_SUBSCR = 61;
         inline constexpr unsigned char BINARY_LSHIFT = 62;
         inline constexpr unsigned char BINARY_RSHIFT = 63;
         inline constexpr unsigned char BINARY_AND = 64;
         inline constexpr unsigned char BINARY_XOR = 65;
         inline constexpr unsigned char BINARY_OR = 66;
         inline constexpr unsigned char INPLACE_POWER = 67;
         inline constexpr unsigned char GET_ITER = 68;
         inline constexpr unsigned char GET_YIELD_FROM_ITER = 69;
         inline constexpr unsigned char PRINT_EXPR = 70;
         inline constexpr unsigned char LOAD_BUILD_CLASS = 71;
         inline constexpr unsigned char YIELD_FROM = 72;
         inline constexpr unsigned char GET_AWAITABLE = 73;
         inline constexpr unsigned char LOAD_ASSERTION_ERROR = 74;
         inline constexpr unsigned char INPLACE_LSHIFT = 75;
         inline constexpr unsigned char INPLACE_RSHIFT = 76;
         inline constexpr unsigned char INPLACE_AND = 77;
         inline constexpr unsigned char INPLACE_XOR = 78;
         inline constexpr unsigned char INPLACE_OR = 79;
         inline constexpr unsigned char LIST_TO_TUPLE = 82;
         inline constexpr unsigned char RETURN_VALUE = 83;
         inline constexpr unsigned char IMPORT_STAR = 84;
         inline constexpr unsigned char SETUP_ANNOTATIONS = 85;
         inline constexpr unsigned char YIELD_VALUE = 86;
         inline constexpr unsigned char POP_BLOCK = 87;
         inline constexpr unsigned char POP_EXCEPT = 89;
         inline constexpr unsigned char STORE_NAME = 90;
         inline constexpr unsigned char DELETE_NAME = 91;
         inline constexpr unsigned char UNPACK_SEQUENCE = 92;
         inline constexpr unsigned char FOR_ITER = 93;
         inline constexpr unsigned char UNPACK_EX = 94;
         inline constexpr unsigned char STORE_ATTR = 95;
         inline constexpr unsigned char DELETE_ATTR = 96;
         inline constexpr unsigned char STORE_GLOBAL = 97;
         inline constexpr unsigned char DELETE_GLOBAL = 98;
         inline constexpr unsigned char ROT_N = 99;
         inline constexpr unsigned char LOAD_CONST = 100;
         inline constexpr unsigned char LOAD_NAME = 101;
         inline constexpr unsigned char BUILD_TUPLE = 102;
         inline constexpr unsigned char BUILD_LIST = 103;
         inline constexpr unsigned char BUILD_SET = 104;
         inline constexpr unsigned char BUILD_MAP = 105;
         inline constexpr unsigned char LOAD_ATTR = 106;
         inline constexpr unsigned char COMPARE_OP = 107;
         inline constexpr unsigned char IMPORT_NAME = 108;
         inline constexpr unsigned char IMPORT_FROM = 109;
         inline constexpr unsigned char JUMP_FORWARD = 110;
         inline constexpr unsigned char JUMP_IF_FALSE_OR_POP = 111;
         inline constexpr unsigned char JUMP_IF_TRUE_OR_POP = 112;
         inline constexpr unsigned char JUMP_ABSOLUTE = 113;
         inline constexpr unsigned char POP_JUMP_IF_FALSE = 114;
         inline constexpr unsigned char POP_JUMP_IF_TRUE = 115;
         inline constexpr unsigned char LOAD_GLOBAL = 116;
         inline constexpr unsigned char IS_OP = 117;
         inline constexpr unsigned char CONTAINS_OP = 118;
         inline constexpr unsigned char RERAISE = 119;
         inline constexpr unsigned char JUMP_IF_NOT_EXC_MATCH = 121;
         inline constexpr unsigned char SETUP_FINALLY = 122;
         inline constexpr unsigned char LOAD_FAST = 124;
         inline constexpr unsigned char STORE_FAST = 125;
         inline constexpr unsigned char DELETE_FAST = 126;
         inline constexpr unsigned char GEN_START = 129;
         inline constexpr unsigned char RAISE_VARARGS = 130;
         inline constexpr unsigned char CALL_FUNCTION = 131;
         inline constexpr unsigned char MAKE_FUNCTION = 132;
         inline constexpr unsigned char BUILD_SLICE = 133;
         inline constexpr unsigned char LOAD_CLOSURE = 135;
         inline constexpr unsigned char LOAD_DEREF = 136;
         inline constexpr unsigned char STORE_DEREF = 137;
         inline constexpr unsigned char DELETE_DEREF = 138;
         inline constexpr unsigned char CALL_FUNCTION_KW = 141;
         inline constexpr unsigned char CALL_FUNCTION_EX = 142;
         inline constexpr unsigned char SETUP_WITH = 143;
         inline constexpr unsigned char EXTENDED_ARG = 144;
         inline constexpr unsigned char LIST_APPEND = 145;
         inline constexpr unsigned char SET_ADD = 146;
         inline constexpr unsigned char MAP_ADD = 147;
         inline constexpr unsigned char LOAD_CLASSDEREF = 148;
         inline constexpr unsigned char MATCH_CLASS = 152;
         inline constexpr unsigned char SETUP_ASYNC_WITH = 154;
         inline constexpr unsigned char FORMAT_VALUE = 155;
         inline constexpr unsigned char BUILD_CONST_KEY_MAP = 156;
         inline constexpr unsigned char BUILD_STRING = 157;
         inline constexpr unsigned char LOAD_METHOD = 160;
         inline constexpr unsigned char CALL_METHOD = 161;
         inline constexpr unsigned char LIST_EXTEND = 162;
         inline constexpr unsigned char SET_UPDATE = 163;
         inline constexpr unsigned char DICT_MERGE = 164;
         inline constexpr unsigned char DICT_UPDATE = 165;
    }

    namespace compare_op {
        inline constexpr unsigned char LESS = 0;
        inline constexpr unsigned char LESS_EQUAL = 1;
        inline constexpr unsigned char EQUAL = 2;
        inline constexpr unsigned char NOT_EQUAL = 3;
        inline constexpr unsigned char GREATER = 4;
        inline constexpr unsigned char GREATER_EQUAL = 5;
    }

    namespace builtin{
        // extern std::unordered_map<std::string, std::function<Object*()>> builtin_functions;
    }

}

#endif
