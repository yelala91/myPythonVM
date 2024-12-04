// binary_file_parser.hpp

/*
    A helper for parsing the code object

    created on 2024/12/4 by yezq.
*/

#ifndef _BINARY_FILE_PARSER_HPP
#define _BINARY_FILE_PARSER_HPP

#include "buffered_input_stream.hpp"
#include "code_object.hpp"

namespace mpvm{

    class BinaryFileParser {
    
    private:
        BufferedInputStream* file_stream;

    public:

        BinaryFileParser(BufferedInputStream* stream) : file_stream(stream) {}

        CodeObject* parse();
        CodeObject* get_code_object();
    };
}

#endif
