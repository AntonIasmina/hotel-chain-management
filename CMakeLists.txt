cmake_minimum_required(VERSION 3.22)
project(hotelmanagement_C___)

set(CMAKE_CXX_STANDARD 14)

add_executable(hotelmanagement_C___ main.cpp
        Hotel.h Hotel.cpp
        Repository.h
        Repository.cpp
        RepoFile.h RepoFile.cpp Service.h
        Service.cpp UI.h UI.cpp Date.h Date.cpp)
