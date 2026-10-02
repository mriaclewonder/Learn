cmake_minimum_required(VERSION 3.12)

project(stl)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/stl/")

file(GLOB SOURCES "*.cpp")

foreach(SOURCE ${SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)
    add_executable(${TARGET_NAME} ${SOURCE})
endforeach()
