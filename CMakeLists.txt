cmake_minimum_required(VERSION 3.14)
project(S1mpleServer)

set(CMAKE_CXX_STANDARD 11)

include_directories ("${PROJECT_SOURCE_DIR}/s1mple")
add_subdirectory (s1mple)

add_executable(S1mpleServer main.cpp)
target_link_libraries(S1mpleServer lib_s1mple)