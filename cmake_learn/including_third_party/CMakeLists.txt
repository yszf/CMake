cmake_minimum_required(VERSION 3.5)

# Set the project name
project(third_party_include)

IF (WIN32)
	MESSAGE(STATUS "Now is windows")
    set(BOOST_ROOT "D:/Projects/C++/boost/boost_1_77_0")
    set(BOOST_INCLUDEDIR "D:/Projects/C++/boost/boost_1_77_0")
    set(BOOST_LIBRARYDIR "D:/Projects/C++/boost/boost_1_77_0/stage/lib")
    find_package(Boost 1.46.1 REQUIRED)
ELSEIF (UNIX)
	MESSAGE(STATUS "Now is UNIX-like OS's.")
    # find a boost instll with the libraries filesystem and system 使用库文件系统和系统查找boost install
    find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)
ENDIF ()

# 这是第三方库，而不是自己生成的静态动态库
# check if boost was found
if(Boost_FOUND)
    message("boost found")
else()
    message(FATAL_ERROR "Cannot find Boost")
endif()

# Add an executable
add_executable(third_party_include main.cpp)

# 链接指定的boost库文件和头文件。
target_include_directories(third_party_include PRIVATE ${Boost_INCLUDE_DIRS})

if(UNIX)
    # link the boost libraries
    target_link_libraries(third_party_include PRIVATE Boost::filesystem)
ELSEIF(WIN32)
    target_link_directories(third_party_include PRIVATE ${Boost_LIBRARY_DIRS})
ENDIF()


