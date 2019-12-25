# CMakeLists.txt (project_root/matrix_handling)
#
#      Author: CodeOhms
#     Contact: codeohms@protonmail.com
#  Created on: 10 Nov. 2019


#add_library(MATRIX_DATA     OBJECT "matrix_data.cpp")
#add_library(MATRIX_HANDLING OBJECT "matrix_handling.cpp")


set(CORE_INCLUDE_DIR "../core/include")

target_sources(CORE
    PUBLIC
        "include/common.h"
        "include/macros.h"
        "include/matrix_data.h"
        "include/matrix_handling.h"
        "include/parsing.h"
    PRIVATE
        "common.cpp"
        "matrix_data.cpp"
        "matrix_handling.cpp"
        "parsing.cpp"
)

target_include_directories(CORE PUBLIC ${CMAKE_CURRENT_LIST_DIR})