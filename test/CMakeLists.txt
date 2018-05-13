cmake_minimum_required(VERSION 3.10)
project(Test_Algorithms)

include_directories(../include/)
link_directories(${ALGORITHS_LIB_OUT_PATH})

set(EXECUTABLE_OUTPUT_PATH  ${ALGORITHMS_BIN_OUT_PATH})

file(GLOB TEST_FILES "*.cpp")

add_executable(${PROJECT_NAME} ${TEST_FILES} ../include/graph.hpp ../include/vertex.hpp ../include/edge.hpp ../include/pathfinder.hpp)

target_link_libraries(${PROJECT_NAME} Sorting)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)
