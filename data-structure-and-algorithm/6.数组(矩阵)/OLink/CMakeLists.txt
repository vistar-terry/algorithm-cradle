# CMakeLists.txt
# CMake最低版本要求
cmake_minimum_required(VERSION 3.16)

# 项目名称
project(olink)

# 生成可执行文件，test_1是可执行文件的名字，hello.c是源文件名称，如有其他源文件，可在后面添加
add_executable(olink olink.cpp) 
