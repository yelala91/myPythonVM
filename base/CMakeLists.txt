file(GLOB SRC_FILES "*.cpp")
add_library(base STATIC ${SRC_FILES})

target_include_directories(base PUBLIC ${PROJECT_SOURCE_DIR}/base)