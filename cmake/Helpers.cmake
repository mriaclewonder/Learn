# ============================================================
# Helpers.cmake —— 公共构建辅助
# ============================================================

# add_examples()
#   把当前模块目录下每个 .cpp 编译为独立可执行文件，统一输出到 bin/<模块名>/。
#   模块名取自当前源目录名（如 07_stl）。
#   目标名加模块名前缀：CMake 目标名全局唯一，多个模块都含 main.cpp 时，
#   若直接用文件名作目标名会冲突，加前缀后各模块可同时启用。
#   产物名仍用源文件名（OUTPUT_NAME），故 bin/<模块名>/main.exe 保持不变。
function(add_examples)
    get_filename_component(_module "${CMAKE_CURRENT_SOURCE_DIR}" NAME)
    set(_output_dir "${CMAKE_SOURCE_DIR}/bin/${_module}")

    file(GLOB _sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
    foreach(_source ${_sources})
        get_filename_component(_stem "${_source}" NAME_WE)
        set(_target "${_module}_${_stem}")
        add_executable("${_target}" "${_source}")
        set_target_properties("${_target}" PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${_output_dir}"
            OUTPUT_NAME "${_stem}")
    endforeach()
endfunction()
