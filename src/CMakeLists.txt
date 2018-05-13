cmake_minimum_required(VERSION 3.10)
PROJECT(Sorting)

include_directories(../include)
set(LIBRARY_OUTPUT_PATH ${ALGORITHMS_LIB_OUT_PATH})

file(GLOB ALGORITHMS_SRC "*.cpp")


add_library(${PROJECT_NAME} SHARED ${ALGORITHMS_SRC})
