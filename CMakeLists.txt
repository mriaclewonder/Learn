cmake_minimum_required(VERSION 3.16)
project(Learn)

# 示例代码普遍用到 C++14/17 特性（make_unique、变参模板等）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 公共构建辅助宏 add_examples()
include(cmake/Helpers.cmake)

# 按学习路线图周号登记模块；新增模块在此追加一行 add_subdirectory
add_subdirectory(01_const)
add_subdirectory(02_conversion)
add_subdirectory(03_operators)
add_subdirectory(04_smartptr)
add_subdirectory(05_move)
add_subdirectory(06_lambda)
add_subdirectory(07_stl)
add_subdirectory(13_template)
