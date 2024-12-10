# aux_source_directory(. LEXER_SRCS)
set(LEXER_SRCS 
    constant.cpp
    python_lexer.cpp
)
add_library(lexer STATIC ${LEXER_SRCS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})