set(RUNTIME_SRC
    interpreter.cpp
    constant.cpp
)

add_library(runtime STATIC ${RUNTIME_SRC})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/object)
include_directories(${PROJECT_SOURCE_DIR}/object/klass)