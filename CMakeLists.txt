# 指定 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(myPythonVM)
set(custom_name mpvm)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(base)

# 添加可执行文件
add_executable(${custom_name} main.cpp)

target_link_libraries(${custom_name} PRIVATE base)

target_include_directories(${custom_name}  PRIVATE ${PROJECT_SOURCE_DIR}/base)