#include "buffered_input_stream.hpp"
#include "binary_file_parser.hpp" 

int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "vm need a parameter: filename\n" << std::endl;

        return 0;
    }

    mpvm::BufferedInputStream* bis = new mpvm::BufferedInputStream(argv[1]);
    mpvm::BinaryFileParser parser(bis);

    parser.parse();

    return 0;
}