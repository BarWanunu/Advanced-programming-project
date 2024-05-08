cmake_minimum_required(VERSION 3.14)
project(" Advanced-programming-project") 
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
googletest
URL
https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
enable_testing()
# this is where the code we want to test
set(SOURCE_FILES
src/AddURL.cpp 
src/BloomPart.cpp
src/BytesArray.cpp 
src/CheckURL.cpp 
src/HashFunction.cpp
src/ICommand.cpp
src/InputArr.cpp
src/Node.cpp 
src/URLList.cpp
)
set(TEST_FILES1
tests/test_main.cpp # this is the main for tests
        tests/URL_test.cpp # this file contain the tests
)

add_executable(UrlTest ${TEST_FILES1})
# Link Google Test to the test executable
target_link_libraries(UrlTest PRIVATE gtest gtest_main)
# Include the source directory for tests
target_include_directories(UrlTest PRIVATE src)

set(TEST_FILES2
        tests/test_main.cpp # this is the main for tests
        tests/BloomPart_test.cpp # this file contain the tests
)

add_executable(BloomPartTest ${TEST_FILES2})
# Link Google Test to the test executable
target_link_libraries(BloomPartTest PRIVATE gtest gtest_main)
# Include the source directory for tests
target_include_directories(BloomPartTest PRIVATE src)

set(TEST_FILES3
            tests/test_main.cpp # this is the main for tests
        tests/HashFunction_test.cpp # this file contain the tests
)

add_executable(HashFunctionTest ${TEST_FILES3})
# Link Google Test to the test executable
target_link_libraries(HashFunctionTest PRIVATE gtest gtest_main)
# Include the source directory for tests
target_include_directories(HashFunctionTest PRIVATE src)

include(GoogleTest)
add_test(NAME UrlTest COMMAND UrlTest)
add_test(NAME BloomPartTest COMMAND BloomPartTest)
add_test(NAME HashFunctionTest COMMAND HashFunctionTest)
add_executable(new_target src/InputArr.cpp)
