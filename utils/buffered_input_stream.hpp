/*
    A tool to read file byte by byte.

    Created on 2024/12/4 by yezq.
*/

#ifndef BUFFERED_INPUT_STREAM_HPP
#define BUFFERED_INPUT_STREAM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <utility>

namespace mpvm{

    const int BUFFER_LEN = 256;

    class BufferedInputStream {
    private:
        std::ifstream _ifs;
        char _szBuffer[BUFFER_LEN];
        unsigned short _index;

        std::streamsize _latest_read_length;

    public:
        BufferedInputStream(std::string filename) {
            _ifs = std::move(std::ifstream(filename, std::ios::in));
            _ifs.read(_szBuffer, BUFFER_LEN * sizeof(char));
            _index = 0;
        }

        char read() {
            if (_index < BUFFER_LEN) 
                return _szBuffer[_index++];
            else {
                _index = 0;
                _ifs.read(_szBuffer, BUFFER_LEN * sizeof(char));
                _latest_read_length = _ifs.gcount();
                return _szBuffer[_index++];
            }
        }

        bool eof() {
            return (_ifs.eof() && _latest_read_length == BUFFER_LEN && _index == BUFFER_LEN) 
                    || (_latest_read_length < BUFFER_LEN && _index == BUFFER_LEN);
        }

        int read_int() {
            int b1 = read() & 0xff;
            int b2 = read() & 0xff;
            int b3 = read() & 0xff;
            int b4 = read() & 0xff;

            return b4 << 24 | b3 << 16 | b2 << 8 | b1;
        }

        ~BufferedInputStream() {
            if (_ifs.is_open()) {
                _ifs.close();
            }
        }

    };

}
#endif