/*
    A tool to read file byte by byte.

    Created on 2024/12/4 by yezq.
*/

#ifndef BUFFERED_INPUT_STREAM_HPP
#define BUFFERED_INPUT_STREAM_HPP

#include <iostream>
#include <fstream>
#include <string>

namespace mpvm{

    const int BUFFER_LEN = 256;

    class BufferedInputStream {
    private:
        std::ifstream ifs;
        char szBuffer[BUFFER_LEN];
        unsigned short index;

    public:
        BufferedInputStream(std::string filename) {
            ifs = std::move(std::ifstream(filename, std::ios::in));
            ifs.read(szBuffer, BUFFER_LEN * sizeof(char));
            index = 0;
        }

        char read() {
            if (index < BUFFER_LEN) 
                return szBuffer[index++];
            else {
                index = 0;
                ifs.read(szBuffer, BUFFER_LEN * sizeof(char));
                return szBuffer[index++];
            }
        }

        int read_int() {
            int b1 = read() & 0xff;
            int b2 = read() & 0xff;
            int b3 = read() & 0xff;
            int b4 = read() & 0xff;

            return b4 << 24 | b3 << 16 | b2 << 8 | b1;
        }

        ~BufferedInputStream() {
            if (ifs.is_open()) {
                ifs.close();
            }
        }

    };

}
#endif