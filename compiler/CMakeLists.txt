add_subdirectory(lexer)

aux_source_directory(lexer LEXER_SRCS)

# 将两者合并为一个库
add_library(compiler STATIC ${LEXER_SRCS})

# 包含头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lexer ${CMAKE_CURRENT_SOURCE_DIR}/syntaxer)