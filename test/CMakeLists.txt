cmake_minimum_required(VERSION 3.9)
project(Test)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${ALGORITHS_LIB_OUT_PATH})

set(EXECUTABLE_OUTPUT_PATH  ${ALGORITHMS_BIN_OUT_PATH})

file(GLOB TEST_FILES "*.cpp")

add_executable(${PROJECT_NAME} ${TEST_FILES})

target_link_libraries(${PROJECT_NAME} Core)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)
