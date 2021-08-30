cmake_minimum_required(VERSION 3.5)

#强制设置默认C++编译标志位缓存变量，缓存变量被定义在文件中，相当于全局变量，源文件中可以使用这个变量
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEX2" CACHE STRING "Set C++ Compile Flags" FORCE)

project(compile_flags)

add_executable(cmake_examples_compile_flags main.cpp)

#为可执行文件添加私有编译定义
target_compile_definitions(cmake_examples_compile_flags
    PRIVATE EX3
)