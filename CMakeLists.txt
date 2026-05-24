cmake_minimum_required(VERSION 3.14)
project(Project) # project name

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)


add_library(proj_lib STATIC # src to func files
    sources/example.cpp
)
target_include_directories(proj_lib PUBLIC headers) # include dirs


add_executable(proj_tests
    tests/test_proj.cpp
) # include tests
target_link_libraries(proj_tests proj_lib gtest_main)

enable_testing()
add_test(NAME ProjectTests COMMAND proj_tests) # adding tests