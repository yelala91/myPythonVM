aux_source_directory(. BASE_SRCS)
add_library(base STATIC ${BASE_SRCS}) 

include_directories(${CMAKE_CURRENT_SOURCE_DIR})