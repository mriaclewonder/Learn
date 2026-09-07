cmake_minimum_required(VERSION 3.10)

project(03_week)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/03_week/")

file(GLOB SOURCE *cpp)

foreach(SOURCE ${SOURCE})
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)
    add_executable(${TARGET_NAME} ${SOURCE})
endforeach()
