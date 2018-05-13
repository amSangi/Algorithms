cmake_minimum_required(VERSION 3.10)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)
set(ALGORITHMS_LIB_OUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(ALGORITHMS_BIN_OUT_PATH ${PROJECT_SOURCE_DIR}/test/bin)

add_subdirectory(src)
add_subdirectory(test)