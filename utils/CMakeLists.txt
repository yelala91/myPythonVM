set(MPVM_UTILS_SRC
    array_list.cpp
    binary_file_parser.cpp
)
add_library(utils STATIC ${MPVM_UTILS_SRC}) 

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/object)