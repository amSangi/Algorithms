cmake_minimum_required(VERSION 3.9)
PROJECT(Core)

include_directories(${CMAKE_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${ALGORITHMS_LIB_OUT_PATH})

file(GLOB ALGORITHMS_SRC "*.cpp")

add_library(${PROJECT_NAME} ${ALGORITHMS_SRC})
