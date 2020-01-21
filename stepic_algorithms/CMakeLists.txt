cmake_minimum_required(VERSION 3.13)
project(stepic_alg)

set(CMAKE_CXX_STANDARD 14)

set(BUILD_1 1.cover_point)
set(SOURCE_FILES_1 cover_point.c++)
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_2 2.infinite_backpack)
set(SOURCE_FILES_2 infinite_backpack.cpp)
add_executable(${BUILD_2} ${SOURCE_FILES_2})

set(BUILD_3 3.terms)
set(SOURCE_FILES_3 terms.cpp)
add_executable(${BUILD_3} ${SOURCE_FILES_3})

set(BUILD_4 4.haffman)
set(SOURCE_FILES_4 haffman.cpp)
add_executable(${BUILD_4} ${SOURCE_FILES_4})

set(BUILD_5 5.priority_queue)
set(SOURCE_FILES_5 priority_queue.c++)
add_executable(${BUILD_5} ${SOURCE_FILES_5})

set(BUILD_6 6.decode_haffman)
set(SOURCE_FILES_6 decode_haffman.c++)
add_executable(${BUILD_6} ${SOURCE_FILES_6})

set(BUILD_7 7.binary_search)
set(SOURCE_FILES_7 binary_search.c++)
add_executable(${BUILD_7} ${SOURCE_FILES_7})

set(BUILD_8 8.merge_sort)
set(SOURCE_FILES_8 merge_sort.c++)
add_executable(${BUILD_8} ${SOURCE_FILES_8})

set(BUILD_9 9.quick_sort)
set(SOURCE_FILES_9 quick_sort.c++)
add_executable(${BUILD_9} ${SOURCE_FILES_9})

set(BUILD_10 10.count_sort)
set(SOURCE_FILES_10 count_sort.c++)
add_executable(${BUILD_10} ${SOURCE_FILES_10})

set(BUILD_11 11.LDS)
set(SOURCE_FILES_11 LDS.c++)
add_executable(${BUILD_11} ${SOURCE_FILES_11})

set(BUILD_12 12.LIS)
set(SOURCE_FILES_12 LIS.c++)
add_executable(${BUILD_12} ${SOURCE_FILES_12})

set(BUILD_13 13.edit_distance)
set(SOURCE_FILES_13 edit_distance.c++)
add_executable(${BUILD_13} ${SOURCE_FILES_13})

set(BUILD_14 14.backpack)
set(SOURCE_FILES_14 backpack.c++)
add_executable(${BUILD_14} ${SOURCE_FILES_14})

set(BUILD_15 15.stairway)
set(SOURCE_FILES_15 stairway.c++)
add_executable(${BUILD_15} ${SOURCE_FILES_15})

set(BUILD_16 16.calculator)
set(SOURCE_FILES_16 calculator.c++)
add_executable(${BUILD_16} ${SOURCE_FILES_16})