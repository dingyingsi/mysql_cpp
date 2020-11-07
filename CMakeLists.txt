cmake_minimum_required(VERSION 3.16)
project(mysql_cpp C CXX)

set(CMAKE_C_STANDARD 11)

link_libraries(mysqlclient)

# linux
link_directories(/usr/lib64/mysql)

# mac os
#include_directories("/usr/local/opt/mysql-client/include/mysql")
#link_directories("/usr/local/opt/mysql-client/lib")

add_executable(mysql_cpp mysql/mysql_cpp.cpp)
add_executable(main main.cpp)