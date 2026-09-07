cmake_minimum_required(VERSION 3.10)

project(cpp11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/cpp11")

# 收集当前目录下所有 .cpp 源文件
file(GLOB SOURCES "*.cpp")

# 每个 .cpp 编译为一个独立的可执行文件
foreach(SOURCE ${SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE) # 取文件名(不含扩展名)作为目标名
    add_executable(${TARGET_NAME} ${SOURCE})
endforeach()