# CMakeLists.txt (project_root/unit_tests)
#
#      Author: CodeOhms
#     Contact: codeohms@protonmail.com
#  Created on: 10 Nov. 2019


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${CORE_INCLUDE_DIR})


# add_executable(run_tests run_tests.cpp
#    $<TARGET_OBJECTS:CORE>
# )

add_executable(run_tests run_tests.cpp)
target_link_libraries(run_tests CORE ${GTEST_LIBRARIES})