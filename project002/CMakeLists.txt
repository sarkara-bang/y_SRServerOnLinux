cmake_minimum_required(VERSION 3.22)

project(simpleserver)

set(EXECUTABLE_OUTPUT_PATH /home/sarkara/project002/executable/)

add_executable(server /home/sarkara/project002/src/server.cpp)

add_executable(client /home/sarkara/project002/src/client.cpp)