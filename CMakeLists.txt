cmake_minimum_required(VERSION 3.20)
project(learning-gtest)

option(BUILD_TESTS "Build unit tests." OFF)

add_library(mylib
  lib/class.cc
)

target_include_directories(mylib PUBLIC lib)
if(BUILD_TESTS)
  enable_testing()
  find_package(GTest REQUIRED)
  include(GoogleTest)
  message(STATUS "Building tests...")

  add_executable(tests 
    tst/tst.cc
  )

  target_link_libraries(tests
    GTest::gtest_main
    GTest::gmock
    GTest::gtest
    mylib
  )
  gtest_discover_tests(tests)
endif()