set(MPVM_OBJECT_SRC
    string.cpp
)
add_library(object STATIC ${MPVM_OBJECT_SRC}) 

include_directories(${CMAKE_CURRENT_SOURCE_DIR})