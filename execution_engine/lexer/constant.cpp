#include "constant.hpp"

std::ostream& operator<<(std::ostream& os, const mpvm::TokenType& type) {
    std::string out_str;

    switch(type) {
        case mpvm::TokenType::KEYWORD :
            out_str = "KEYWORD";
            break;

        case mpvm::TokenType::IDENTIFIER : 
            out_str = "IDENTIFIER";
            break;
        
        case mpvm::TokenType::NUMBER : 
            out_str = "NUMBER";
            break;

        case mpvm::TokenType::STRING :
            out_str = "STRING";
            break;

        case mpvm::TokenType::OPERATOR :
            out_str = "OPERATOR";
            break;

        case mpvm::TokenType::SEPARATOR :
            out_str = "SEPARATOR";
            break;

        case mpvm::TokenType::COMMENT :
            out_str = "COMMENT";
            break;

        case mpvm::TokenType::INDENT :
            out_str = "INDENT";
            break;

        default :
            out_str = "UNKNOWN";
            break;
    }

    os << out_str;
    return os;
}

std::ostream& operator<<(std::ostream& os, const mpvm::Token& tk) {
    os << "<" << tk.type << ", " << tk.value << ">" << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<mpvm::Token> vec) {
    for(auto item : vec) {
        os << item;
    }

    return os;
}