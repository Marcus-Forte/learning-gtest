cmake_minimum_required(VERSION 3.20)
project(learning-gtest)

option(BUILD_TESTS "Build unit tests." OFF)

add_library(mylib
  lib/algebraClass.cc
)

target_include_directories(mylib PUBLIC lib)

## Testing s
if(BUILD_TESTS)
  enable_testing()
  find_package(GTest REQUIRED)
  include(GoogleTest)
  message(STATUS "Building tests...")

  add_executable(tests 
  tst/tst.cc
  tst/tst_log.cc
  )

  target_link_libraries(tests
    GTest::gmock
    GTest::gtest
    mylib
  )
  gtest_discover_tests(tests)
endif()