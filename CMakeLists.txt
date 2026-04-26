cmake_minimum_required(VERSION 3.20)
project(LeetCode CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE DAILY_MAINS "${CMAKE_SOURCE_DIR}/Dailies/*/main.cpp")

foreach(MAIN_FILE ${DAILY_MAINS})
    get_filename_component(DAY_DIR ${MAIN_FILE} DIRECTORY)
    get_filename_component(DAY_NAME ${DAY_DIR} NAME)

    # Sanitize: CMake target names can't have hyphens
    string(REPLACE "-" "_" TARGET_NAME "Daily_${DAY_NAME}")

    add_executable(${TARGET_NAME} ${MAIN_FILE})
endforeach()

file(GLOB ACTIVITY_SOURCES "${CMAKE_SOURCE_DIR}/Practice/*.cpp")

foreach(ACTIVITY_FILE ${ACTIVITY_SOURCES})
    get_filename_component(ACTIVITY_NAME ${ACTIVITY_FILE} NAME_WE)
    string(REPLACE "-" "_" PRACTICE_TARGET_NAME "Practice_${ACTIVITY_NAME}")
    add_executable(${PRACTICE_TARGET_NAME} ${ACTIVITY_FILE})
endforeach()