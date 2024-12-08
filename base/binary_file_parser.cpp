#include "binary_file_parser.hpp"
#include "code_object.hpp"

mpvm::CodeObject* mpvm::BinaryFileParser::parse() {
    int magic_number = file_stream->read_int();
    std::cout << "Magic number is 0x"<< std::hex << magic_number << std::endl;

    int bit_field = file_stream->read_int();
    std::cout << "Bit field is 0x" << std::hex << bit_field << std::endl;

    int last_modified_time = file_stream->read_int();
    std::cout << "Last modified time is " << std::dec << last_modified_time << std::endl;

    int file_size = file_stream->read_int();
    std::cout << "File size is " << file_size << " bytes "<< std::endl;

    u_int8_t object_type = file_stream->read();
    // std::cout << object_type << std::endl;
    if (object_type == 0xe3) {
        CodeObject* results = get_code_object();
        std::cout << "parse OK!" << std::endl;
        return results;
    }

    return NULL;
}

mpvm::CodeObject* mpvm::BinaryFileParser::get_code_object() {
    return NULL;
}