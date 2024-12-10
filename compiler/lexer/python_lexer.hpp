// python_lexer.hpp

/*
    A Python lexer.

    created on 2024/12/5 by yezq.
*/

#ifndef _PYTHON_LEXER_HPP
#define _PYTHON_LEXER_HPP

#include <utility>
#include <vector>
#include "constant.hpp"

namespace mpvm{

    const int BYTES_BLOCK_BUFFER = 4096;

    class PythonLexer{
    private:
        std::string _source;
        int _start_pos;
        int _current_pos;
        int _lineno;
        int _col_offset;

        Token parse_IDENTIFIER();
        Token parse_COMMENT();
        // std::string& parse_KEYWORD();
        Token parse_NUMBER();
        Token parse_OPERATOR();
        Token parse_STRING();
        Token parse_SEPARATOR();
        Token parse_INDENT();

        void parse_SPACE(std::vector<mpvm::Token>&);
        

        // std::string& parse_UNIT();


    public:
        PythonLexer(const std::string& source, int start_pos=0) : 
            _source(source), _start_pos(start_pos), _current_pos(start_pos) , _lineno(1) {
                
            _col_offset     = 1;
        }

        PythonLexer(const char* chars, int start_pos=0) : _start_pos(start_pos), _current_pos(start_pos), _lineno(1)  {
            _source = std::move(std::string(chars));
            _col_offset     = 1;
        }

        std::vector<Token> tokenize();     /* transform source to a vector of tokens */

    };

}


#endif
