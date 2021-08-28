cmake_minimum_required(VERSION 3.5) #最低CMake版本

project(hello_headers) #工程名

set(SOURCES src/hello.cpp src/main.cpp) #创建一个变量，名字叫SOURCES，它包含了所有的cpp文件

add_executable(hello_headers ${SOURCES}) #用所有的源文件生成一个可执行文件
#等价于 add_executable(hello_headers src/hello.cpp src/main.cpp)

target_include_directories(hello_headers PRIVATE ${PROJECT_SOURCE_DIR}/include) # 设置这个可执行文件hello_headers需要包含头文件路径

#PROJECT_SOURCE_DIR 指工程顶层目录
#PROJECT_BINARY_DIR 指编译目录
#PRIVATE指定了库的范围