cmake_minimum_required(VERSION 3.5)
project(hello_library)
# Create a library
# 库的源文件hello.cpp生成静态库hello_library
add_library(hello_library STATIC src/hello.cpp)

target_include_directories(hello_library PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Create an executable
# Add an executable with the above sources
add_executable(hello_binary src/main.cpp)

# 链接可执行文件和静态库
target_link_libraries(hello_binary PRIVATE hello_library)

#链接库和包含头文件都有关于scope这三个关键字的用法