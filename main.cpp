#include "buffered_input_stream.hpp"
#include "binary_file_parser.hpp" 
#include "interpreter.hpp"


#include <fstream>
#include <sstream>

int main(int argc, char** argv) {

    // std::ifstream ifs("../hello.py", std::ios::binary);

    // if (!ifs.is_open()) {
    //     std::cerr << "Unable to open file" << std::endl;
    //     return 1;
    // }

    

    mpvm::BufferedInputStream* bis = new mpvm::BufferedInputStream("../test_demo/__pycache__/test_while.cpython-310.pyc");

    // std::ostringstream oss;
    // oss << ifs.rdbuf();  // 将文件内容写入 stringstream

    // 将内容赋给 string
    // std::string content = oss.str();
    // mpvm::PythonLexer pl(content);
    // std::vector<mpvm::Token> vec = pl.tokenize();
    // std::cout << vec;
    mpvm::BinaryFileParser parser(bis);
    auto rtn = parser.parse();

    std::cout << *rtn << std::endl;

    mpvm::Interpreter interpreter;

    std::cout << "========== Start Run Code Object ==========" << std::endl;

    interpreter.run(static_cast<mpvm::CodeObject*>(rtn));

    // parser.parse();

    return 0;
}