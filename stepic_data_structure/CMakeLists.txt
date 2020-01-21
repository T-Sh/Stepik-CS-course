cmake_minimum_required(VERSION 3.13)
project(stepic_structure)

set(CMAKE_CXX_STANDARD 14)

set(BUILD_1 1.parentheses)
set(SOURCE_FILES_1 basic_structure/parentheses.c++)
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_2 2.height_of_tree)
set(SOURCE_FILES_2 basic_structure/height_of_tree.c++)
add_executable(${BUILD_2} ${SOURCE_FILES_2})

set(BUILD_3 3.simulation_net_pac)
set(SOURCE_FILES_3 basic_structure/simulation_net_pac.c++)
add_executable(${BUILD_3} ${SOURCE_FILES_3})

set(BUILD_4 4.stack_new)
set(SOURCE_FILES_4 basic_structure/stack_max.c++)
add_executable(${BUILD_4} ${SOURCE_FILES_4})

set(BUILD_5 5.max_in_window)
set(SOURCE_FILES_5 basic_structure/max_in_window.c++)
add_executable(${BUILD_5} ${SOURCE_FILES_5})

set(BUILD_6 6.create_heap)
set(SOURCE_FILES_6 queue_priority/create_heap.c++)
add_executable(${BUILD_6} ${SOURCE_FILES_6})

set(BUILD_7 7.parallel_process)
set(SOURCE_FILES_7 queue_priority/parallel_process.c++)
add_executable(${BUILD_7} ${SOURCE_FILES_7})

set(BUILD_8 8.combine_tabs)
set(SOURCE_FILES_8 set_system/combine_tabs.c++)
add_executable(${BUILD_8} ${SOURCE_FILES_8})

set(BUILD_9 9.auto_analysis_programm)
set(SOURCE_FILES_9 set_system/auto_analysis_programm.c++)
add_executable(${BUILD_9} ${SOURCE_FILES_9})

set(BUILD_10 10.phone_book)
set(SOURCE_FILES_10 hash_table/phone_book.c++)
add_executable(${BUILD_10} ${SOURCE_FILES_10})

set(BUILD_11 11.hash_chain)
set(SOURCE_FILES_11 hash_table/hash_chain.c++)
add_executable(${BUILD_11} ${SOURCE_FILES_11})

set(BUILD_12 12.find_in_text)
set(SOURCE_FILES_12 hash_table/find_in_text.c++)
add_executable(${BUILD_12} ${SOURCE_FILES_12})

set(BUILD_13 13.binary_tree_pass)
set(SOURCE_FILES_13 search_trees/binary_tree_pass.c++)
add_executable(${BUILD_13} ${SOURCE_FILES_13})

set(BUILD_14 14.check_search_tree)
set(SOURCE_FILES_14 search_trees/check_search_tree.c++)
add_executable(${BUILD_14} ${SOURCE_FILES_14})

set(BUILD_15 15.common_check_tree)
set(SOURCE_FILES_15 search_trees/common_check_tree.c++)
add_executable(${BUILD_15} ${SOURCE_FILES_15})

set(BUILD_16 16.set_with_sum)
set(SOURCE_FILES_16 search_trees/set_with_sum.c++)
add_executable(${BUILD_16} ${SOURCE_FILES_16})