cmake_minimum_required(VERSION 3.17)
set (CMAKE_MINIMUM_REQUIRED_VERSION true)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED true)

project (Epilogger)

add_compile_options(
    "-Wall" "-Wextra" "-pedantic" "-Wpointer-arith"
)

add_subdirectory(Src)