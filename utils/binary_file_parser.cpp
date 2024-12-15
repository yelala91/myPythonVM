#include "binary_file_parser.hpp"

#include "none_object.hpp"
#include "ellipsis_object.hpp"
#include "bool_object.hpp"
#include "integer.hpp"
#include "code_object.hpp"

namespace mpvm {
    namespace obj_type {

        constexpr char NULL_ = '0';                // 注意避免与标准库中的NULL宏冲突
        constexpr char NONE = 'N';
        constexpr char FALSE = 'F';
        constexpr char TRUE = 'T';
        constexpr char STOPITER = 'S';
        constexpr char ELLIPSIS = '.';
        constexpr char BINARY_FLOAT = 'g';         // Version 0 uses FLOAT instead.
        constexpr char BINARY_COMPLEX = 'y';       // Version 0 uses COMPLEX instead.
        constexpr char LONG = 'l';                 // See also INT.
        constexpr char STRING = 's';               // Bytes. (Name comes from Python 2.)
        constexpr char TUPLE = '(';                // See also SMALL_TUPLE.
        constexpr char LIST = '[';
        constexpr char DICT = '{';
        constexpr char CODE = 'c';
        constexpr char UNICODE = 'u';
        constexpr char UNKNOWN = '?';

        // added in version 2:
        constexpr char SET = '<';
        constexpr char FROZENSET = '>';

        // added in version 5:
        constexpr char SLICE = ':';

        // Special cases for unicode strings (added in version 4)
        constexpr char INTERNED = 't';             // Version 1+
        constexpr char ASCII = 'a';
        constexpr char ASCII_INTERNED = 'A';
        constexpr char SHORT_ASCII = 'z';
        constexpr char SHORT_ASCII_INTERNED = 'Z';

        // Special cases for small objects
        constexpr char INT = 'i';                  // All versions. 32-bit encoding.
        constexpr char SMALL_TUPLE = ')';          // Version 4+

        // Supported for backwards compatibility
        constexpr char COMPLEX = 'x';              // Generated for version 0 only.
        constexpr char FLOAT = 'f';                // Generated for version 0 only.
        constexpr char INT64 = 'I';                // Not generated any more.

        // References (added in version 3)
        constexpr char REF = 'r';
        constexpr unsigned char FLAG_REF = '\x80'; // with a type, add obj to index
    }
}

mpvm::Object* mpvm::BinaryFileParser::parse() {

    std::cout << "Parsing binary file..." << std::endl;

    std::cout << "========== Header ==========" << std::endl;
    int magic_number = file_stream->read_int();
    std::cout << "Magic number is 0x"<< std::hex << magic_number << std::endl;

    int bit_field = file_stream->read_int();
    std::cout << "Bit field is 0x" << std::hex << bit_field << std::endl;

    int last_modified_time = file_stream->read_int();
    std::cout << "Last modified time is " << std::dec << last_modified_time << std::endl;

    int file_size = file_stream->read_int();
    std::cout << "File size is " << file_size << " bytes "<< std::endl;
    
    return read_obj();
}

void mpvm::BinaryFileParser::_add_ref(Object* obj, u_int8_t flag) {
    if (flag){
        _refs->add(obj);
    }
}

mpvm::Object* mpvm::BinaryFileParser::read_obj() {

    using namespace mpvm::obj_type;

    u_int8_t type, code, flag;
    mpvm::Object* rtnval = nullptr;

    int n, temp_idx, idx;
    char* temp_str = nullptr;

    Tuple* tuple = nullptr;

    if (!file_stream->eof())
        code = file_stream->read();
    else return rtnval;

    flag = code & FLAG_REF;
    type = code & ~FLAG_REF;

    // std::cout << "Type is " << type << std::endl;
    // std::cout << "Flag is " << flag << std::endl;

    switch(type) {
        
    case NULL_:
        break;

    case NONE:
        rtnval = mpvm::NONE_OBJECT;
        _add_ref(rtnval, flag);
        break;

    case ELLIPSIS:
        rtnval = mpvm::ELLIPSIS_OBJECT;
        break;
    
    case TRUE:
        rtnval = mpvm::TRUE_OBJECT;
        break;

    case FALSE:
        rtnval = mpvm::FALSE_OBJECT;
        break;
    
    case INT:
        n = file_stream->read_int();
        rtnval = new Integer(n);
        _add_ref(rtnval, flag);
        break;

    case FLOAT:
        n = file_stream->read_int();
        break;

    case STRING:
        n = file_stream->read_int();

        temp_str = new char[n+1];
        for(size_t i = 0; i < n; i++) 
            temp_str[i] = file_stream->read();
        
        temp_str[n+1] = '\0';
        
        rtnval = new String(temp_str, n, false);
        // rtnval = new Integer(-2);
        _add_ref(rtnval, flag);

        delete[] temp_str;
        break;
        
    case SMALL_TUPLE:
        n = file_stream->read() & 0xff;
        temp_idx = 0;

        tuple = new Tuple();
        _add_ref(tuple, flag);

        while(temp_idx++ < n) {
            tuple->add(read_obj());
        }
        
        
        rtnval = tuple;

        break;
    
    case TUPLE:
        n = file_stream->read_int();

        temp_idx = 0;

        tuple = new Tuple();
        _add_ref(tuple, flag);

        while(temp_idx++ < n) {
            tuple->add(read_obj());
        }
        rtnval = tuple;

        break;

    case SHORT_ASCII_INTERNED:
        
        n = file_stream->read() & 0xff;

        temp_str = new char[n];

        for(size_t i = 0; i < n; i++)
            temp_str[i] = file_stream->read();
        
        rtnval = new String(temp_str, n, true);
        _add_ref(rtnval, flag);

        delete[] temp_str;
        break;
        
    case SHORT_ASCII:
        
        n = file_stream->read() & 0xff;

        temp_str = new char[n];

        for(size_t i = 0; i < n; i++)
            temp_str[i] = file_stream->read();
        
        rtnval = new String(temp_str, true);
        _add_ref(rtnval, flag);

        delete[] temp_str;
        break;
        
    case CODE:
    {   
        CodeObject* temp = new CodeObject();
        _add_ref(rtnval, flag);

        int argcount        = file_stream->read_int();
        int posonlyargcount = file_stream->read_int();
        int kwonlyargcount  = file_stream->read_int();
        int nlocals         = file_stream->read_int();
        int stacksize       = file_stream->read_int();
        int flags           = file_stream->read_int();

        
        String* bytecodes   = static_cast<String*>(read_obj());
        Tuple* consts       = static_cast<Tuple*>(read_obj());
        Tuple* names        = static_cast<Tuple*>(read_obj());
        Tuple* varnames     = static_cast<Tuple*>(read_obj());
        Tuple* freenames    = static_cast<Tuple*>(read_obj());
        Tuple* cellvars     = static_cast<Tuple*>(read_obj());
        String* filename   = static_cast<String*>(read_obj());
        String* co_name     = static_cast<String*>(read_obj());
        int firstlineno    = file_stream->read_int();
        String* notable     = static_cast<String*>(read_obj());
        
        temp->set(
            argcount, 
            posonlyargcount,
            kwonlyargcount,
            nlocals,
            stacksize,
            flags,
            bytecodes,
            consts, 
            names,
            varnames,
            freenames,
            cellvars,
            filename,
            co_name, 
            firstlineno,
            notable
            );
        rtnval = temp;

    }
        break;


    case REF:
        idx = file_stream->read_int();
        if (!_refs) {
            std::cerr << "Refs tuple is not inited." << std::endl;
        } else if (idx >= _refs->size()) {
            std::cerr << "Ref index out of range." << std::endl;
        } else {
            rtnval = _refs->get(idx);
        }
        break;

    default:
        std::cerr << "The type " << type << " is not supported." << std::endl;
        break;
    
    }

    return rtnval;
} 
