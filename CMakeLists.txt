cmake_minimum_required(VERSION 3.0.0)
project(cpp-data-structures VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20 CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(CTest)
enable_testing()

add_executable(cpp-data-structures example-main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
