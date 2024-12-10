

#include "python_lexer.hpp"
#include <iostream>

std::vector<mpvm::Token> mpvm::PythonLexer::tokenize() {
    std::vector<mpvm::Token> vec_rtn;

    while (_current_pos < _source.size()) {
        char c = _source[_current_pos];
        if (is_alpha(c) || c == '_') {
            vec_rtn.emplace_back(parse_IDENTIFIER());
        } else if (c == '\'' || c == '\"') {
            vec_rtn.emplace_back(parse_STRING());
        } else if (is_digital(c)) {
            vec_rtn.emplace_back(parse_NUMBER());
        } else if (c == '.') {
            char temp_c = _source[_current_pos + 1];
            if (is_digital(temp_c))
                vec_rtn.emplace_back(parse_NUMBER());
            else 
                vec_rtn.emplace_back(parse_SEPARATOR());
        } else if (is_separator(c)) {
            vec_rtn.emplace_back(parse_SEPARATOR());
        } else if (c == '#') {
            vec_rtn.emplace_back(parse_COMMENT());
        } else if (is_operator(c)) {
            vec_rtn.emplace_back(parse_OPERATOR());
        } else if (c == ' ' || c == '\t' || c == '\n') {
            parse_SPACE(vec_rtn);
        } else {
            std::cerr << "Can't parse token at line " << _lineno << ", col " << _col_offset << std::endl;
        }
    }
    return vec_rtn;
}

mpvm::Token mpvm::PythonLexer::parse_IDENTIFIER() {

    int lexem_start         = _current_pos;
    int lexem_col_offset    = _col_offset;

    char c = _source[++_current_pos];
    _col_offset++;

    while (is_alpha(c) || is_digital(c) || c == '_') {
        c = _source[++_current_pos];
        _col_offset++;
    }

    std::string value_str = _source.substr(lexem_start, _current_pos - lexem_start);

    mpvm::Token new_token = {
        is_keyword(value_str) ? mpvm::TokenType::KEYWORD : mpvm::TokenType::IDENTIFIER,
        value_str,
        lexem_start,
        _current_pos - 1,
        _lineno,
        _lineno,
        lexem_col_offset,
        _col_offset - 1
    };

    return new_token;

}

mpvm::Token mpvm::PythonLexer::parse_COMMENT() {

    int lexem_start         = _current_pos;
    int lexem_col_offset    = _col_offset;

    char c = _source[++_current_pos];
    _col_offset++;

    while(c != '\n') {
        c = _source[++_current_pos];
        _col_offset++;
    }

    std::string value_str = _source.substr(lexem_start, _current_pos - lexem_start);

    mpvm::Token new_token = {
        mpvm::TokenType::COMMENT,
        value_str,
        lexem_start,
        _current_pos - 1,
        _lineno,
        _lineno,
        lexem_col_offset,
        _col_offset - 1
    };

    return new_token;
}

mpvm::Token mpvm::PythonLexer::parse_NUMBER() {
    
    int lexem_start         = _current_pos;
    int lexem_col_offset    = _col_offset;

    char c = _source[++_current_pos];
    _col_offset++;    

    while (is_digital(c)) {
        c = _source[++_current_pos];
        _col_offset++;
    }

    if (c == '.') {
        c = _source[++_current_pos];
        _col_offset++;
        while (is_digital(c)) {
            c = _source[++_current_pos];
            _col_offset++;
        }

        if (c == 'e' || c == 'E') {
            c = _source[++_current_pos];
            _col_offset++;
            while (is_digital(c)) {
                c = _source[++_current_pos];
                _col_offset++;
            }
        }
    } else if (c == 'e' || c == 'E') {
        c = _source[++_current_pos];
        _col_offset++;
        while (is_digital(c)) {
            c = _source[++_current_pos];
            _col_offset++;
        }
    } 

    std::string value_str = _source.substr(lexem_start, _current_pos - lexem_start);

    mpvm::Token new_token = {
        mpvm::TokenType::NUMBER,
        value_str,
        lexem_start,
        _current_pos - 1,
        _lineno,
        _lineno,
        lexem_col_offset,
        _col_offset - 1
    };

    return new_token;
}

mpvm::Token mpvm::PythonLexer::parse_OPERATOR() {

    int lexem_start         = _current_pos;
    int lexem_col_offset    = _col_offset;

    char c = _source[_current_pos];

    if (c == '=' || c == '+' || c == '-' || c == '%' || c == '&' || c =='|' || c == '^' || c == '~') {
        if (_source[++_current_pos] == '=')
            _col_offset++;
        else _current_pos--;
    } else if (c == '*' || c == '/' || c == '<' || c == '>') {
        char temp_c = _source[++_current_pos];
        if (temp_c == '=') {
            _col_offset++;
        } else if (temp_c == c) {
            if (_source[++_current_pos] == '=') 
                _col_offset++;
            else _current_pos--;

        } else _current_pos--;

    } else if (c == '!') {
        _current_pos++;
        _col_offset++;
    }

    std::string value_str = _source.substr(lexem_start, _current_pos - lexem_start + 1);

    mpvm::Token new_token = {
        mpvm::TokenType::OPERATOR,
        value_str,
        lexem_start,
        _current_pos++,
        _lineno,
        _lineno,
        lexem_col_offset,
        _col_offset++
    };

    return new_token;
}

mpvm::Token mpvm::PythonLexer::parse_STRING() {
    int lexem_start         = _current_pos;
    int lexem_col_offset    = _col_offset;

    char start_tag = _source[_current_pos++];
    char c         = _source[_current_pos];

    while(c != start_tag) {
        c = _source[++_current_pos];
        _col_offset++;
    }

    std::string value_str = _source.substr(lexem_start, _current_pos - lexem_start + 1);

    mpvm::Token new_token = {
        mpvm::TokenType::STRING,
        value_str,
        lexem_start,
        _current_pos++,
        _lineno,
        _lineno,
        lexem_col_offset,
        _col_offset++
    };

    return new_token;
}

mpvm::Token mpvm::PythonLexer::parse_SEPARATOR() {

    int lexem_start         = _current_pos;
    int lexem_col_offset    = _col_offset;

    std::string value_str = _source.substr(lexem_start, 1);

    mpvm::Token new_token = {
        mpvm::TokenType::SEPARATOR,
        value_str,
        lexem_start,
        _current_pos++,
        _lineno,
        _lineno,
        lexem_col_offset,
        _col_offset++
    };

    return new_token;
}

mpvm::Token mpvm::PythonLexer::parse_INDENT() {

    mpvm::Token new_token = {
        mpvm::TokenType::INDENT,
        _source.substr(_current_pos++, 1),
        _current_pos,
        _current_pos - 1,
        _lineno,
        _lineno,
        _col_offset++,
        _col_offset - 1
    };

    return new_token;
}

void mpvm::PythonLexer::parse_SPACE(std::vector<mpvm::Token>& vec) {
    
    char c = _source[_current_pos];
    bool indent_flag = false;
    while (c == ' ' || c == '\t' || c == '\n') {
        
        if (c == '\n') {
            _lineno++;
            _col_offset = 1;
            indent_flag = true;
        } else {
            _col_offset++;
            if (indent_flag) {
                mpvm::Token indent_token = {
                    mpvm::TokenType::INDENT,
                    _source.substr(_current_pos, 1),
                    _current_pos,
                    _current_pos,
                    _lineno,
                    _lineno,
                    _col_offset,
                    _col_offset
                };

                vec.emplace_back(std::move(indent_token));
            }
        }

        c = _source[++_current_pos];
    }
}