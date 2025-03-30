cmake_minimum_required(VERSION 3.2...3.30.2)
project(LongNumberProject)

add_library(long_number STATIC long_number.cpp)

add_executable(test_long_number test_long_number.cpp)

target_link_libraries(test_long_number long_number)

enable_testing()
add_test(NAME test_long_number COMMAND test_long_number)