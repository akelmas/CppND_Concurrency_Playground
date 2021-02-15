cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_STANDARD 17)

project(ConcurrencyPlayGround)

file(GLOB project_SRCS src/*.cpp)
find_package (Threads)
add_executable(test ${project_SRCS})
target_link_libraries (test ${CMAKE_THREAD_LIBS_INIT})