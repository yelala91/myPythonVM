// constant.hpp

/*
    Some constants definition of mpvm.

    created on 2024/12/5 by yezq.
*/

#ifndef _CONSTANT_HPP
#define _CONSTANT_HPP

#include <string>
#include <unordered_set>
#include <ostream>
#include <vector>

namespace mpvm{

    enum class TokenType : int {
        KEYWORD     = 0,        /* key word */
        IDENTIFIER  = 1,        /* vars, class or other identifier */
        NUMBER      = 2,        /* number: float, int and so on */
        STRING      = 3,        /* string */
        OPERATOR    = 4,        /* operator: +, -, *, /, ., and so on */
        SEPARATOR   = 5,        /* separator */
        COMMENT     = 6,        /* comment, start with cahr "#" */
        INDENT      = 7
    };

    struct Token {
        TokenType   type;
        std::string value;

        int start_pos;
        int end_pos;
        int lineno;
        int end_lineno;
        int col_offset;
        int end_col_offset;
    };

    static std::unordered_set<std::string> KeyWords = {
        "False", "None", "True", "and", "as", "assert", "async", "await", 
        "break", "class", "continue", "def", "del", "elif", "else", "except", 
        "finally", "for", "from", "global", "if", "import", "in", "is", 
        "lambda", "nonlocal", "not", "or", "pass", "raise", "return", "try", 
        "while", "with", "yield"
    };
    static std::unordered_set<char> Separator = {
        '(', ')', '[', ']', '{', '}', ';', ':', '\\', '.', ','
    };
    static std::unordered_set<char> Operator = {
        '=', '+', '-', '*', '/', '>', '<', '^', '&', '|', '~', '%', '!'
    };
    inline bool is_digital(char c);
    inline bool is_upper_alpha(char c);
    inline bool is_lower_alpha(char c);
    inline bool is_alpha(char c);
    inline bool is_keyword(std::string chars);
    inline bool is_separator(const char c);
    inline bool is_operator(const char c);

    inline bool is_digital(char c) {
        if ('0' <= c && c <= '9') 
            return true;
        else return false;
    }

    inline bool is_upper_alpha(char c) {
        if ('A' <= c && c <= 'Z') 
            return true;
        else return false;
    }

    inline bool is_lower_alpha(char c) {
        if ('a' <= c && c <= 'z') 
            return true;
        else return false;
    }

    inline bool is_alpha(char c) {
        return is_lower_alpha(c) || is_upper_alpha(c);
    }

    inline bool is_keyword(std::string chars) {
        if (KeyWords.find(chars) != KeyWords.end()) {
            return true;
        } else return false;
    }

    inline bool is_separator(const char c) {
        if (Separator.find(c) != Separator.end()) {
            return true;
        } else return false;
    }

    inline bool is_operator(const char c) {
        if (Operator.find(c) != Operator.end()) {
            return true;
        } else return false;
    }


}

std::ostream& operator<<(std::ostream& os, const mpvm::TokenType& type);
std::ostream& operator<<(std::ostream& os, const mpvm::Token& tk);
std::ostream& operator<<(std::ostream& os, const std::vector<mpvm::Token> vec);

#endif 