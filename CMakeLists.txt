cmake_minimum_required(VERSION 3.10)

project(HtmlParser)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(mini-renderer src/main.cpp src/html_element.cpp src/html_parser.cpp src/utils.cpp)
add_executable(test tests/test_main.cpp src/html_element.cpp src/html_parser.cpp src/utils.cpp)

include_directories(include)
