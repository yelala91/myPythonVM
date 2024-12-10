#include "binary_file_parser.hpp"
#include "code_object.hpp"


/* Supported types */
#define TYPE_NULL               '0'
#define TYPE_NONE               'N'
#define TYPE_FALSE              'F'
#define TYPE_TRUE               'T'
#define TYPE_STOPITER           'S'
#define TYPE_ELLIPSIS           '.'
#define TYPE_BINARY_FLOAT       'g'  // Version 0 uses TYPE_FLOAT instead.
#define TYPE_BINARY_COMPLEX     'y'  // Version 0 uses TYPE_COMPLEX instead.
#define TYPE_LONG               'l'  // See also TYPE_INT.
#define TYPE_STRING             's'  // Bytes. (Name comes from Python 2.)
#define TYPE_TUPLE              '('  // See also TYPE_SMALL_TUPLE.
#define TYPE_LIST               '['
#define TYPE_DICT               '{'
#define TYPE_CODE               'c'
#define TYPE_UNICODE            'u'
#define TYPE_UNKNOWN            '?'
// added in version 2:
#define TYPE_SET                '<'
#define TYPE_FROZENSET          '>'
// added in version 5:
#define TYPE_SLICE              ':'
// Remember to update the version and documentation when adding new types.

/* Special cases for unicode strings (added in version 4) */
#define TYPE_INTERNED           't' // Version 1+
#define TYPE_ASCII              'a'
#define TYPE_ASCII_INTERNED     'A'
#define TYPE_SHORT_ASCII        'z'
#define TYPE_SHORT_ASCII_INTERNED 'Z'

/* Special cases for small objects */
#define TYPE_INT                'i'  // All versions. 32-bit encoding.
#define TYPE_SMALL_TUPLE        ')'  // Version 4+

/* Supported for backwards compatibility */
#define TYPE_COMPLEX            'x'  // Generated for version 0 only.
#define TYPE_FLOAT              'f'  // Generated for version 0 only.
#define TYPE_INT64              'I'  // Not generated any more.

/* References (added in version 3) */
#define TYPE_REF                'r'
#define FLAG_REF                '\x80' /* with a type, add obj to index */


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
    // int argcount = file_stream->read_int();
    // std::cout << argcount << std::endl;
    // int nlocals = file_stream->read_int();
    // int stacksize = file_stream->read_int();
    // int flags = file_stream->read_int();

    // std::cout << flags << std::endl;

    // mpvm::String* bytes_codes                   = get_byte_codes();
    // mpvm::ArrayList<mpvm::Object>* consts       = get_consts();
    // mpvm::ArrayList<mpvm::Object>* names        = get_names();
    // mpvm::ArrayList<mpvm::Object>* var_names    = get_var_names();
    // mpvm::ArrayList<mpvm::Object>* free_vars    = get_free_vars();
    // mpvm::ArrayList<mpvm::Object>* cell_vars    = get_cell_vars();

    // mpvm::String* file_name     = get_file_name();
    // mpvm::String* module_name   = get_name();
    // int begin_line_no           = file_stream->read_int();
    // mpvm::String* lnotab        = get_no_table();

    // return new CodeObject(argcount, nlocals, stacksize, flags, bytes_codes, 
    //     consts, names, var_names, free_vars, cell_vars, file_name, module_name, 
    //     begin_line_no, lontab);
    return NULL;
}

mpvm::Object* mpvm::BinaryFileParser::read_obj() {

    u_int8_t type, code, flag;
    mpvm::Object* rtnval = nullptr;

    if (!file_stream.eof())
        code = file_stream->read();
    else return rtnval;

    flag = code & FLAG_REF;
    type = code & ~FLAG_REF;

    switch(c) {
        
    case TYPE_NULL:
        break;

    case TYPE_NONE:
        rtnval = mpvm::None;
        break;
    
    
    

    }
        
    
        

} 