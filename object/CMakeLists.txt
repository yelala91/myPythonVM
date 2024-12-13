set(MPVM_OBJECT_SRC
    object.cpp
    none_object.cpp
    bool_object.cpp
    tuple_object.cpp
    ellipsis_object.cpp
    code_object.cpp
    integer.cpp
    string.cpp
    constant.cpp
)
add_library(object STATIC ${MPVM_OBJECT_SRC}) 

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/utils)