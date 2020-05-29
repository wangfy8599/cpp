cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(module_name vector-example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(${module_name} VERSION 0.1)

aux_source_directory(src SRC_DIR)

add_executable(${module_name} ${SRC_DIR})

target_include_directories (
    ${module_name}
    PUBLIC
    "include"
)

