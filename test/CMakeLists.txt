cmake_minimum_required(VERSION 3.2)
project(test_runner)

add_subdirectory( base )

set( test_sources
  base/vector_wrapper_tests.cpp
  main.cpp)

add_executable( tests ${test_sources} )

target_link_libraries( tests
  base
  gtest_main )

add_test( NAME test COMMAND tests)

