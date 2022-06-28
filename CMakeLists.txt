cmake_minimum_required(VERSION 3.16)

project(MyProject VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/
    ${CMAKE_MODULE_PATH}
)
include(AddGitSubmodule)

set(EXEUTABLE_NAME Executable)
set(LIB_NAME MyLib)


set(MYVAR HAHAHA)

add_subdirectory(configured)

set(SPDLOG_PATH external/spdlog)
add_git_submodule(${SPDLOG_PATH})

add_library(${LIB_NAME} STATIC
  my_lib.cpp
)
target_link_libraries(${LIB_NAME} 
  spdlog
)

target_include_directories(${LIB_NAME} PUBLIC
  ${CMAKE_BINARY_DIR}/configured_files
)

add_executable(${EXEUTABLE_NAME} main.cpp)
target_link_libraries(${EXEUTABLE_NAME} 
  ${LIB_NAME}
)

option(TESTS "Build the tests" ON)
if(TESTS)
    message("Build the tests")
endif()
