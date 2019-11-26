# CMakeLists.txt (project_root/unit_tests)
#
#      Author: CodeOhms
#     Contact: codeohms@protonmail.com
#  Created on: 10 Nov. 2019


cmake_minimum_required(VERSION 2.6)
project(MonoMatrix_Test_Suite)


set(CORE_INCLUDE_DIR "../core/include")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${CORE_INCLUDE_DIR})


add_executable(run_tests run_tests.cpp
    $<TARGET_OBJECTS:CORE>
)
target_link_libraries(run_tests ${GTEST_LIBRARIES})