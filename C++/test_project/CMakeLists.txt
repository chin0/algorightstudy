cmake_minimum_required(VERSION 3.0)

project(hello-vsc)

set(SOURCE hello-vsc.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})
add_executable(fuck hello-vsc.cpp)
