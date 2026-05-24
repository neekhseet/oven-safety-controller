cmake_minimum_required(VERSION 3.14)
project(OvenSafetyController) # project name

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(osc_lib STATIC # src to func files
    sources/controller.cpp
)
target_include_directories(osc_lib PUBLIC headers) # include dirs


add_executable(osc_tests
    tests/test_osc.cpp
    tests/mock.h
) # include tests
target_link_libraries(osc_tests osc_lib gtest_main gmock)

enable_testing()
add_test(NAME OvenSafetyControllerTests COMMAND osc_tests) # adding tests