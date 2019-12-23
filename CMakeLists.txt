# CMakeLists.txt (project_root)
#
#      Author: CodeOhms
#     Contact: codeohms@protonmail.com
#  Created on: 10 Nov. 2019


cmake_minimum_required(VERSION 3.0)
project(MonoMatrix)


set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})
endif()

if(NOT ARDUINO STREQUAL PLATFORM)
    set(PLATFORM MBED)
endif()
message(STATUS "PLATFORM: " ${PLATFORM})

if(NOT FRAME_QUEUE_SIZE)
    set(FRAME_QUEUE_SIZE 5)
endif()
message(STATUS "FRAME_QUEUE_SIZE: " ${FRAME_QUEUE_SIZE})

if(NOT FRAME_WIDTH)
    set(FRAME_WIDTH 8)
endif()
message(STATUS "FRAME_WIDTH: " ${FRAME_WIDTH})

if(NOT FRAME_HEIGHT)
    set(FRAME_HEIGHT 8)
endif()
message(STATUS "FRAME_HEIGHT: " ${FRAME_HEIGHT})

if(NOT FRAME_RATE)
    set(FRAME_RATE 30)
endif()
message(STATUS "FRAME_RATE: " ${FRAME_RATE})


add_subdirectory(CMake_templates)
add_subdirectory(core)
add_subdirectory(unit_tests)