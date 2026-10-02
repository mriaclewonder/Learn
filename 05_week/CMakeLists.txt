cmake_minimum_required(VERSION 3.10)

project(05_week)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/05_week/")

file(GLOB SOURCE *cpp)

foreach(file ${SOURCE})
    get_filename_component(TARGET_NAME ${file} NAME_WE)
    add_executable(${TARGET_NAME} ${file})
endforeach()
