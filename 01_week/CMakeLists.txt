# ============================================================
# 01_week - 第一周示例代码
# ============================================================

# 可执行文件输出到 bin/01_week/ 目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/01_week")

# 收集当前目录下所有 .cpp 源文件
file(GLOB SOURCES "*.cpp")

# 每个 .cpp 编译为一个独立的可执行文件
foreach(SOURCE ${SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)  # 取文件名(不含扩展名)作为目标名
    add_executable(${TARGET_NAME} ${SOURCE})
endforeach()
