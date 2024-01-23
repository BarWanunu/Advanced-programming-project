cmake_minimum_required(VERSION 3.14)
project("Advanced-programming-project")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

enable_testing()

# Source files for the main project
set(SOURCE_FILES
    src/AddURL.cpp 
    src/BloomPart.cpp
    src/BytesArray.cpp 
    src/CheckURL.cpp 
    src/HashFunction.cpp
    src/ICommand.cpp 
    src/URLList.cpp
)

# Common test files
set(TEST_COMMON_FILES
    tests/test_main.cpp
)

# Test files for UrlTest
set(TEST_FILES_URL
    tests/URL_test.cpp
)

# Test files for BloomPartTest
set(TEST_FILES_BLOOM
    tests/BloomPart_test.cpp
)

# Test files for HashFunctionTest
set(TEST_FILES_HASH
    tests/HashFunction_test.cpp
)

# UrlTest executable
add_executable(UrlTest ${TEST_COMMON_FILES} ${TEST_FILES_URL})
target_link_libraries(UrlTest PRIVATE gtest gtest_main)
target_include_directories(UrlTest PRIVATE src)
add_test(NAME UrlTest COMMAND UrlTest)

# BloomPartTest executable
add_executable(BloomPartTest ${TEST_COMMON_FILES} ${TEST_FILES_BLOOM})
target_link_libraries(BloomPartTest PRIVATE gtest gtest_main)
target_include_directories(BloomPartTest PRIVATE src)
add_test(NAME BloomPartTest COMMAND BloomPartTest)

# HashFunctionTest executable
add_executable(HashFunctionTest ${TEST_COMMON_FILES} ${TEST_FILES_HASH})
target_link_libraries(HashFunctionTest PRIVATE gtest gtest_main)
target_include_directories(HashFunctionTest PRIVATE src)
add_test(NAME HashFunctionTest COMMAND HashFunctionTest)